#pragma once
#include "Animal.h"

class Dog : public Animal // Elephant�� Animal�� ��� ��ӹ޾Ҵ�.
{
public:
	void howl();

public:
	// ������, �Ҹ��ڴ� ����� ����� �ƴϴ�.
	Dog() = default;
	Dog(std::string InName)
		: Animal(InName)			// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}
};
