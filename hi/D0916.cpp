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
//	// 객체가 생성될 때 호출
//}
//
//Day0916::~Day0916()
//{
//	// 객체가 해제될 때 호출
//}

void Day0916::ClassInstance()
{
	Car myCar = Car("지역변수");	// 인스턴스 생성. 사라지는 타이밍은 함수가 종료되었을 때 사라짐.
	myCar.Accel();

	Car* pCar = new Car("동적할당");
	pCar->HandleTurn();
	delete pCar;
	pCar = nullptr;
}

/*
동물 클래스 만들어보기
	Name : std::string
	Energy : float
	Age : int

	동물은 움직이면(Move) 에너지를 소비한다.
	동물은 소리를 지를 수 있다.(MakeSound)
	동물은 먹으면(Eat) 에너지가 증가한다.
	동물은 잠을 자면(Sleep) 나이가 증가하고 에너지가 완전 회복된다.
	동물의 모든 정보를 출력할 수 있다.(ShoInfo)
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
	Elephant elephant = Elephant("꼬끼리");
	elephant.Move();
	elephant.Attack();
}


// 간단 실습
// 다른 동물 만들어보기
// 다른 동물 전용 함수 구현하기