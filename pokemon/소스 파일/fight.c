#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mgame.h"
#include <windows.h>
#include "store.h"

void fight(void)
{
	
	while (1)
	{
		system("cls");
		print_pokemon(my_pk);
		int a = random(&a);
		turn = 0;
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf(" 1.싸우기 2.회복약\n 3.잡기 4.도망치기\n 5.포켓몬 교체\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("1.%s 2.%s\n", pk[0].skill, pk[0].skill2);
			scanf("%d", &choice);
			system("cls");
			switch (choice)
			{
			case 1:
				print_pokemon(my_pk);
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("%s의 %s\n", pk[0].name, pk[0].skill);
				wild_pk[0].current_hp -= 50;
				if (wild_pk[0].current_hp <= 0)
				{
					wild_pk[0].current_hp = 0;
				}
				printf("%d의 데미지를 입혔습니다.\n", pk[0].damage);
				printf("%s의 남은 체력은 %d 입니다.\n", wild_pk[0].name, wild_pk[0].current_hp);
				if (wild_pk[0].current_hp <= 0)break;

				turn++;
				break;
			case 2:
				print_pokemon(my_pk);
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("%s의 %s\n", pk[0].name, pk[0].skill2);
				wild_pk[0].current_hp -= (pk[0].damage + 20);
				if (wild_pk[0].current_hp <= 0)
				{
					wild_pk[0].current_hp = 0;
				}
				printf("%s의 남은 체력은 %d 입니다.\n", wild_pk[0].name, wild_pk[0].current_hp);
				_sleep(1000);
				if (wild_pk[0].current_hp <= 0)break;
				s_count--;

				turn++;
				break;
			}
			break;
		case 2:
			textfile("d.txt");
			if (ps_it->potion.Nomal_potion <= 0)
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("사용할 회복약이 없습니다.\n");
				printf("%d\n", ps_it->potion.Nomal_potion);
			}
			else
			{
				if (pk[0].current_hp == pk[0].max_hp)
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					printf("%s의 체력이 이미 100입니다.\n", pk[0].name);
				}
				else if (pk[0].current_hp + 60 > pk[0].max_hp)
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[0].current_hp = pk[0].max_hp;
					printf("%s의 회복되었습니다.\n", pk[0].name);
					printf("current hp : %d 입니다.\n", pk[0].current_hp);
					ps_it->potion.Nomal_potion -= 1;
					printf("%d\n", ps_it->potion.Nomal_potion);
				}
				else
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[0].current_hp += 50;
					printf("%s의 체력이 회복 되었습니다.\n", pk[0].name);
					ps_it->potion.Nomal_potion -= 1;
					printf("남은 포션 수 :%d\n", ps_it->potion.Nomal_potion);
				}
				turn++;
				break;
			}
			break;

		case 3:
			textfile("c.txt");//볼
			int x = random(a);

			if (ps_it->MBall.Mball <= 0)
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("사용할 몬스터볼이 없습니다.\n");
				_sleep(1000);

			}
			else
			{

				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("몬스터볼을 사용했다.\n");
				printf("가라 몬스터 볼~!\n");
				_sleep(1000);

				if (x > 6)//확률로 잡기 40%6
				{
					system("cls");
					textfile("c.txt");//볼
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//볼
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//볼
					_sleep(500);

					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[1] = wild_pk[0];
					printf("신난다!\n%s를 잡았다!\n", wild_pk[0].name);
					ps_it->MBall.Mball -= 1;
					printf("%d", ps_it->MBall.Mball);
					b++;
					_sleep(1000);
				}
				else
				{
					system("cls");
					textfile("c.txt");//볼
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//볼
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//볼
					_sleep(500);
					system("cls");
					print_pokemon(16);

					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");

					printf("아아!.\n");
					printf("잡았다고 생각했는데!\n");
					ps_it->MBall.Mball -= 1;
					printf("남은 몬스터 볼: %d", ps_it->MBall.Mball);
					_sleep(1000);
					f_ball++;
					turn++;
				}
			}
			break;
		case 4:
			textfile("e.txt");
			int x = random(a);
			if (x > 5) //도망 확률 50%5
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("성공적으로 도망쳤다!\n");
				b++;
			}
			else
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("도망에 실패했다.\n");
				turn++;
			}

			break;
		case 5:
		{
			for (int i = 0; i < 6;i++)
			{
				printf("%d. %s\n",i+1, pk[i].name);
			}
		}
		break;
		}

		if (b == 1)
		{
			b = 0;
			break;
		}
		//-------------------------------------- 구구
		if (turn == 1)
		{
			_sleep(1000);
			system("cls");

			if (f_ball == 0 && b==0)
			{
				textfile("a.txt");//폭죽

				_sleep(1000);
				system("cls");
				print_pokemon(16);//구구 맞는 효과
				_sleep(500);
				system("cls");
				_sleep(500);
				print_pokemon(16);
				_sleep(500);
				system("cls");
				_sleep(500);
			}

			print_pokemon(16);
			f_ball = 0;
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			int y = random(a);
			if (y > 5) // 구구 스킬 랜덤 하게 사용 하기5
			{
				printf("적의 %s가 %s!\n", wild_pk[0].name, wild_pk[0].skill);
				pk[0].current_hp -= 30;
				if (pk[0].current_hp <= 0)
				{
					pk[0].current_hp = 0;
				}
			}
			else
			{
				printf("적의 %s가 %s!\n", wild_pk[0].name, wild_pk[0].skill2);
				pk[0].current_hp -= wild_pk[0].damage;
				if (pk[0].current_hp <= 0)
				{
					pk[0].current_hp = 0;
				}
			}
			_sleep(1000);
			system("cls");

			print_pokemon(my_pk);//내포켓몬 맞는 효과
			_sleep(500);
			system("cls");
			_sleep(500);
			print_pokemon(my_pk);
			_sleep(500);
			system("cls");
			_sleep(500);
			print_pokemon(my_pk);

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s의 피가 %d남았습니다.\n", pk[0].name, pk[0].current_hp);
			_sleep(1000);

		}

		if (pk[0].current_hp <= 0)
		{
			_sleep(1000);
			system("cls");
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s는 쓰러졌다\n", pk[0].name);
			break;
		}
		if (wild_pk[0].current_hp <= 0)
		{
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("적의 %s는 쓰러졌다\n", wild_pk[0].name);
			printf("레드는 상금으로 %d원 손에 넣었다!\n", 300); //요거는 사람이랑 대결 할때 
			gold += 300;
			_sleep(1000);

			break;
		}///------------------
	}
}

/*
			

*/