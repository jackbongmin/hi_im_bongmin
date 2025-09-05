#pragma once

/*
1. Ư�������ȿ� ������ ���� �����ϴ� �Լ�
	- int �Ķ���� 2��
	- int ����

*/

// �ǽ�1
int RandomNumber1(int Number1, int Number2);

// �ǽ�2
void Age(int Number1);

// �ǽ�3
float Radius(float Number1);

// �ǽ� 4
bool Number4_1(int Number1);

// �ǽ� 5
int Score(int Number1);

// �ǽ� 6

enum ItemList
{
	Sword  = 1 << 0,
	Shield = 1 << 1,
	Arnmor = 1 << 2
};

void SetItem(int Inventory, ItemList Item);
void UnSetItem(int Inventory, ItemList Item);
void ToggleItem(int Inventory, ItemList Item);

// �ǽ� 7
int Pyramid(int Number1);

// �ǽ� 8
template <typename M>
M Min(M Number1, M Number2)
{
	if (Number1 > Number2)
	{
		printf("�� �� ���� ���ڴ� %d�Դϴ�.\n", Number2);
		return 0;
	}
	else
	{
		printf("�� �� ���� ���ڴ� %d�Դϴ�.\n", Number1);
		return 0;
	}
}

// �ǽ� 9
template <typename MM>
MM Max(MM Number1, MM Number2)
{
	if (Number1 > Number2)
	{
		printf("�� �� ū ���ڴ� %d�Դϴ�.\n", Number1);
		return 0;
	}
	else
	{
		printf("�� �� ū ���ڴ� %d�Դϴ�.\n", Number2);
		return 0;
	}
}

// �ǽ� 10

template <typename C>
C Clamp(C Number1, C Number2, C Number3)
{
	if (Number1 < Number2)
	{
		printf("min�� %d�Դϴ�.\n", Number2);
		return 0;
	}
	else if (Number1 > Number3)
	{
		printf("max�� %d�Դϴ�.\n", Number3);
		return 0;
	}
	else
	{
		printf("%d�� value�Դϴ�.\n", Number1);
		return 0;
	}
}

// �ǽ� 11

int Factorial(int Number1);

