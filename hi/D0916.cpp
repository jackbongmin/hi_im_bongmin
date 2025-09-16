#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include "fstream"
#include "D0916.h"
#include <iostream>
#include <random>
#include "direct.h"
#include "Car.h"
#include "Animal.h"
#include "Elephant.h"

//Day0916::Day0916()
//{
//	// ��ü�� ������ �� ȣ��
//}
//
//Day0916::~Day0916()
//{
//	// ��ü�� ������ �� ȣ��
//}

void Day0916::ClassInstance()
{
	Car myCar = Car("��������");	// �ν��Ͻ� ����. ������� Ÿ�̹��� �Լ��� ����Ǿ��� �� �����.
	myCar.Accel();

	Car* pCar = new Car("�����Ҵ�");
	pCar->HandleTurn();
	delete pCar;
	pCar = nullptr;
}

/*
���� Ŭ���� ������
	Name : std::string
	Energy : float
	Age : int

	������ �����̸�(Move) �������� �Һ��Ѵ�.
	������ �Ҹ��� ���� �� �ִ�.(MakeSound)
	������ ������(Eat) �������� �����Ѵ�.
	������ ���� �ڸ�(Sleep) ���̰� �����ϰ� �������� ���� ȸ���ȴ�.
	������ ��� ������ ����� �� �ִ�.(ShoInfo)
*/

void Day0916::TestAnimal()
{
	Animal animal;
	animal.ShowInfo();
	animal.MakeSound();
	animal.Move();
	animal.Move();
	animal.Move();
	animal.ShowInfo();
	animal.Eat();
	animal.ShowInfo();
	animal.Move();
	animal.Move();
	animal.Move();
	animal.ShowInfo();
	animal.Sleep();
	animal.ShowInfo();

}



void Day0916::TesrElephant()
{
	Elephant elephant = Elephant("������");
	elephant.Move();
	elephant.Attack();
}


// ���� �ǽ�
// �ٸ� ���� ������
// �ٸ� ���� ���� �Լ� �����ϱ�