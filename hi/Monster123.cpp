#include "Monster123.h"
#include "EnemyData.h"

float Monster123::Attack1()
{
	printf("[% s]가 공격했습니다.", Name.c_str());
	return AttackPower;
}

void Monster123::TakeDamage1(float Amount)
{
	Health -= Amount;
}
