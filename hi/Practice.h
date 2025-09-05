#pragma once

/*
1. 특정범위안에 랜덤한 수를 리턴하는 함수
	- int 파라메터 2개
	- int 리턴

*/

// 실습1
int RandomNumber1(int Number1, int Number2);

// 실습2
void Age(int Number1);

// 실습3
float Radius(float Number1);

// 실습 4
bool Number4_1(int Number1);

// 실습 5
int Score(int Number1);

// 실습 6

enum ItemList
{
	Sword  = 1 << 0,
	Shield = 1 << 1,
	Arnmor = 1 << 2
};

void SetItem(int Inventory, ItemList Item);
void UnSetItem(int Inventory, ItemList Item);
void ToggleItem(int Inventory, ItemList Item);

// 실습 7
int Pyramid(int Number1);

// 실습 8
template <typename M>
M Min(M Number1, M Number2)
{
	if (Number1 > Number2)
	{
		printf("둘 중 작은 숫자는 %d입니다.\n", Number2);
		return 0;
	}
	else
	{
		printf("둘 중 작은 숫자는 %d입니다.\n", Number1);
		return 0;
	}
}

// 실습 9
template <typename MM>
MM Max(MM Number1, MM Number2)
{
	if (Number1 > Number2)
	{
		printf("둘 중 큰 숫자는 %d입니다.\n", Number1);
		return 0;
	}
	else
	{
		printf("둘 중 큰 숫자는 %d입니다.\n", Number2);
		return 0;
	}
}

// 실습 10

template <typename C>
C Clamp(C Number1, C Number2, C Number3)
{
	if (Number1 < Number2)
	{
		printf("min은 %d입니다.\n", Number2);
		return 0;
	}
	else if (Number1 > Number3)
	{
		printf("max은 %d입니다.\n", Number3);
		return 0;
	}
	else
	{
		printf("%d은 value입니다.\n", Number1);
		return 0;
	}
}

// 실습 11

int Factorial(int Number1);

