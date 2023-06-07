#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mgame.h"
#include <windows.h>
#include "store.h"

void Gym_pk()
{
	print_pokemon(my_pk);

	gotoxy(0, cony);
	printf("\n--------------------------------------------------------------------------\n");
	story("상록시티 관장 이슬이와 대결!\n");
	story("선공은 받아주도록 하지!\n");
	_sleep(1000);
	while (1)
	{
		turn = 0;
		int a = random(&a);
		system("cls");
		print_pokemon(my_pk);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("1.싸우기 2.회복약\n3.포켓몬교체 4.도망치다\n");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("1.%s 2.%s\n", pk[0].skill, pk[0].skill2);
			scanf("%d", &choice);
			system("cls");
			switch (choice)
			{
			case 1:
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("%s의 %s\n", pk[0].name, pk[0].skill);
				Gym_Leader_pk[0].current_hp -= 30;
				if (Gym_Leader_pk[0].current_hp <= 0)
				{
					Gym_Leader_pk[0].current_hp = 0;
				}
				printf("%d의 데미지를 입혔습니다.\n", 50);
				printf("%s의 남은 체력은 %d 입니다.\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].current_hp);
				_sleep(1000);
				if (Gym_Leader_pk[0].current_hp <= 0)break;

				turn++;
				break;
			case 2:
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("%s의 %s\n", pk[0].name, pk[0].skill2);
				Gym_Leader_pk[0].current_hp -= (pk[0].damage + 20);
				if (Gym_Leader_pk[0].current_hp <= 0)
				{
					Gym_Leader_pk[0].current_hp = 0;
				}
				printf("%s의 남은 체력은 %d 입니다.\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].current_hp);
				_sleep(1000);
				if (Gym_Leader_pk[0].current_hp <= 0)break;
				s_count--;

				turn++;
				break;
			}
			break;
		case 2:
			textfile("d.txt");//회복
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
					(*ps_it).potion.Nomal_potion -= 1;
					printf("남은 포션 수 :%d\n", ps_it->potion.Nomal_potion);
				}
				else
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[0].current_hp += 50;
					printf("%s의 체력이 회복 되었습니다.\n", pk[0].name);
					(*ps_it).potion.Nomal_potion -= 1;
					printf("%d\n", ps_it->potion.Nomal_potion);
				}
				turn++;
				break;
			}
			break;
		case 3:
			textfile("c.txt");//볼
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("포켓몬 바꾸기 교체!\n"); // pk[0]번이 무조건 싸우는애
			for (int i = 0; i < 6; i++)
			{
				if (pk[i].level != 0)
				{
					printf("%d. %s\n", i + 1, pk[i].name);
				}
				else
				{
					break;
				}
				
			}
			scanf("%d", &choice);
			if (pk[choice - 1].name != '\0')
			{
				pk[7] = pk[0];
				pk[0] = pk[choice - 1];
				pk[choice - 1] = pk[7];
				printf("%s 들어와!\n 나와라 %s!\n", pk[choice - 1].name, pk[0].name);
				my_pk = pk[0].pk_code;
				_sleep(1000);
			}
			else
			{
				break;
			}

			break;
		case 4:
			textfile("e.txt");//runner
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("포기했는가?\n");
			printf("역시 체육관 트레이너는 강하다!\n");
			printf("다음에 다시 도전하겠습니다.\n");
			break;
		}
		if (choice == 4)//도망가면 다시 풀피
		{

			Gym_Leader_pk[0].current_hp = Gym_Leader_pk[0].max_hp;
			Gym_Leader_pk[1].current_hp = Gym_Leader_pk[1].max_hp;
			break;
		}

		if (turn == 1)
		{
			_sleep(1000);
			system("cls");
			textfile("a.txt");//폭죽

			_sleep(1000);
			if (count == 0)
			{
				system("cls");
				print_pokemon(Gym_Leader_pk[0].pk_code);
			}
			else
			{
				system("cls");
				print_pokemon(Gym_Leader_pk[1].pk_code);
			}
			_sleep(1000);
			system("cls");

			print_pokemon(Gym_Leader_pk[0].pk_code);
			_sleep(500);
			system("cls");
			_sleep(500);
			print_pokemon(Gym_Leader_pk[0].pk_code);
			_sleep(500);
			system("cls");
			_sleep(500);
			print_pokemon(Gym_Leader_pk[0].pk_code);

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			int x = random(a);
			if (x > 5)//랜덤 스킬 사용
			{
				printf("적의 %s가 %s!\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].skill);
				pk[0].current_hp -= 30;
				if (pk[0].current_hp <= 0)
				{
					pk[0].current_hp = 0;
				}
			}
			else
			{
				printf("적의 %s가 %s!\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].skill2);
				pk[0].current_hp -= Gym_Leader_pk[0].damage;
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
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s는 쓰러졌다\n", pk[0].name);
			Gym_Leader_pk[0].current_hp = Gym_Leader_pk[0].max_hp;//져도 다시 풀피
			Gym_Leader_pk[1].current_hp = Gym_Leader_pk[1].max_hp;

			break;
		}

		if (Gym_Leader_pk[0].current_hp <= 0 && count <= 0)
		{
			gotoxy(0, 0);
			textfile("a.txt");//폭죽
			_sleep(1000);
			system("cls");

			gotoxy(0, 0);
			textfile("c.txt");//볼
			_sleep(1000);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");

			printf("적의 %s는 쓰러졌다\n", Gym_Leader_pk[0].name);
			printf("이슬이는 %s 집어 넣고 다른 포켓몬은 꺼냈다.\n", Gym_Leader_pk[0].name);
			Gym_Leader_pk[2] = Gym_Leader_pk[0];
			Gym_Leader_pk[0] = Gym_Leader_pk[1];
			Gym_Leader_pk[1] = Gym_Leader_pk[2];

			printf("나와라! %s\n", Gym_Leader_pk[0].name);
			_sleep(1000);
			system("cls");
			count++;
		}
		else if (Gym_Leader_pk[0].current_hp <= 0 && count >= 1)
		{
			badge++;
			story("이슬이 : 아앗! 져버렸다.\n");
			story("상록시티 배지는 이제 너꺼야.\n");
			story("배지는 이제 넌 내꺼야.\n");
			story("레드는 상금 1000원과 배지를 손에 넣었다!\n"); //요거는 사람이랑 대결 할때
			gold += 1000;

			break;
		}

	}
}
