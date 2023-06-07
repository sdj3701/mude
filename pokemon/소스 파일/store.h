#pragma once

typedef struct potion
{
	int Nomal_potion;
	int potion1;
	int potion2;
}Potion;

typedef struct ball
{
	int Mball;
}Ball;

typedef struct skill
{
	int Sbook;
}Skill;

typedef struct item
{
	Potion potion;
	Ball MBall;
	Skill SBook;
}Item;

Potion potion;

Item s_it;
Item* ps_it;

int my_pk, cony, s_count,res,b, badge,f_ball;

