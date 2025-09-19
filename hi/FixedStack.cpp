#include "FixedStack.h"
#include <stdio.h>

void FixedStack::Push(int InValue)
{
	if (IsFull())
	{
		printf("����: ������ ���� á���ϴ�!(Stack Overflow)\n");
		return;
	}
	TopIndex++;					// Top��ġ�� ������Ű��
	Data[TopIndex] = InValue;	// �� ��ġ�� ���� �ֱ�
}

int FixedStack::Pop()
{
	if (IsEmpty())
	{
		printf("����: ������ ����ֽ��ϴ�! (Stack Underflow)\n");
		return 0;
	}
	int Result = Data[TopIndex];
	TopIndex--;
	return Result;
}

int FixedStack::Top() const
{
	if (IsEmpty())
	{
		printf("����: ������ ����ֽ��ϴ�! ���� ��ȯ�� �� �����ϴ�.\n");
		return Empty;	// �������� �ƴ϶� ���������� �츮�� ������ ���� �����ϴ� ��
	}

	return Data[TopIndex];
}
