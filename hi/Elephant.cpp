#include "Elephant.h"

void Elephant::Attack1()
{
	printf("[%s]�� �����մϴ�.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
}
