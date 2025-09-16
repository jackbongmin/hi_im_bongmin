#include "Elephant.h"

void Elephant::Attack1()
{
	printf("[%s]가 공격합니다.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
}
