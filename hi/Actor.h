#pragma once
#include<string>
#include "ICanBattle.h"


class Actor:public ICanBattle
{
public:
	Actor() = default;
	Actor(const char* InName, float InHealth, float InAttackPower)
		: Name(InName), Health(InHealth),MaxHealth(InHealth), AttackPower(InAttackPower)
	{
	}

	virtual void ApplyAttack(ICanBattle* InTarget) override;
	virtual void TakeDamage(float InDamage) override;


	/// <summary>
	/// �� Actor�� ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ����ִ�. false�� �׾���.</returns>
	inline bool IsAlive() { return Health > 0; }

	const float GetHealth() const { return Health; }
	const float GetMaxHealth() const { return MaxHealth; }
	const float GetAttackPower() const { return AttackPower; }

protected:
	inline void SetHealth(float InHealth)
	{
		if (InHealth > MaxHealth)
		{
			Health = MaxHealth;
		}
		else
		{
			Health = InHealth;
		}
	}

	std::string Name= "����";
	float Health = 100.0f;
	float MaxHealth = 100.0f;
	float AttackPower = 10.0f;
	
};

