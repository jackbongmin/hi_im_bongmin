#include "Elephant.h"

void Elephant::Attack1()
{
	printf("[%s] : 공격합니다.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
}

void Elephant::Move()
{
	printf("[%s] : 포효합니다.\n", Name.c_str());
	//Animal::Move();
	if (Energy < 0.1f)
	{
		printf("[%s] : 힘이 없어서 움직일 수 없습니다.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : 움직입니다.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : 에너지가 10% 감소합니다.\n", Name.c_str());
	}
}

void Elephant::MakeSound()
{
	Animal::MakeSound();
	printf("[%s] : 뿌ㅜ우우ㅜ우ㅜㅇ\n", Name.c_str());
}

void Elephant::Attack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

void Elephant::TakeDamage(float InDamage)
{
	printf("[%.0f]의 피해를 입었다.", InDamage);
}
