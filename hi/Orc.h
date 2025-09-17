#pragma once
#include "Monster.h"


class Orc : public Monster
{
public:
	void BrutalSmash();

public:
	Orc() = default;
	Orc(std::string InName)
		: Monster(InName)
	{
		Health = 150.0f;
	}
};

