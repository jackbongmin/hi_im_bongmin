#pragma once
#include "Animal.h"

class Eagle : public Animal // Elephant�� Animal�� ��� ��ӹ޾Ҵ�.
{
public:
	void Fly();	

public:
	// ������, �Ҹ��ڴ� ����� ����� �ƴϴ�.
	Eagle() = default;
	Eagle(std::string InName)
		: Animal(InName)			// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}
};

