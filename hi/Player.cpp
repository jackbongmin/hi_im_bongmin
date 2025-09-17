#include "Player.h"

bool Player::PayGold(int Amount)
{
    if (Amount > Gold) return false;
    Gold -= Amount;
    return true;
}

void Player::Heal(float Amount)
{
    SetHealth(Health + Amount);
}