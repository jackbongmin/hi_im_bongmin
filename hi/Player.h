#pragma once
#include "Actor.h"
#include "Position.h"
class Player : public Actor
{
public:
	Player() = default;
	Player(const char* InName, float InHealth, float InAttackPower)
		: Actor(InName, InHealth, InAttackPower)
	{
	}

	const int GetGold() const { return Gold; }

	void AddGold(int InGold) { Gold += InGold; }

	bool PayGold(int Amount);

	void Heal(float Amount);

	Position CurrentPosition = Position(0, 0);
protected:
	int Gold = 0;
};

