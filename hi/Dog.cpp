#include "Dog.h"

void Dog::howl()
{
	printf("[%s]�� ¢���ϴ�.\n", Name.c_str());
	SetEnergy(Energy - 0.1f);
}
