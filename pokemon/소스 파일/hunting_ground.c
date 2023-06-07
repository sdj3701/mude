#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mgame.h"
#include <windows.h>
#include "store.h"

void hunting_ground()
{
	gotoxy(0, cony);
	int a = random(&a);
	wild_pk[a].current_hp = wild_pk[a].max_hp;//hp 초기화
	printf("\n--------------------------------------------------------------------------\n");
	printf("사냥터로 출발\n");
	printf("앗! 야생 %s가 튀어나왔다\n", wild_pk[a].name);
	print_pokemon(wild_pk[a].pk_code);
	_sleep(1000);
	system("cls");
	while (1)
	{
		system("cls");
		print_pokemon(my_pk);
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
				wild_pk[a].current_hp -= 30;
				if (wild_pk[a].current_hp <= 0)
				{
					wild_pk[a].current_hp = 0;
				}
				printf("%d의 데미지를 입혔습니다.\n", pk[0].damage);
				printf("%s의 남은 체력은 %d 입니다.\n", wild_pk[a].name, wild_pk[a].current_hp);
				if (wild_pk[a].current_hp <= 0)break;

				turn++;
				break;
			case 2:
				print_pokemon(my_pk);
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("%s의 %s\n", pk[0].name, pk[0].skill2);
				wild_pk[a].current_hp -= (pk[0].damage + 20);
				if (wild_pk[a].current_hp <= 0)
				{
					wild_pk[a].current_hp = 0;
				}
				printf("%s의 남은 체력은 %d 입니다.\n", wild_pk[a].name, wild_pk[a].current_hp);
				_sleep(1000);
				if (wild_pk[a].current_hp <= 0)break;
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
					printf("남은 포션 수 :%d\n", ps_it->potion.Nomal_potion);
				}
				else
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[0].current_hp += 50;
					printf("%s의 체력이 회복 되었습니다.\n", pk[0].name);
					ps_it->potion.Nomal_potion -= 1;
					printf("%d\n", ps_it->potion.Nomal_potion);
				}
				turn++;
				break;
			}
			break;

		case 3:
			textfile("c.txt");//볼
			if (ps_it->MBall.Mball <= 0)
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("사용할 몬스터볼이 없습니다.\n");
				_sleep(1000);

			}
			else
			{
				int x = random(a);
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("몬스터볼을 사용했다.\n");
				printf("가라 몬스터 볼~!\n");
				_sleep(1000);

				if (x > 6)//확률로 잡기 40%6
				{
					for (int i = 0;i < 6;i++)
					{
						if (pk[i].level == 0)
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

							gotoxy(0, cony);
							printf("\n--------------------------------------------------------------------------\n");
							pk[i] = wild_pk[a];
							printf("신난다!\n%s를 잡았다!\n", wild_pk[a].name);
							break;
						}
					}
					ps_it->MBall.Mball -= 1;
					printf("%d\n", ps_it->MBall.Mball);
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
					print_pokemon(wild_pk[a].pk_code);

					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					printf("아아!.\n");
					printf("잡았다고 생각했는데!\n");
					ps_it->MBall.Mball -= 1;
					printf("남은 몬스터 볼: %d\n", ps_it->MBall.Mball);
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
				b = 1;
			}
			else
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("도망에 실패했다.\n");
				turn++;
			}

			break;
		case 5: // 포켓몬 바꾸기
		
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
			if (pk[choice-1].name != '\0')
			{
				pk[7] = pk[0];
				pk[0] = pk[choice-1];
				pk[choice-1] = pk[7];
				printf("%s 들어와!\n 나와라 %s!\n", pk[choice-1].name, pk[0].name);
				my_pk = pk[0].pk_code;
				_sleep(1000);
			}
			else
			{
				break;
			}
			break;
		}

		if (b == 1)
		{
			b = 0;
			break;
		}

		if (turn == 1)
		{
			_sleep(1000);
			system("cls");
			if (f_ball == 0 && b == 1)
			{
				
				textfile("a.txt");//폭죽

				_sleep(1000);
				system("cls");

				print_pokemon(wild_pk[a].pk_code);
				_sleep(500);
				system("cls");
				_sleep(500);
				print_pokemon(wild_pk[a].pk_code);
				_sleep(500);
				system("cls");
				_sleep(500);
			}
			print_pokemon(wild_pk[a].pk_code);
			f_ball = 0;

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			int y = random(a);
			if (y > 5) 
			{
				printf("적의 %s가 %s!\n", wild_pk[a].name, wild_pk[a].skill);
				_sleep(1000);

				pk[0].current_hp -= 20;
				if (pk[0].current_hp <= 0)
				{
					pk[0].current_hp = 0;
				}
			}
			else
			{
				printf("적의 %s가 %s!\n", wild_pk[a].name, wild_pk[a].skill2);
				_sleep(1000);

				pk[0].current_hp -= (wild_pk[a].damage + 20);
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
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s는 쓰러졌다\n", pk[0].name);

			_sleep(1000);
			break;
		}
		if (wild_pk[a].current_hp <= 0)
		{
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("적의 %s는 쓰러졌다\n", wild_pk[a].name);
			printf("레드는 돈 %d원 손에 넣었다!\n", 300); 
			gold += 300;
			_sleep(1000);
			wild_pk[a].current_hp = wild_pk[a].max_hp;

			break;
		}
	}
}