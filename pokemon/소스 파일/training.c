#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mgame.h"
#include <windows.h>
#include "store.h"

void training()
{
	print_pokemon(my_pk);

	gotoxy(0, cony);
	printf("\n--------------------------------------------------------------------------\n");
	printf("�Ʒ��忡 �����߽��ϴ�.\n");
	while (1)
	{
		printf("1.%s 2.%s\n3.�Ʒ�����\n", pk[0].skill, pk[0].skill2);
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			print_pokemon(my_pk);

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s�� ���� ��ġ��\n", pk[0].name);
			printf("%d�� �������� �������ϴ�.\n", pk[0].damage);
			break;
		case 2:
			print_pokemon(my_pk);

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("������ �Ʒ��� �ϸ� ���� ��ȭ�� ��ų�� ���� �� �ֽ��ϴ�.\n");
			printf("%s�� %s\n", pk[0].name, pk[0].skill2);
			s_count--;
			if (s_count <= 0)
			{
				if (strcmp(pk[0].skill2, "�Ҳɼ���") == 0)
				{
					printf("%s���� ȭ������ ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "ȭ�����");
					pk[0].damage += 70;
					pk[0].max_hp += 70;
					s_count = 15;
					break;
				}

				else if (strcmp(pk[0].skill2, "ȭ�����") == 0 && (strcmp(pk[0].name, "���ڵ�") == 0 || strcmp(pk[0].name, "���ڸ�") == 0))
				{
					printf("%s���� �÷������̺�� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "�÷������̺�");
					s_count = 20;
					pk[0].damage += 100;
					pk[0].max_hp += 70;
					break;

				}

				else if (strcmp(pk[0].skill2, "�÷������̺�") == 0 && strcmp(pk[0].name, "���ڸ�") == 0)
				{
					printf("%s���� �ı������� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "�ı�����");
					pk[0].damage += 130;
					pk[0].max_hp += 70;
					s_count = 100;
					break;

				}

				//--------------------------
				if (strcmp(pk[0].skill2, "����ä��") == 0)
				{
					printf("%s���� 	�ٳ�������� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "	�ٳ�������");
					pk[0].damage += 70;
					pk[0].max_hp += 70;
					s_count = 15;
					break;

				}
				else if (strcmp(pk[0].skill2, "	�ٳ�������") == 0 && (strcmp(pk[0].name, "�̻���Ǯ") == 0 || strcmp(pk[0].name, "�̻��ز�") == 0))
				{
					printf("%s���� �ֶ���� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "�ֶ��");
					s_count = 20;
					pk[0].damage += 100;
					pk[0].max_hp += 70;
					break;
				}
				else if (strcmp(pk[0].skill2, "	�ֶ��") == 0 && strcmp(pk[0].name, "�̻��ز�") == 0)
				{
					printf("%s���� �ı������� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "�ı�����");
					pk[0].damage += 130;
					pk[0].max_hp += 70;
					s_count = 100;
					break;

				}

				//-------------------------------
				if (strcmp(pk[0].skill2, "������") == 0)
				{
					printf("%s���� ����Ʈ��ġ��� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "����Ʈ��ġ��");
					pk[0].damage += 70;
					pk[0].max_hp += 70;
					s_count = 15;
					break;

				}
				else if (strcmp(pk[0].skill2, "����Ʈ��ġ��") == 0 && (strcmp(pk[0].name, "��Ϻα�") == 0 || strcmp(pk[0].name, "�źϿ�") == 0))
				{
					printf("%s���� ���̵�������� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "���̵������");
					s_count = 20;
					pk[0].damage += 100;
					pk[0].max_hp += 70;
					break;

				}
				else if (strcmp(pk[0].skill2, "���̵������") == 0 && strcmp(pk[0].name, "�źϿ�") == 0)
				{
					printf("%s���� �ı������� ��ȭ �Ǿ����ϴ�.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "�ı�����");
					s_count = 100;
					pk[0].damage += 130;
					pk[0].max_hp += 70;
					break;

				}break;
			}
			break;
		case 3:
			break;
		}
		if (choice == 3)break;
	}
}