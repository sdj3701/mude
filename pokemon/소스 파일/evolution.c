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
			if (strcmp(pk[i].name, "파이리") == 0)
			{
				printf("파이리한테 사용 했습니다\n");
				strcpy(pk[i].name, "리자드");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "이상해씨") == 0)
			{
				printf("이상해씨한테 사용 했습니다\n");
				strcpy(pk[i].name, "이상해풀");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "꼬북이") == 0)
			{
				printf("꼬북이한테 사용 했습니다\n");
				strcpy(pk[i].name, "어니부기");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "리자드") == 0)//리자드
			{
				printf("리자드한테 사용 했습니다\n");
				strcpy(pk[i].name, "리자몽");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "이상해풀") == 0)
			{
				printf("이상해풀한테 사용 했습니다\n");
				strcpy(pk[i].name, "이상해꽃");
				_sleep(1000);
				system("cls");
				my_pk += 1;
				pk[i].pk_code = my_pk;
				break;
			}
			if (strcmp(pk[i].name, "어니부기") == 0)
			{
				printf("어니부기한테 사용 했습니다\n");
				strcpy(pk[i].name, "거북왕");
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