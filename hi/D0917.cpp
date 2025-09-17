
#include "D0917.h"
#include "Elephant.h"
#include "Eagle.h"
#include "Dog.h"
#include "Shape.h"
#include <stdint.h>

#include "TestSample.h"

void D0917::TestPolymorphism()
{
	Elephant* pElephant = new Elephant("������");
	Eagle* pEagle = new Eagle("���׾���");
	
	printf("������ �̵�\n");
	pElephant->Move();
	printf("���׾��� �̵�\n");
	pEagle->Move();

	printf("���� �̵�\n");
	Animal* pAnimal = pElephant;
	pAnimal->Move();		// Animal�� Move�� ����� -> �����Լ��� �� �Ŀ��� ���� Ŭ������ Move�� ����ȴ�.
	
	// C++ ��Ÿ�� ĳ���� �� �ϳ�
	//dynamic_cast : ��Ÿ��(������)�� �� �ּҰ� ���� � �ڽ� Ŭ������ ��ü�� ����Ű�� �ִ��� �����ϰ� Ȯ�����ִ� cast

	Elephant* pTempElephant = dynamic_cast<Elephant*>(pAnimal);
	if (pTempElephant == nullptr)
	{
		// pAnimal�� Tiger*�� �ƴϴ�.
	}
	else
	{
		// pAnimal�� ����� �ּҴ� Tiger�� �ּҰ� �´�.
		pTempElephant->Attack1();
	}

	delete pElephant;
	pElephant = nullptr;
	delete pEagle;
	pEagle = nullptr;

}

void D0917::TestVirtualFunction()
{
	Parent* pParent = new Child();	// ����
	delete pParent;
	pParent = nullptr;
}

void D0917::TestPractice1()
{
	// ���� �ǽ�
	// Animal*�� �迭 �����
	// ���������� ������ �ֱ�
	// �迭�� ����ִ� ��� ������ MakeSound �����ϱ�

	const int Size = 5;
	Animal* Zoo[Size];
	Zoo[0] = new Elephant("������");
	Zoo[1] = new Elephant("��Ű��");
	Zoo[2] = new Eagle("���׾���");
	Zoo[3] = new Eagle("���⾥��");
	Zoo[4] = new Dog("����");

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

	// ���� �ǽ�
	// Animal�� Move�Լ��� ���� ���� �Լ��� ���� Animal�� �߻�Ŭ������ �����
	// �� �������� Move�� ������ �� �����ϱ�

	Elephant* pElephant = new Elephant("������");
	printf("������ �̵�\n");
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
	//};	// ���� enum�� ������ �����̱� ������ �̸��� ��ġ�� �ȵ�

	Color myColor = Green;
	Fruit myFruit = Orange;
	
	if (myColor == myFruit)
	{
		// �������δ� ���� �ȵ����� ���������� ����� ��
	}

	// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

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
		Red = 0,	// TrafficLight2�ȿ� �ִ� Red�� ������ �̸��� ��ġ�� �ʴ´�.
		Yellow,
		Green
	};

	Color2 myColor2 = Color2::Red;
	Fruit2 myFruit2 = Fruit2::Apple;
	//if (myColor2 == myFruit2)
	//{
	//	// ���������� ����.
	//}

	//int Number = myColor2;	// �̰͵� �ȵ� / �Ͻ��� ĳ������ ����
	int Number = static_cast<int>(myColor2);	// ����� ĳ������ �ʼ�

	PlayerState state = PlayerState::None;
	state = static_cast<PlayerState>(static_cast<int>(state) | static_cast<int>(PlayerState::OnGround));

	// ���� �ǽ�
	// &, ~, |=, &=



}

