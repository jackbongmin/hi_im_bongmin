#include "Elephant.h"

void Elephant::Attack1()
{
	printf("[%s] : �����մϴ�.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
}

void Elephant::Move()
{
	printf("[%s] : ��ȿ�մϴ�.\n", Name.c_str());
	//Animal::Move();
	if (Energy < 0.1f)
	{
		printf("[%s] : ���� ��� ������ �� �����ϴ�.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : �����Դϴ�.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : �������� 10% �����մϴ�.\n", Name.c_str());
	}
}

void Elephant::MakeSound()
{
	Animal::MakeSound();
	printf("[%s] : �Ѥ̿��̿�̤�\n", Name.c_str());
}

void Elephant::Attack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

void Elephant::TakeDamage(float InDamage)
{
	printf("[%.0f]�� ���ظ� �Ծ���.", InDamage);
}
