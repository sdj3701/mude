#include <stdio.h>
#include "mgame.h"
#include <windows.h>
#include "store.h"

void pokemon_center()
{
	for (int i = 0; i < 6;i++)
	{
		if (pk[i].level != 0)
		{
			printf("%s\n", pk[i].name);
			pk[i].current_hp = pk[i].max_hp;
		}
		else
		{
			break;
		}
	}
	_sleep(1000);
	story("포켓몬이 회복 되었습니다.\n");
}