
#include "D0917.h"
#include "Elephant.h"
#include "Eagle.h"
#include "Dog.h"
#include "Shape.h"
#include <stdint.h>

#include "TestSample.h"

void D0917::TestPolymorphism()
{
	Elephant* pElephant = new Elephant("꼬끼리");
	Eagle* pEagle = new Eagle("도그쑤리");
	
	printf("꼬끼리 이동\n");
	pElephant->Move();
	printf("도그쑤리 이동\n");
	pEagle->Move();

	printf("동물 이동\n");
	Animal* pAnimal = pElephant;
	pAnimal->Move();		// Animal의 Move가 실행됨 -> 가상함수가 된 후에는 원래 클래스의 Move가 실행된다.
	
	// C++ 스타일 캐스팅 중 하나
	//dynamic_cast : 런타임(실행중)에 이 주소가 실제 어떤 자식 클래스의 객체를 가리키고 있는지 안전하게 확인해주는 cast

	Elephant* pTempElephant = dynamic_cast<Elephant*>(pAnimal);
	if (pTempElephant == nullptr)
	{
		// pAnimal은 Tiger*가 아니다.
	}
	else
	{
		// pAnimal에 저장된 주소는 Tiger의 주소가 맞다.
		pTempElephant->Attack1();
	}

	delete pElephant;
	pElephant = nullptr;
	delete pEagle;
	pEagle = nullptr;

}

void D0917::TestVirtualFunction()
{
	Parent* pParent = new Child();	// 가능
	delete pParent;
	pParent = nullptr;
}

void D0917::TestPractice1()
{
	// 간단 실습
	// Animal*의 배열 만들기
	// 여러종류의 동물을 넣기
	// 배열에 들어있는 모든 동물의 MakeSound 실행하기

	const int Size = 5;
	Animal* Zoo[Size];
	Zoo[0] = new Elephant("꼬끼리");
	Zoo[1] = new Elephant("꽃키리");
	Zoo[2] = new Eagle("도그쑤리");
	Zoo[3] = new Eagle("더기쑤리");
	Zoo[4] = new Dog("김희연");

	for (int i = 0; i < Size; i++)
	{
		Zoo[i]->MakeSound();
	}

	for (int i = 0; i < Size; i++)
	{
		delete Zoo[i];
		Zoo[i] = nullptr;
	}
}

void D0917::TestAbstractClass()
{
	//Shape* pShape = new Shape();

	// 간단 실습
	// Animal의 Move함수를 순수 가상 함수로 만들어서 Animal을 추상클래스로 만들기
	// 각 동물들의 Move는 별도로 다 구현하기

	Elephant* pElephant = new Elephant("꼬끼리");
	printf("꼬끼리 이동\n");
	pElephant->Move();
	delete pElephant;
	pElephant = nullptr;

}



void D0917::TestEnumClass()
{
	enum Color
	{
		Red = 0,
		Green,
		Blue,
	};

	enum Fruit
	{
		Apple = 0,
		Orange,
		Banana
	};

	//enum TrafficLight
	//{
	//	Red, Yellow, Green
	//};	// 기존 enum은 범위가 전역이기 때문에 이름이 겹치면 안됨

	Color myColor = Green;
	Fruit myFruit = Orange;
	
	if (myColor == myFruit)
	{
		// 논리적으로는 말이 안되지만 문법적으로 허용이 됨
	}

	// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

	enum class Color2
	{
		Red = 0,
		Green,
		Blue,
	};

	enum class Fruit2
	{
		Apple = 0,
		Orange,
		Banana
	};

	enum class TrafficLight2
	{
		Red = 0,	// TrafficLight2안에 있는 Red기 때문에 이름이 겹치지 않는다.
		Yellow,
		Green
	};

	Color2 myColor2 = Color2::Red;
	Fruit2 myFruit2 = Fruit2::Apple;
	//if (myColor2 == myFruit2)
	//{
	//	// 문법적으로 금지.
	//}

	//int Number = myColor2;	// 이것도 안됨 / 암시적 캐스팅은 금지
	int Number = static_cast<int>(myColor2);	// 명시적 캐스팅이 필수

	PlayerState state = PlayerState::None;
	state = static_cast<PlayerState>(static_cast<int>(state) | static_cast<int>(PlayerState::OnGround));

	// 간단 실습
	// &, ~, |=, &=



}

