#include "Monster.h"

float Monster::Attack()
{
	printf("[% s]가 공격했습니다.", Name.c_str());
	return AttackPower;
}
