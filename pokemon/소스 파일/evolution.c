#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mgame.h"
#include "store.h"


int evolution(int a)
{
	if (a == 1)
	{
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		for (int i = 0; i < 6; i++)
		{
			if (strcmp(pk[i].name, "���̸�") == 0)
			{
				printf("���̸����� ��� �߽��ϴ�\n");
				strcpy(pk[i].name, "���ڵ�");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "�̻��ؾ�") == 0)
			{
				printf("�̻��ؾ����� ��� �߽��ϴ�\n");
				strcpy(pk[i].name, "�̻���Ǯ");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "������") == 0)
			{
				printf("���������� ��� �߽��ϴ�\n");
				strcpy(pk[i].name, "��Ϻα�");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "���ڵ�") == 0)//���ڵ�
			{
				printf("���ڵ����� ��� �߽��ϴ�\n");
				strcpy(pk[i].name, "���ڸ�");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "�̻���Ǯ") == 0)
			{
				printf("�̻���Ǯ���� ��� �߽��ϴ�\n");
				strcpy(pk[i].name, "�̻��ز�");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "��Ϻα�") == 0)
			{
				printf("��Ϻα����� ��� �߽��ϴ�\n");
				strcpy(pk[i].name, "�źϿ�");
				_sleep(1000);
				system("cls");
				break;
				my_pk += 1;
				pk[i].pk_code = my_pk;
			}
		}
		ps_it->SBook.Sbook -= 1;
		print_pokemon(my_pk);
	}	
}