#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000000

#include <windows.h>
#include "mgame.h"
#include "store.h"

void print_pokemon(int n_pokemon); //도감 그림을 불러오는 함수
char story(char *talk); //한글자씩 출력하는 함수
char textfile(char* t_str); //텍스트 파일을 출력하는 함수
int cony = 38; // 인터페이스 위치
Pokemon pk[7] = { 0 };
int b = 0, s_count = 10 , my_pk; //b : 도망갈는 변수, s_count : 스킬 진화할수있게하는 변수, my_pk 포켓몬 그림을 받아 올수 있는 변수
int cho = 0, badge=0, f_ball=0; //badge : 배지 변수 게임 끝내기, f_ball : 실패한 몬스터볼이후 특정 효과를 보기 위한 변수 

int main()
{
	ps_it = &s_it;
	system("mode con cols=110 lines=50"); //cmd창 크기 설정

	gold = 1000;//용돈 금액
	N_HP = 500, Mb =500, count=0, turn=0;//가격 및 변수초기화
	
	textfile("b.txt");//포켓몬 글자
	_sleep(2000);
	system("cls");
	textfile("c.txt");//볼

	gotoxy(0, cony);
	printf("\n--------------------------------------------------------------------------\n");
	story("원하는 스타팅 포켓몬을 정해라\n");
	while (1)
	{
		if (cho > 0)
		{
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("1.파이리 2.꼬북이 3.이상해씨 \n");
		}
		else
		{
			printf("1.파이리 2.꼬북이 3.이상해씨 \n");
		}
		cho++;
		scanf("%d", &choice);
		system("cls");
		pk_choice(choice); // 포켓몬 선택하는 함수
		if (choice == 1) //확인하는 if문
		{
			break;
		}
	}

	print_pokemon(my_pk);
	gotoxy(0, cony);
	printf("\n--------------------------------------------------------------------------\n");
	story("포켓몬도 받았으니 이제 여행을 해볼까?\n");
	story("이제 어디로 가지? \n");
	_sleep(1000);
	system("cls");

	while (1)
	{
		system("cls");
		print_pokemon(my_pk);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("1.상점 2.상록시티 \n3.센터\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("상점으로 갔습니다.\n");
			while (1)
			{
				system("cls");
				print_pokemon(my_pk);
				choice = input_store_choice(&choice); //상점 물품 구매 함수
				evolution(ps_it->SBook.Sbook); //진화 하는 함수
				if (choice == 4)
				{
					break;
				}
			}
			break;
		case 2:
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("상록시티로 출발\n");
			printf("앗! 야생 %s가 튀어나왔다\n",wild_pk[0].name);
			print_pokemon(16);
			_sleep(1000);
			system("cls");
			
			fight();//튜토리얼 구구와 대결
			
			break;
		case 3:
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			pokemon_center();

		break;
		}

		
		if (wild_pk[0].current_hp <= 0 || b==1)
		{
			system("cls");
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("상록시티 도착\n");
			_sleep(1000);

			b = 0;
			break;
		}
	}
	while (1)
	{
		system("cls");
		print_pokemon(my_pk);

		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("1. 상점 2. 훈련장 \n3. 관장 4. 센터\n5. 사냥터\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			print_pokemon(my_pk);

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("상점으로 갔습니다.\n");
			while (1)
			{
				choice = input_store_choice(&choice); //상점
				evolution(ps_it->SBook.Sbook); //진화 하는 함수
				if (choice == 4)
				{
					break;
				}
			}
			break;
		case 2:
			training();//훈련장
			break;
		case 3:
			if (badge == 0)
			{
				Gym_pk();//관장과 대결
			}
			else
			{
				printf("이미 베지를 가지고 있습니다\n");
			}
			break;
		case 4:
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			pokemon_center(); //치료 센터
			break;
		case 5:
			hunting_ground();//사냥터
			break;
		}
		if (badge != 0)
		{
			printf("시즌 1 완료\n");
			break;
		}
	}
}

int random(int *a)
{
	srand((unsigned int)time(NULL));
	int ran = (rand() % 11);
	return ran;
}

char story(char *talk)
{
	char* str = talk;
	int stl =strlen(talk);
	for (int i = 0; i < stl; i++) {
		printf("%c", str[i]);
		_sleep(50);
	}
	return 0;
}

char textfile(char * t_str)
{
	char buffer[1000] = {0};
	FILE* fp = fopen(t_str, "r");
	if (fp == NULL) return;
	fseek(fp, 0, SEEK_SET);
	fread(buffer, 1, 1000, fp); //글자
	printf("%s", buffer);
	fclose(fp); //파일 포인터 닫기

}


/*
* 
*	아이템이 0개 이면 오류가 남
* 
	해야 할 것
	1. 선택한 포켓몬이 누구인가 확인 하기
	2. 물량
	3. 경험치
	4. 레벨에 따른 데미지 스킬에 대한 데미지 랜덤적으로 사용하기
	5. 각각의 스킬에 대한 데미지

	6.포켓몬 교환
	%s 들어와 가랏! %s

	아스키코드 아트
	https://emojicombos.com/pokemon-ascii-art
	https://gist.github.com/MatheusFaria/4cbb8b6dbe33fd5605cf8b8f713ba6d

		  *       ___.-=--..-._     *                '               '
								  *       *
				*        _.'  .'       `.        '  *             *
	 *              *_.-'   .'            `.               *
				   .'                       `._             *  '
   '       '                        .       .  `.     .
	   .                      *                  `
			   *        '             '                          .
	 .                          *        .           *  *
			 *        .                                    '⠀⠀⠀⠀⠀


	내용/ 순서도 /함수명 적고 어떤 기능을 하는지 어떤 작용  /개발 일정


	if (wild_pk[a].current_hp <= 0 || b == 1)
			{
				system("cls");
				print_pokemon(my_pk);
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("사냥터에서 나왔다\n");
				_sleep(1000);
				b = 0;
			}
				//print_pokemon(my_pk);//선택한 포켓몬 그림 가져오는 함수
	//gotoxy(0, cony);
	//printf("\n--------------------------------------------------------------------------\n");
	//printf("포켓몬 이름을 변경 하실 건가요?\n");
	//printf("1. 네 2. 아니요\n");
	//scanf("%d", &choice);
	//system("cls");
	//switch (choice)//포켓몬 이름 변경 switch
	//{
	//case 1:
	//	print_pokemon(my_pk);
	//	gotoxy(0, cony);
	//	printf("\n--------------------------------------------------------------------------\n");
	//	printf("변경할 이름을 정해주세요.\n");
	//	scanf("%s", pk[0].name);
	//	printf("%s 로 변경 되었습니다.\n", pk[0].name);
	//	_sleep(1000);
	//	system("cls");
	//	break;
	//case 2:
	//	print_pokemon(my_pk);
	//	gotoxy(0, cony);
	//	printf("\n--------------------------------------------------------------------------\n");
	//	printf("%s로 진행 합니다.\n", pk[0].name);
	//	_sleep(1000);
	//	system("cls");
	//	break;
	//}

*/