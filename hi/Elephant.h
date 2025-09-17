#pragma once
#include "Animal.h"
#include "ICanBattle.h"

class Elephant : public Animal, public ICanBattle// Elephant�� Animal�� ��� ��ӹ޾Ҵ�.
{
public:
	void Attack1();	// �ڳ��� ���� �Լ�
	virtual void Move() override;
	virtual void MakeSound() override;

	virtual void ApplyAttack(ICanBattle* InTarget) override;
	virtual void TakeDamage(float InDamage) override;


public:
	// ������, �Ҹ��ڴ� ����� ����� �ƴϴ�.
	Elephant() = default;
	Elephant(std::string InName)
		: Animal(InName)			// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}

	virtual ~Elephant() {}

	float AttackPower = 10.0f;

};

