#include "Practice.h"
#include <iostream>
#include <stdio.h>

//�ѤѤѤѤѤѤѤѤѤѤѤѤ� �ǽ� 0905 �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

/*
[�⺻ �Լ� �ǽ�]

1. Ư�������ȿ� ������ ���� �����ϴ� �Լ�
	- int �Ķ���� 2��
	- int ����

2. "����� ���̸� �Է����ּ��� : " �� "����� 00�� �Դϴ�."
	- int �Ķ���� 1��

3. ���� �������� �Է� �ް� ���̸� ���ϱ�
	- float �Ķ���� 1��
	- float ����

4. ���ڸ� �Է¹޾� Ȧ������ ¦������ �Ǵ��ϴ� �Լ�
	- int �Ķ���� 1��
	- bool ����(true�� Ȧ��, false�� ¦��)

5. �����з� �Լ� (A ~ F)
	- int �Ķ���� 1��
	- int ����(enum ��)

6. ������ ����, ������ ����, ������ ��ۿ� �Լ� �� 3��
	- ��Ʈ�÷����κ��丮 ����
	- int �Ķ���� 2��(Inventory, ��Ʈ�÷��׿� enum)
	- ���� ����

7. �Ƕ�̵� ��� �Լ�
	- int �Ķ���� 1��

[�⺻ ���ø� �ǽ�]

8. Min
	- �Ķ���� 2��
	- ���� : �Ķ���� �� ���� �� ����

9. Max
	- �Ķ���� 2��
	- ���� : �Ķ���� �� ū �� ����

10. Clamp
	- �Ķ���� 3��(value, min, max)
	- ����
		value ���� min���� ������ min
		value ���� max���� ũ�� max
		value ���� min�� max���̸� value

[�⺻ ����Լ� �ǽ�]

11. ����Լ��� �̿��ؼ� ���丮�� ���� ����� �Լ� �����(for��� x)

*/

//�ǽ� 1
	int RandomNumber1(int Number1, int Number2)
	{
		return rand() % (Number2 - Number1) + Number1;
	}

//�ǽ� 2
	void Age(int Number1)
	{
		printf("����� %d�� �Դϴ�.\n", Number1);
	}

//�ǽ� 3
	float Radius(float Number1)
	{
		const float Pie = 3.141592f;
		return Number1 * Number1 * Pie;
	}

//�ǽ� 4

	bool Number4_1(int Number1)
	{
		if (Number1 % 2 == 1)
		{
			printf("�Է��Ͻ� ���ڴ� Ȧ�� �Դϴ�.\n");
			return true;
		}
		else
		{
			printf("�Է��Ͻ� ���ڴ� ¦�� �Դϴ�.\n");
			return false;
		}
	}

//�ǽ� 5
	int Score(int Number1)
	{
		enum score
		{
			A,
			B,
			C,
			D,
			F
		};
		if (Number1 >= 90)
		{
			printf("����� ������ A�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 80)
		{
			printf("����� ������ B�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 70)
		{
			printf("����� ������ C�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 60)
		{
			printf("����� ������ D�Դϴ�.\n");
			return 0;
		}
		else
		{
			printf("����� ������ F�Դϴ�.\n");
			return 0;
		}
	}

//�ǽ� 6

	void SetItem(int Inventory, ItemList Item)
	{
		Inventory |= Item;
	}

	void UnSetItem(int Inventory, ItemList Item)
	{
		Inventory &= ~Item;
	}

	void ToggleItem(int Inventory, ItemList Item)
	{
		Inventory ^= Item;
	}

	//�ǽ� 7
	int Pyramid(int Number1)
	{
		for (int Line = 0; Line <= Number1; Line++)

		{

			for (int Space = 0; Space < (Number1 - Line); Space++)

			{

				printf(" ");

			}

			for (int Star = 0; Star < (2 * Line) - 1; Star++)

			{

				printf("*");

			}

			printf("\n");

		}
		return 0;
	}

//�ǽ� 11
	
	int Factorial(int Number1)
	{
		if (Number1 <= 1)
		{
			return 1;
		}
		else
		{
			return Number1 * (Number1 - 1);
		}		
	}



// �ָ��ǽ� 1
	float Average(float Number1, float Number2, float Number3)
	{
		return (Number1 + Number2 + Number3) / 3.0f;
	}

// �ָ��ǽ� 2
	float SalePrice(float Number1, float Number2)
	{
		return Number1 - (Number1 * Number2 * 0.01);
	}

// �ָ��ǽ� 3
	int Dice(int Number1)
	{
		return rand() % 6 +1;
	}

// �ָ��ǽ� 4
	int Score1(int Number1)
	{
		enum score
		{
			A,
			B,
			C,
			D,
			F
		};
		if (Number1 >= 90)
		{
			printf("����� ������ A�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 80)
		{
			printf("����� ������ B�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 70)
		{
			printf("����� ������ C�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 60)
		{
			printf("����� ������ D�Դϴ�.\n");
			return 0;
		}
		else
		{
			printf("����� ������ F�Դϴ�.\n");
			return 0;
		}
	}

// �ָ��ǽ�(��ȭ) 1
	int TotalSum(int Number1)
	{
		int Sum = 0;
		while (Number1 > 0)
		{
			Sum += Number1 % 10;
			Number1 = Number1 / 10;
		}
		return Sum;
	}


// �ָ��ǽ�(��ȭ) 2
	void DecToBin(int Number1)
	{
		if (Number1 > 1)
		{
			DecToBin(Number1 / 2);
		}
		printf("%d", Number1 % 2);
	}

// �ָ��ǽ�(��ȭ) 3
	void Spin(int Number1, int Number2, int Number3)
	{
		Number1 = rand() % 10 + 1;
		Number2 = rand() % 10 + 1;
		Number3 = rand() % 10 + 1;
		
	}

	int Result(int Numberone, int Numbertwo, int Numberthree, int Number4)
	{
		return 0;
	}


// �ָ��ǽ�(��ȭ) 4

	int PlayerAttack(int Number1)
	{
		int Damage = rand() % 11 + 5;
		if (rand() % 10 == 0)
		{
			Damage *= 2;
			printf("ũ��Ƽ�� ��Ʈ!\n");
		}
			return Damage;
	}


	int ComputerAttack(int Number1)
	{
		int Damage = rand() % 11 + 5;
		if (rand() % 10 == 0)
		{
			Damage *= 2;
			printf("ũ��Ƽ�� ��Ʈ!\n");
		}
		return Damage;
	}

	//�ָ� �ǽ�(��ȭ) 5

	const int Jocker = 14;

	// ī�� ����
	void Card(int Number1)                 
	{
		if (Number1 == Jocker)
		{
			printf("��Ŀ");
		}
		else
		{
			switch (Number1)
			{
				case 1 : printf("A");
					break;
				case 11: printf("J");
					break;
				case 12: printf("Q");
					break;
				case 13: printf("K");
					break;
				default: printf("%d", Number1);
			
			}
		}
			
	}

	//// ī�� ����
	//void Shuffle(int Number1, int Number2)      
	//{
	//	for(int a = Number2 - 1; a > 0; a--)
	//	{
	//		int b = rand() % (a + 1);
	//		int c = (Number1 + a);
	//		(Number1 + a) = (Number1 + b);
	//		(Number1 + b) = c;
	//	}
	//}




