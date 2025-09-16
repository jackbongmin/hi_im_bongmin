#include "Animal.h"

void Animal::Move()
{
	if (Energy < 0.1f)
	{
		printf("[%s] : ���� ��� ������ �� �����ϴ�.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : �����Դϴ�.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : �������� 10% �����մϴ�.\n", Name.c_str());
	}
}

void Animal::MakeSound()
{
	printf("[%s] : �Ҹ��� ���ϴ�.\n", Name.c_str());
}

void Animal::Eat()
{
	printf("[%s] : �Խ��ϴ�.\n", Name.c_str());
	printf("[%s] : �������� 30% ȸ���մϴ�.\n", Name.c_str());
	SetEnergy(Energy + 0.3f);
}

void Animal::Sleep()
{
	printf("[%s] : ���� ��ϴ�.\n", Name.c_str());
	printf("[%s] : �������� 100% ȸ���մϴ�.\n", Name.c_str());
	SetEnergy(1.0f);
	Age++;
	printf("[%s] : ���̰� �ѻ� �����մϴ�. %d�� �Դϴ�.\n", Name.c_str(), Age);
}

void Animal::ShowInfo()
{
	printf("�̸�\t: %s\n", Name.c_str());
	printf("����\t: %d ��\n", Age);
	printf("������\t: %.0f �ۼ�Ʈ\n", Energy * 100);
}
