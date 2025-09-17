#pragma once

class ICanBattle
{
public:
	virtual ~ICanBattle() {};

	virtual void ApplyAttack(ICanBattle* InTarget) = 0;
	virtual void TakeDamage(float InDamage) = 0;

	// �ɹ� ������ �� �ʿ��� ���. Getter�� �ִٴ°��� ���
	//virtual void GetAttackPower() = 0;
};