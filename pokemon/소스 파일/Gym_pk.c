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
	story("��Ͻ�Ƽ ���� �̽��̿� ���!\n");
	story("������ �޾��ֵ��� ����!\n");
	_sleep(1000);
	while (1)
	{
		turn = 0;
		int a = random(&a);
		system("cls");
		print_pokemon(my_pk);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("1.�ο�� 2.ȸ����\n3.���ϸ�ü 4.����ġ��\n");
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
				printf("%s�� %s\n", pk[0].name, pk[0].skill);
				Gym_Leader_pk[0].current_hp -= 30;
				if (Gym_Leader_pk[0].current_hp <= 0)
				{
					Gym_Leader_pk[0].current_hp = 0;
				}
				printf("%d�� �������� �������ϴ�.\n", 50);
				printf("%s�� ���� ü���� %d �Դϴ�.\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].current_hp);
				_sleep(1000);
				if (Gym_Leader_pk[0].current_hp <= 0)break;

				turn++;
				break;
			case 2:
				gotoxy(0, cony);
				printf("\n--------------------------------------------------------------------------\n");
				printf("%s�� %s\n", pk[0].name, pk[0].skill2);
				Gym_Leader_pk[0].current_hp -= (pk[0].damage + 20);
				if (Gym_Leader_pk[0].current_hp <= 0)
				{
					Gym_Leader_pk[0].current_hp = 0;
				}
				printf("%s�� ���� ü���� %d �Դϴ�.\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].current_hp);
				_sleep(1000);
				if (Gym_Leader_pk[0].current_hp <= 0)break;
				s_count--;

				turn++;
				break;
			}
			break;
		case 2:
			textfile("d.txt");//ȸ��
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
					(*ps_it).potion.Nomal_potion -= 1;
					printf("���� ���� �� :%d\n", ps_it->potion.Nomal_potion);
				}
				else
				{
					gotoxy(0, cony);
					printf("\n--------------------------------------------------------------------------\n");
					pk[0].current_hp += 50;
					printf("%s�� ü���� ȸ�� �Ǿ����ϴ�.\n", pk[0].name);
					(*ps_it).potion.Nomal_potion -= 1;
					printf("%d\n", ps_it->potion.Nomal_potion);
				}
				turn++;
				break;
			}
			break;
		case 3:
			textfile("c.txt");//��
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("���ϸ� �ٲٱ� ��ü!\n"); // pk[0]���� ������ �ο�¾�
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
				printf("%s ����!\n ���Ͷ� %s!\n", pk[choice - 1].name, pk[0].name);
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
			printf("�����ߴ°�?\n");
			printf("���� ü���� Ʈ���̳ʴ� ���ϴ�!\n");
			printf("������ �ٽ� �����ϰڽ��ϴ�.\n");
			break;
		}
		if (choice == 4)//�������� �ٽ� Ǯ��
		{

			Gym_Leader_pk[0].current_hp = Gym_Leader_pk[0].max_hp;
			Gym_Leader_pk[1].current_hp = Gym_Leader_pk[1].max_hp;
			break;
		}

		if (turn == 1)
		{
			_sleep(1000);
			system("cls");
			textfile("a.txt");//����

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
			if (x > 5)//���� ��ų ���
			{
				printf("���� %s�� %s!\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].skill);
				pk[0].current_hp -= 30;
				if (pk[0].current_hp <= 0)
				{
					pk[0].current_hp = 0;
				}
			}
			else
			{
				printf("���� %s�� %s!\n", Gym_Leader_pk[0].name, Gym_Leader_pk[0].skill2);
				pk[0].current_hp -= Gym_Leader_pk[0].damage;
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
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s�� ��������\n", pk[0].name);
			Gym_Leader_pk[0].current_hp = Gym_Leader_pk[0].max_hp;//���� �ٽ� Ǯ��
			Gym_Leader_pk[1].current_hp = Gym_Leader_pk[1].max_hp;

			break;
		}

		if (Gym_Leader_pk[0].current_hp <= 0 && count <= 0)
		{
			gotoxy(0, 0);
			textfile("a.txt");//����
			_sleep(1000);
			system("cls");

			gotoxy(0, 0);
			textfile("c.txt");//��
			_sleep(1000);
			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");

			printf("���� %s�� ��������\n", Gym_Leader_pk[0].name);
			printf("�̽��̴� %s ���� �ְ� �ٸ� ���ϸ��� ���´�.\n", Gym_Leader_pk[0].name);
			Gym_Leader_pk[2] = Gym_Leader_pk[0];
			Gym_Leader_pk[0] = Gym_Leader_pk[1];
			Gym_Leader_pk[1] = Gym_Leader_pk[2];

			printf("���Ͷ�! %s\n", Gym_Leader_pk[0].name);
			_sleep(1000);
			system("cls");
			count++;
		}
		else if (Gym_Leader_pk[0].current_hp <= 0 && count >= 1)
		{
			badge++;
			story("�̽��� : �ƾ�! �����ȴ�.\n");
			story("��Ͻ�Ƽ ������ ���� �ʲ���.\n");
			story("������ ���� �� ������.\n");
			story("����� ��� 1000���� ������ �տ� �־���!\n"); //��Ŵ� ����̶� ��� �Ҷ�
			gold += 1000;

			break;
		}

	}
}
