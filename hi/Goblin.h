#pragma once
#include "Monster.h"


class Goblin : public Monster
{
public:
	void SneakyStab();

public:
	Goblin() = default;
	Goblin(std::string InName)
		: Monster(InName)
	{
		Health = 75.0f;
	}
};

