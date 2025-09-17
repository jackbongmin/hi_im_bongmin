#include "Dog.h"

void Dog::howl()
{
	printf("[%s]°¡ Â¢½À´Ï´Ù.\n", Name.c_str());
	SetEnergy(Energy - 0.1f);
}

void Dog::Move()
{
	printf("[%s] : ´Ş¸³´Ï´Ù.\n", Name.c_str());
	Animal::Move();
}

void Dog::MakeSound()
{
	Animal::MakeSound();
	printf("[%s] : ÄÈ¤»¾ı¾ûÄÈÄÈÄÈ\n", Name.c_str());
}
