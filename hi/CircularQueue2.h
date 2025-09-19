#pragma once
#include <stdio.h>


class CircularQueue2
{
public:

	CircularQueue2(int InSize = 5)
		:MaxSize(InSize == 0 ? MinSize : InSize)
	{
		if (InSize == 0)
		{
			printf("��û�� ũ�� 0�� ��ȿ���� �����Ƿ� �ּ�ũ���� 1�� �����߽��ϴ�.");
		}
		Data = new int[MaxSize];
	}

	~CircularQueue2() 
	{
		if (Data != nullptr)
		{
			delete[] Data;
			Data = nullptr;
		}
	}

	// ���� ����
	CircularQueue2(const CircularQueue2&) = delete;	// ���� �����ڴ� ����
	CircularQueue2& operator=(const CircularQueue2&) = delete;	// ���� �����ڰ� ����

	void Enqueue(int InValue);

	int Dequeue();

	void TestPrintQueue();

	inline bool IsFull() const
	{
		return (Rear + 1) % MaxSize == Front;
	}

	inline bool IsEmpty() const
	{
		return Front == Empty;	
	}

	inline int Peek() const
	{
		if (IsEmpty())
		{
			printf("����: ť�� ����ֽ��ϴ�.\n");
			return Empty;
		}
		return Data[Front];
	}

	inline int GetSize() const
	{
		return ((Rear + MaxSize) - Front) % MaxSize + 1;
	}

private:
	static constexpr int Empty = -1;
	static constexpr int MinSize = 1;

	int Front = Empty;
	int Rear = Empty;
	int MaxSize;
	int* Data = nullptr;
};

