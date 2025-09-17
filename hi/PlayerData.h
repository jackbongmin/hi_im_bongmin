#pragma once
#include "Position.h"

struct PlayerData
{
	const float MaxHealth = 100.0f;

	Position CurrentPosition = Position(0,0);
	float Health = MaxHealth;
	float AttackPower = 20.0f;
	int Gold = 0;


	PlayerData() : CurrentPosition(0, 0), AttackPower(20.0f), Health(100.0f), Gold(0) {}

};

//class MazePlayer1
//{
//public:
//	inline const float GetHealth() const { return Health; }
//	inline const float GetAttackPower() const { return AttackPower; }
//	inline const int GetGold() const { return Gold; }
//
//
//
//protected:
//
//	const float MaxHealth = 100.0f;
//	float Health = MaxHealth;
//	float AttackPower = 20.0f;
//	int Gold = 0;
//};