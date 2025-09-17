#include "MazePlayer.h"

void MazePlayer::TakeGold(int Amount)
{
	Gold += Amount;
}

void MazePlayer::TakeAttack(float Amount)
{
	Health -= Amount;
}

//void MazePlayer::Heal(float Amount)
//{
//	Health += Amount;
//	if (Health > MaxHealth)
//		Health = MaxHealth;
//}

//void MazePlayer::PayGold(int Amount)
//{
//	Gold -= Amount;
//}
