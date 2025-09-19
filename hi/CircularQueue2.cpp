#include "CircularQueue2.h"

void CircularQueue2::Enqueue(int InValue)
{
	if (IsFull())
	{
		printf("����: ť�� ���� á���ϴ�!\n");
		return;
	}
	if (IsEmpty())					// ����� �� �ִ� ����� Front�� 0���� ����
	{
		Front = 0;
	}

	Rear = (Rear + 1) % MaxSize;	// Rear�� 1����. MaxSize�� �Ѿ�� �ٽ� 0���� 
	Data[Rear] = InValue;
}

int CircularQueue2::Dequeue()
{
	if (IsEmpty())
	{
		printf("����: ť�� ����ֽ��ϴ�!\n");
		return Empty;
	}
	int Result = Data[Front];

	if (Front != Rear)
	{
		// �Ϲ����� ��Ȳ
		Front = (Front + 1) % MaxSize;
	}
	else
	{
		// ���������� 1���� ���� ��Ȳ
		Front = Empty;
		Rear = Empty;
	}

	return Result;
}

void CircularQueue2::TestPrintQueue()
{
	// Front���� Rear���� ����ϱ�
	// ť�� ũ�⵵ ���
	printf("Queue(ũ�� : %d) : ", GetSize());

	int i = Front;
	while (true)
	{
		printf("%d, ", Data[i]);
		if (i == Rear)
		{
			break;
		}
		i = (i + 1) % MaxSize;
	}
	printf("\n");
}
