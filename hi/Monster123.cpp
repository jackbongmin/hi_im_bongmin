#include "Monster123.h"
#include "EnemyData.h"

float Monster123::Attack1()
{
	printf("[% s]�� �����߽��ϴ�.", Name.c_str());
	return AttackPower;
}

void Monster123::TakeDamage1(float Amount)
{
	Health -= Amount;
}
