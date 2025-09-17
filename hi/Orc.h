#pragma once
#include "Monster.h"


class Orc : public Monster
{
public:
	void BrutalSmash();

public:
	Orc()
		: Monster("ø¿≈©", 75.0f, 5.0f)
	{
		DropGold = 30;
	}
	Orc(const char* InName)
		: Monster(InName, 75.0f, 5.0f)
	{
		DropGold = 30;
	}
};

