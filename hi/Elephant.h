#pragma once
#include "Animal.h"

class Elephant : public Animal // Elephant�� Animal�� ��� ��ӹ޾Ҵ�.
{
public:
	void Attack1();	// �ڳ��� ���� �Լ�

public:
	// ������, �Ҹ��ڴ� ����� ����� �ƴϴ�.
	Elephant() = default;
	Elephant(std::string InName)
		: Animal(InName)			// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}
};

