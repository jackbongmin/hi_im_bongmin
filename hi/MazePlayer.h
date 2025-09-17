#pragma once
#include "Position.h"
#include "Actor.h"

class MazePlayer : public Actor
{
public:
	inline const float GetHealth() const { return Health; }
	inline const float GetAttackPower() const { return AttackPower; }
	//inline const int GetGold() const { return Gold; }
	const float MaxHealth = 100.0f;

	Position CurrentPosition = Position(0, 0);

	void TakeGold(int Amount);
	void TakeAttack(float Amount);
	//void Heal(float Amount);
	//void PayGold(int Amount);

protected:

	float Health = MaxHealth;
	float AttackPower = 20.0f;
	int Gold = 0;
};