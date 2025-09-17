#pragma once
#include "Animal.h"

class Dog : public Animal // Elephant�� Animal�� ��� ��ӹ޾Ҵ�.
{
public:
	void howl();
	virtual void Move() override;
	virtual void MakeSound() override;

public:
	// ������, �Ҹ��ڴ� ����� ����� �ƴϴ�.
	Dog() = default;
	Dog(std::string InName)
		: Animal(InName)			// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}
	virtual ~Dog() {};
};
