#pragma once
#include<string>
#include "Actor.h"

class Monster123 : public Actor
{
public:
	inline const std::string& GetName() const { return Name; }
	inline const float GetHealth() const { return Health; }
	inline const float GetAttackPower() const { return AttackPower; }
	inline const int GetDropGold() const { return DropGold; }

	Monster123(std::string InName)
		: Name(InName)
	{
	}

	float Attack1();

	void  TakeDamage1(float Amount);

	Monster123(float Modifier = 1.0f)
	{
		float randomFactor = 0.9f + ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.2f);
		Health = Health * Modifier * randomFactor;
		AttackPower = AttackPower * Modifier * randomFactor;
		DropGold = static_cast<int>(DropGold * Modifier * randomFactor);
	}

protected:
	std::string Name;
	float Health = 50.0f;
	float AttackPower = 5.0f;
	int DropGold = 20;
};
