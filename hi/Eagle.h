#pragma once
#include "Animal.h"
#include "IFlyable.h"

class Eagle : public Animal, public IFlyable 
{
public:
	virtual void Move() override;	// �������� Animal�� Move�Լ��� �������.

	virtual void MakeSound() override;

	virtual void Fly() override;

public:
	// ������, �Ҹ��ڴ� ����� ����� �ƴϴ�.
	Eagle() = default;
	Eagle(std::string InName)
		: Animal(InName)			// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}
	virtual ~Eagle() {};
};

