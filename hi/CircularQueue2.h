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
			printf("요청한 크기 0은 유효하지 않으므로 최소크기인 1로 설정했습니다.");
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

	// 복사 방지
	CircularQueue2(const CircularQueue2&) = delete;	// 복사 생성자는 없음
	CircularQueue2& operator=(const CircularQueue2&) = delete;	// 대입 연산자가 없음

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
			printf("오류: 큐가 비어있습니다.\n");
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

