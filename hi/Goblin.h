#pragma once
#include "Monster.h"


class Goblin : public Monster
{
public:
	void SneakyStab();

public:
	Goblin()
		: Monster("°íºí¸°", 20.0f, 3.0f)
	{
		DropGold = 5;
	}
	Goblin(const char* InName)
		: Monster(InName, 20.0f, 3.0f)
	{
		DropGold = 5;
	}
};

