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


	int RandomNumber1(int Number1, int Number2)
	{
		return rand() % (Number2 - Number1) + Number1;
	}

	void Age(int Number1)
	{
		printf("����� %d�� �Դϴ�.\n", Number1);
	}

	float Radius(float Number1)
	{
		const float Pie = 3.141592f;
		return Number1 * Number1 * Pie;
	}

	int Number4(int Number1)
	{
		bool result = Number1 % 2 == 1;
		if (result)
		{
			printf("�Է��Ͻ� ���ڴ� Ȧ�� �Դϴ�.\n");
		}
		else
		return 0;
	}

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
		else if (Number1 >= 80)
		{
			printf("����� ������ C�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 80)
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

