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
	printf("훈련장에 도착했습니다.\n");
	while (1)
	{
		printf("1.%s 2.%s\n3.훈련종료\n", pk[0].skill, pk[0].skill2);
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			print_pokemon(my_pk);

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("%s의 몸통 박치기\n", pk[0].name);
			printf("%d의 데미지를 입혔습니다.\n", pk[0].damage);
			break;
		case 2:
			print_pokemon(my_pk);

			gotoxy(0, cony);
			printf("\n--------------------------------------------------------------------------\n");
			printf("열심히 훈련을 하면 더욱 강화된 스킬을 얻을 수 있습니다.\n");
			printf("%s의 %s\n", pk[0].name, pk[0].skill2);
			s_count--;
			if (s_count <= 0)
			{
				if (strcmp(pk[0].skill2, "불꽃세례") == 0)
				{
					printf("%s에서 화염방사로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "화염방사");
					pk[0].damage += 70;
					pk[0].max_hp += 70;
					s_count = 15;
					break;
				}

				else if (strcmp(pk[0].skill2, "화염방사") == 0 && (strcmp(pk[0].name, "리자드") == 0 || strcmp(pk[0].name, "리자몽") == 0))
				{
					printf("%s에서 플레어드라이브로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "플레어드라이브");
					s_count = 20;
					pk[0].damage += 100;
					pk[0].max_hp += 70;
					break;

				}

				else if (strcmp(pk[0].skill2, "플레어드라이브") == 0 && strcmp(pk[0].name, "리자몽") == 0)
				{
					printf("%s에서 파괴광선로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "파괴광선");
					pk[0].damage += 130;
					pk[0].max_hp += 70;
					s_count = 100;
					break;

				}

				//--------------------------
				if (strcmp(pk[0].skill2, "덩굴채찍") == 0)
				{
					printf("%s에서 	잎날가르기로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "	잎날가르기");
					pk[0].damage += 70;
					pk[0].max_hp += 70;
					s_count = 15;
					break;

				}
				else if (strcmp(pk[0].skill2, "	잎날가르기") == 0 && (strcmp(pk[0].name, "이상해풀") == 0 || strcmp(pk[0].name, "이상해꽃") == 0))
				{
					printf("%s에서 솔라빔로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "솔라빔");
					s_count = 20;
					pk[0].damage += 100;
					pk[0].max_hp += 70;
					break;
				}
				else if (strcmp(pk[0].skill2, "	솔라빔") == 0 && strcmp(pk[0].name, "이상해꽃") == 0)
				{
					printf("%s에서 파괴광선로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "파괴광선");
					pk[0].damage += 130;
					pk[0].max_hp += 70;
					s_count = 100;
					break;

				}

				//-------------------------------
				if (strcmp(pk[0].skill2, "물대포") == 0)
				{
					printf("%s에서 로케트박치기로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "로케트박치기");
					pk[0].damage += 70;
					pk[0].max_hp += 70;
					s_count = 15;
					break;

				}
				else if (strcmp(pk[0].skill2, "로케트박치기") == 0 && (strcmp(pk[0].name, "어니부기") == 0 || strcmp(pk[0].name, "거북왕") == 0))
				{
					printf("%s에서 하이드로펌프로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "하이드로펌프");
					s_count = 20;
					pk[0].damage += 100;
					pk[0].max_hp += 70;
					break;

				}
				else if (strcmp(pk[0].skill2, "하이드로펌프") == 0 && strcmp(pk[0].name, "거북왕") == 0)
				{
					printf("%s에서 파괴광선로 강화 되었습니다.\n", pk[0].skill2);
					strcpy(pk[0].skill2, "파괴광선");
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