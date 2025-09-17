#pragma once
#include "Monster.h"


class Skeleton : public Monster
{
public:
	void BonePierce();

public:
	Skeleton()
		: Monster("���̷���", 30.0f, 8.0f)
	{
		DropGold = 15;
	}
	Skeleton(const char* InName)
		: Monster(InName, 30.0f, 8.0f)
	{
		DropGold = 15;
	}
};
