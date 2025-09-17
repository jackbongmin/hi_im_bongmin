#include "Actor.h"



void Actor::ApplyAttack(ICanBattle* InTarget)
{
	InTarget->TakeDamage(AttackPower);
}

void Actor::TakeDamage(float InDamage)
{
	SetHealth(Health - InDamage);

	printf("%s�� %.0f�� ���ظ� �Ծ����ϴ�.\n", Name.c_str(), InDamage);
	printf("(%.0f/%.0f)\n", Health, MaxHealth);

	if (!IsAlive())
	{
		//��� ó��
		printf("%s�� �׾����ϴ�.\n", Name.c_str());
	}
}

