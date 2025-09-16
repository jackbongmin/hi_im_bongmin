#pragma once
#include<string>

class Monster
{
public:
	inline const std::string& GetName() const { return Name; }
	inline const float GetHealth() const { return Health; }
	inline const float GetAttackPower() const { return AttackPower; }

	Monster() = default;
	Monster(std::string InName)
		: Name(InName)
	{
	}

	float Attack();

protected:
	std::string Name;
	float Health = 100.0f;
	float AttackPower = 10.0f;
};

