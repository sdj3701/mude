#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mgame.h"
#include "store.h"

int pk_choice(int a)
{
	switch (a)
	{
	case 1:
		pk[0].pk_code = 4;
		my_pk = pk[0].pk_code;
		print_pokemon(pk[0].pk_code);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("���̸��� ���� �ϼ̽��ϴ�.\n");
		printf("������ �� ���ϸ����� �����Ͻǰǰ���?\n");
		printf("1.�� 2.�ƴϿ�\n");
		strcpy(pk[0].name, "���̸�");//����ü ���ڿ��� ������ �ּ��̱� ������ strcpy�� ����Ͼ��Ѵ�.
		pk[0].level = 1;
		pk[0].max_hp = 100;
		pk[0].current_hp = 100;
		pk[0].damage = 30;
		strcpy(pk[0].skill, "���� ��ġ��");
		strcpy(pk[0].skill2, "�Ҳɼ���");
		scanf("%d", &choice);
		system("cls");
		break;
	case 2:
		pk[0].pk_code = 7;
		my_pk = pk[0].pk_code;

		print_pokemon(my_pk);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("�����̸� ���� �ϼ̽��ϴ�.\n");
		strcpy(pk[0].name, "������");
		pk[0].level = 1;
		pk[0].max_hp = 100;
		pk[0].current_hp = 100;
		pk[0].damage = 30;
		strcpy(pk[0].skill, "���� ��ġ��");
		strcpy(pk[0].skill2, "������");
		printf("������ �� ���ϸ����� �����Ͻǰǰ���?\n");
		printf("1.�� 2.�ƴϿ�\n");
		scanf("%d", &choice);
		system("cls");
		break;
	case 3:
		pk[0].pk_code = 1;
		my_pk = pk[0].pk_code;
		print_pokemon(my_pk);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("�̻��ؾ��� ���� �ϼ̽��ϴ�.\n");
		strcpy(pk[0].name, "�̻��ؾ�");
		pk[0].level = 1;
		pk[0].max_hp = 100;
		pk[0].current_hp = 100;
		pk[0].damage = 30;
		strcpy(pk[0].skill, "���� ��ġ��");
		strcpy(pk[0].skill2, "����ä��");
		printf("������ �� ���ϸ����� �����Ͻǰǰ���?\n");
		printf("1.�� 2.�ƴϿ�\n");
		scanf("%d", &choice);
		system("cls");
		break;
	}
	return choice;
}