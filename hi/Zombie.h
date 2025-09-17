#pragma once
#include "Monster.h"


class Zombie : public Monster
{
public:
	void RottingGrasp();

public:
	Zombie() = default;
	Zombie(std::string InName)
		: Monster(InName)
	{
	}
};

