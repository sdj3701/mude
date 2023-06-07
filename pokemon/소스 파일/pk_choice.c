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
		printf("파이리를 선택 하셨습니다.\n");
		printf("정말로 이 포켓몬으로 선택하실건가요?\n");
		printf("1.예 2.아니요\n");
		strcpy(pk[0].name, "파이리");//구조체 문자열은 포인터 주소이기 때문에 strcpy를 사용하야한다.
		pk[0].level = 1;
		pk[0].max_hp = 100;
		pk[0].current_hp = 100;
		pk[0].damage = 30;
		strcpy(pk[0].skill, "몸통 박치기");
		strcpy(pk[0].skill2, "불꽃세례");
		scanf("%d", &choice);
		system("cls");
		break;
	case 2:
		pk[0].pk_code = 7;
		my_pk = pk[0].pk_code;

		print_pokemon(my_pk);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("꼬북이를 선택 하셨습니다.\n");
		strcpy(pk[0].name, "꼬북이");
		pk[0].level = 1;
		pk[0].max_hp = 100;
		pk[0].current_hp = 100;
		pk[0].damage = 30;
		strcpy(pk[0].skill, "몸통 박치기");
		strcpy(pk[0].skill2, "물대포");
		printf("정말로 이 포켓몬으로 선택하실건가요?\n");
		printf("1.예 2.아니요\n");
		scanf("%d", &choice);
		system("cls");
		break;
	case 3:
		pk[0].pk_code = 1;
		my_pk = pk[0].pk_code;
		print_pokemon(my_pk);
		gotoxy(0, cony);
		printf("\n--------------------------------------------------------------------------\n");
		printf("이상해씨를 선택 하셨습니다.\n");
		strcpy(pk[0].name, "이상해씨");
		pk[0].level = 1;
		pk[0].max_hp = 100;
		pk[0].current_hp = 100;
		pk[0].damage = 30;
		strcpy(pk[0].skill, "몸통 박치기");
		strcpy(pk[0].skill2, "덩굴채찍");
		printf("정말로 이 포켓몬으로 선택하실건가요?\n");
		printf("1.예 2.아니요\n");
		scanf("%d", &choice);
		system("cls");
		break;
	}
	return choice;
}