#pragma once
#include "Monster.h"


class Zombie : public Monster
{
public:
	void RottingGrasp();

public:
	Zombie()
		: Monster("����") {}
	Zombie(const char* InName)
		: Monster(InName)
	{
	}
};

