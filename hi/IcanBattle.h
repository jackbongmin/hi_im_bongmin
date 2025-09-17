#pragma once

class ICanBattle
{
public:
	virtual ~ICanBattle() {};

	virtual void ApplyAttack(ICanBattle* InTarget) = 0;
	virtual void TakeDamage(float InDamage) = 0;

	// 맴버 변수가 꼭 필요한 경우. Getter가 있다는것을 명시
	//virtual void GetAttackPower() = 0;
};