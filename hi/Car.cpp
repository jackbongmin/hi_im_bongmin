#include <stdio.h>
#include "Car.h"

Car::Car(const char* InName)
	: Name(InName)
{
	printf("[%s]�ڵ����� �����Ǿ����ϴ�.", Name.c_str());
}

Car::~Car()
{
	printf("[%s] �ڵ����� �����Ǿ����ϴ�.", Name.c_str());
}

void Car::Accel()	// Car Ŭ������ Accel �Լ�
{
	printf("�ڵ����� �����մϴ�.");
}

void Car::Brake()
{
	printf("�ڵ����� �����մϴ�.");
}

void Car::HandleTurn()
{
	printf("�ڵ��� �����ϴ�.\n");
}
