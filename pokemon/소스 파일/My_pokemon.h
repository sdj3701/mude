#pragma once
typedef struct pokemon
{
	char name[20];
	int level;
	int max_hp;
	int current_hp;
	int damage;
	char skill[100];
	char skill2[100];
	int pk_code;
}Pokemon;

Pokemon pk[7];

Pokemon wild_pk[10];

Pokemon Gym_Leader_pk[6];