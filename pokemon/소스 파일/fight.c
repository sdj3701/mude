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
		printf(" 1.�ο�� 2.ȸ����\n 3.��� 4.����ġ��\n 5.���ϸ� ��ü\n");
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
				printf("%s�� %s\n", pk[0].name, pk[0].skill);
				wild_pk[0].current_hp -= 50;
				if (wild_pk[0].current_hp <= 0)
				{
					wild_pk[0].current_hp = 0;
				}
				printf("%d�� �������� �������ϴ�.\n", pk[0].damage);
				printf("%s�� ���� ü���� %d �Դϴ�.\n", wild_pk[0].name, wild_pk[0].current_hp);
				if (wild_pk[0].current_hp <= 0)break;

				turn++;
				break;
			case 2:
				print_pokemon(my_pk);
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("%s�� %s\n", pk[0].name, pk[0].skill2);
				wild_pk[0].current_hp -= (pk[0].damage + 20);
				if (wild_pk[0].current_hp <= 0)
				{
					wild_pk[0].current_hp = 0;
				}
				printf("%s�� ���� ü���� %d �Դϴ�.\n", wild_pk[0].name, wild_pk[0].current_hp);
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
				printf("����� ȸ������ �����ϴ�.\n");
				printf("%d\n", ps_it->potion.Nomal_potion);
			}
			else
			{
				if (pk[0].current_hp == pk[0].max_hp)
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					printf("%s�� ü���� �̹� 100�Դϴ�.\n", pk[0].name);
				}
				else if (pk[0].current_hp + 60 > pk[0].max_hp)
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[0].current_hp = pk[0].max_hp;
					printf("%s�� ȸ���Ǿ����ϴ�.\n", pk[0].name);
					printf("current hp : %d �Դϴ�.\n", pk[0].current_hp);
					ps_it->potion.Nomal_potion -= 1;
					printf("%d\n", ps_it->potion.Nomal_potion);
				}
				else
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[0].current_hp += 50;
					printf("%s�� ü���� ȸ�� �Ǿ����ϴ�.\n", pk[0].name);
					ps_it->potion.Nomal_potion -= 1;
					printf("���� ���� �� :%d\n", ps_it->potion.Nomal_potion);
				}
				turn++;
				break;
			}
			break;

		case 3:
			textfile("c.txt");//��
			int x = random(a);

			if (ps_it->MBall.Mball <= 0)
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("����� ���ͺ��� �����ϴ�.\n");
				_sleep(1000);

			}
			else
			{

				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("���ͺ��� ����ߴ�.\n");
				printf("���� ���� ��~!\n");
				_sleep(1000);

				if (x > 6)//Ȯ���� ��� 40%6
				{
					system("cls");
					textfile("c.txt");//��
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//��
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//��
					_sleep(500);

					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[1] = wild_pk[0];
					printf("�ų���!\n%s�� ��Ҵ�!\n", wild_pk[0].name);
					ps_it->MBall.Mball -= 1;
					printf("%d", ps_it->MBall.Mball);
					b++;
					_sleep(1000);
				}
				else
				{
					system("cls");
					textfile("c.txt");//��
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//��
					_sleep(500);
					system("cls");
					_sleep(500);
					textfile("c.txt");//��
					_sleep(500);
					system("cls");
					print_pokemon(16);

					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");

					printf("�ƾ�!.\n");
					printf("��Ҵٰ� �����ߴµ�!\n");
					ps_it->MBall.Mball -= 1;
					printf("���� ���� ��: %d", ps_it->MBall.Mball);
					_sleep(1000);
					f_ball++;
					turn++;
				}
			}
			break;
		case 4:
			textfile("e.txt");
			int x = random(a);
			if (x > 5) //���� Ȯ�� 50%5
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("���������� �����ƴ�!\n");
				b++;
			}
			else
			{
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("������ �����ߴ�.\n");
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
		//-------------------------------------- ����
		if (turn == 1)
		{
			_sleep(1000);
			system("cls");

			if (f_ball == 0 && b==0)
			{
				textfile("a.txt");//����

				_sleep(1000);
				system("cls");
				print_pokemon(16);//���� �´� ȿ��
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
			if (y > 5) // ���� ��ų ���� �ϰ� ��� �ϱ�5
			{
				printf("���� %s�� %s!\n", wild_pk[0].name, wild_pk[0].skill);
				pk[0].current_hp -= 30;
				if (pk[0].current_hp <= 0)
				{
					pk[0].current_hp = 0;
				}
			}
			else
			{
				printf("���� %s�� %s!\n", wild_pk[0].name, wild_pk[0].skill2);
				pk[0].current_hp -= wild_pk[0].damage;
				if (pk[0].current_hp <= 0)
				{
					pk[0].current_hp = 0;
				}
			}
			_sleep(1000);
			system("cls");

			print_pokemon(my_pk);//�����ϸ� �´� ȿ��
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
			printf("%s�� �ǰ� %d���ҽ��ϴ�.\n", pk[0].name, pk[0].current_hp);
			_sleep(1000);

		}

		if (pk[0].current_hp <= 0)
		{
			_sleep(1000);
			system("cls");
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s�� ��������\n", pk[0].name);
			break;
		}
		if (wild_pk[0].current_hp <= 0)
		{
			print_pokemon(my_pk);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("���� %s�� ��������\n", wild_pk[0].name);
			printf("����� ������� %d�� �տ� �־���!\n", 300); //��Ŵ� ����̶� ��� �Ҷ� 
			gold += 300;
			_sleep(1000);

			break;
		}///------------------
	}
}

/*
			

*/