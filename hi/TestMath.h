#pragma once


// ������Ͽ��� ������ �ۼ��Ѵ�.
// ctrl + k + o : �����̸��� cpp�� h�� ��ȯ

void PrintHelloWorld();					// �����ϴ� ���� ����(void), �̸��� PrintHelloWorld�� �Ķ���͵� ����.


/// <summary>
/// �� �Ķ���͸� ���ϴ� �Լ�
/// </summary>
/// <param name="Number1">������ ù��° ����</param>
/// <param name="Number2">������ �ι�° ����</param>
/// <returns>�Ķ���Ͱ� ������ ��</returns>
int Sum(int Number1, int Number2);		// ����Ÿ���� int�� �̸��� Sum�̰� �Ķ���ʹ� int 2���� �Լ��� �����ߴ�.
// int Sum(int, int);					// �����Ҷ��� �Լ��� �Ķ���� �̸��� �����ص� �ȴ�. / ���� ��������

float Sum(float Test1, float Test2);


// ���� �ǽ� ��Ģ����� ���ø� �Լ� 4�� �����
// 
// ���ø�
template <typename T1>
T1 Add(T1 Number1, T1 Number2)
{
	return Number1 + Number2;
}

template <typename T2>
T2 Minus(T2 Number1, T2 Number2)
{
	return Number1 - Number2;
}

template <typename T3>
T3 Multiply(T3 Number1, T3 Number2)
{
	return Number1 * Number2;
}

template <typename T4>
T4 Division(T4 Number1, T4 Number2)
{
	return Number1 / Number2;
}



// �Ķ���� �ΰ��� ���ؼ� �����ִ� �Լ�
int Multiply(int Number1, int Number2 = 2);	// ����Ʈ �Ķ���� ��� ����
											// �ش� �Ķ���� ���� �Լ��� ȣ���ϸ� �⺻������ ������ ���� ��� ��.
											// ����ο��� ���� �����Ѵ�.
											// ����Ʈ �Ķ���ʹ� �׻� �ڿ������� �־�� �Ѵ�.

// ��� ȣ��
int TestRecurcive(int Number);

inline int Square(int Number)
{
	return Number * Number;
}
