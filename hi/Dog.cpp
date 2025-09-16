#include "Dog.h"

void Dog::howl()
{
	printf("[%s]°¡ Â¢½À´Ï´Ù.\n", Name.c_str());
	SetEnergy(Energy - 0.1f);
}
