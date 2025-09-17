#include "Eagle.h"

void Eagle::Move()
{
	//Animal::Move();	// �θ��� Animal�� Move �����ϱ�
	if (Energy < 0.1f)
	{
		printf("[%s] : ���� ��� ������ �� �����ϴ�.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : �����մϴ�.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : �������� 10% �����մϴ�.\n", Name.c_str());
	}
}

void Eagle::MakeSound()
{
	Animal::MakeSound();
	printf("[%s] : ���߾ߤ����Ǥ�\n", Name.c_str());
}

void Eagle::Fly()
{
	printf("[%s]�� ���ٿ�.", Name.c_str());
}
