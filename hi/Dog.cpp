#include "Dog.h"

void Dog::howl()
{
	printf("[%s]�� ¢���ϴ�.\n", Name.c_str());
	SetEnergy(Energy - 0.1f);
}

void Dog::Move()
{
	printf("[%s] : �޸��ϴ�.\n", Name.c_str());
	Animal::Move();
}

void Dog::MakeSound()
{
	Animal::MakeSound();
	printf("[%s] : �Ȥ�����������\n", Name.c_str());
}
