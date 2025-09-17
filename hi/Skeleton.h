#pragma once
#include "Monster.h"


class Skeleton : public Monster
{
public:
	void BonePierce();

public:
	Skeleton() = default;
	Skeleton(std::string InName)
		: Monster(InName)
	{
		Health = 75.0f;
	}
};
