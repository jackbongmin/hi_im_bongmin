#include "Monster.h"

float Monster::Attack()
{
	printf("[% s]�� �����߽��ϴ�.", Name.c_str());
	return AttackPower;
}
