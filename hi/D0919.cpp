#include <stdio.h>
#include <iostream>
#include "D0919.h"
#include "FixedStack.h"
#include "CircularQueue.h"

void D0919::TestStack()
{
	FixedStack Stack;

	// 1.초기 상태 테스트
	//	스택이 비었는지 확인해보기(IsEmpty와 GetSize 사용하고 printf로 출력하기)

	printf("1.스택이 비었는지 확인해보기(IsEmpty와 GetSize 사용하고 printf로 출력하기\n");
	Stack.IsEmpty();
	printf("스택의 크기는 %d 입니다.\n\n", Stack.GetSize());

	// 2. Push 테스트
	//	데이터(10) 넣고 Top 위치에 있는 값과 스택 크기 출력해보기
	//	데이터(20) 넣고 Top 위치에 있는 값과 스택 크기 출력해보기
	//	데이터(30) 넣고 Top 위치에 있는 값과 스택 크기 출력해보기

	printf("2.Push 테스트\n");
	Stack.Push(10);
	printf("Top : %d, StackSize : %d\n", Stack.Top(), Stack.GetSize());
	Stack.Push(20);
	printf("Top : %d, StackSize : %d\n", Stack.Top(), Stack.GetSize());
	Stack.Push(30);
	printf("Top : %d, StackSize : %d\n\n", Stack.Top(), Stack.GetSize());



	// 3. Pop 테스트
	//	데이터 하나 빼고 뺀 값 출력해보기, 스탟의 남은 Top 위치값과 스택 크기 출력해보기

	printf("3.Pop 테스트\n");
	printf("뺀 값 : %d, 현재 Top : %d, StackSize : %d\n\n", Stack.Pop(), Stack.Top(), Stack.GetSize());

	// 4. 스택 오버플로우 테스트
	//	스택 가득 채우고 한번 더 넣어 보기
	
	printf("4.오버플로우 테스트\n");
	for (int i = Stack.GetSize(); i < 10; i++)
	{
		Stack.Push(10);
	}

	Stack.Push(20);
	printf("\n");

	// 5. 스택 언더플로우 테스트
	//	스택 다 비우고 한번 더 빼보기

	printf("5.언더플로우 테스트\n");
	for (int i = Stack.GetSize(); i > 0; i--)
	{
		Stack.Pop();
	}

	Stack.Pop();



}

void D0919::TestQueue()
{
	// 메뉴 만들기
	//	1. Enqueue
	//	2. Dequeue
	//	3. Peek	
	//	4. TestPrintQueue
	//	5. 종료
	printf("실습1\nQueue 메뉴 만들기\n\n");
	CircularQueue Queue;
	while (true)
	{
		printf("(1.Enqueue  2.Dequeue  3.Peek  4.TestPrintQueue  5.종료)\n명령어를 입력하시오 : ");
		int Index = 0;
		std::cin >> Index;
		if (Index == 1)
		{
			int Value = 0;
			printf("Enqueue할 값을 입력하시오. : ");
			std::cin >> Value;
			Queue.Enqueue(Value);

		}
		else if (Index == 2)
		{
			Queue.Dequeue();
		}
		else if (Index == 3)
		{
			printf("Front는 %d입니다.\n", Queue.Peek());
		}
		else if (Index == 4)
		{
			Queue.TestPrintQueue();
		}
		else if (Index == 5)
		{
			break;
		}
		else
		{
			printf("잘못된 값을 입력하셨습니다. 다시 입력하시오.\n");
		}
	}

	// 2. Circular Queue2 만들기
	//	생성자에서 파라메터를 받아 크기를 조절 가능하게 만들기
	printf("실습2\nCircular Queue2 만들기\n\n");


}

void D0919::TestArt()
{
	printf("   /^\\\n");
	printf("  ( *_*)\n");
	printf("  <)   )┘\n");
	printf("   /__\\\n");
	printf("  ┘  └\n");
}
 