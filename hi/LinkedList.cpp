#include "LinkedList.h"
#include "stdio.h"

LinkedList::~LinkedList()
{
	ListNode* Current = Head;
	while (Current)
	{
		ListNode* NodeToDelete = Current;
		Current = Current->Next;
		delete NodeToDelete;
		NodeToDelete = nullptr;
	}
}

void LinkedList::Add(int32 InData)
{
	ListNode* NewNode = new ListNode(InData);	// 새 노드 하나 생성

	if (Head == nullptr)
	{
		Head = NewNode;							// 하나밖에 없으니까 새 노드가 Head이자 Tail이다.
		Tail = NewNode;
	}
	else
	{
		Tail->Next = NewNode;					// 마지막 노드 뒤에 새 노드 추가
		Tail = NewNode;							// 새 노드를 새로운 마지막 노드로 설정
	}
	Size++;
}

void LinkedList::InsertAt(int32 InData, uint32 InPosition)
{
	ListNode* NewNode = new ListNode(InData);


	if (Head == nullptr)
	{
		Head = NewNode;
		Tail = NewNode;
	}
	if (InPosition == 0)
	{
		NewNode->Next = Head;
		Head = NewNode;
	}
	if (InPosition >= Size)
	{
		Tail->Next = NewNode;
		Tail = NewNode;
	}
	ListNode* PrevNode = Head;
	if (InPosition > 0 && InPosition < Size)
	{
		const uint32 TargetIndex = InPosition - 1;
		for (int i = 0; i < TargetIndex;i++)
		{
			PrevNode = PrevNode->Next;
		}
		NewNode->Next = PrevNode->Next;				// 새 노드의 다음 노드를, 이전 노드의 다음 노드로 설정
		PrevNode->Next = NewNode;					// 이전 노드의 다음 노드를, 새 노드로 설정
	}
	Size++;

}

void LinkedList::Remove(int32 InData)
{
	if (Head == nullptr)	// 비어있으면 그냥 끝낸다.
		return;

	ListNode* NodeToDelete = nullptr;				// 삭제할 노드
	ListNode* PrevNode = nullptr;					// 삭제할 노드의 앞 노드
	
	if (Head->Data == InData)
	{
		NodeToDelete = Head;						// 삭제할 데이터로 Head를 설정
		Head = Head->Next;							// Head를 Head의 다음 노드로 설정
		if (IsEmpty())
		{
			Tail = nullptr;							// Head의 삭제결과 리스트가 비게되면 Tail도 nullptr로 설정
		}
	}
	else
	{
		PrevNode = Head;							// PrevNode를 찾기. Head에서 시작해서 계속 다음으로 전진하며 찾는다.
		while (PrevNode->Next != nullptr            // Prev의 다음 노드가 비어있지 않다.
			&& PrevNode->Next->Data != InData)      // 그리고 Prev의 다음 노드의 데이터가 찾는 데이터가 아니다.
		{
			PrevNode = PrevNode->Next;
		}
		if (PrevNode->Next != nullptr)			// PrevNode를 찿았다면
		{
			NodeToDelete = PrevNode->Next;		// Prev의 다음 노드를 삭제할 노드로 설정
			PrevNode->Next = NodeToDelete->Next;// Prev의 다음 노드를 삭제할 노드의 다음 노드로 설정
			if (NodeToDelete == Tail)
				Tail = PrevNode;				// 삭제할 노드가 마지막 노드면 Prev가 새로운 마지막 노드
		}
	}
	if (NodeToDelete != nullptr)
	{
		delete NodeToDelete;					// NodeToDelete를 찾았으면 delete
		NodeToDelete = nullptr;
		Size--;									// Size 줄이기
	}
	else
	{
		// 못찾았으면 에러 출력
		printf("오류 : %d값을 가진 노드가 없습니다.\n", InData);
	}

}

void LinkedList::RemoveAt(uint32 InPosition)
{
	if (InPosition >= Size)
	{
		printf("오류: %u위치는 범위를 벗어났습니다.(현재 크기: %u)\n", InPosition, Size);
		return;
	}

	ListNode* NodeToDelete = nullptr;				// 삭제할 노드의 주소가 저장될 변수
	if (InPosition == 0)
	{
		// 헤드를 삭제하는 경우
		NodeToDelete = Head;
		Head = Head->Next;
		if (Head == nullptr)
		{
			Tail = nullptr;							// 리스트가 비게되면 Tail도 nullptr로 설정
		}
	}
	else
	{
		// 헤드가 아닌 경우
		ListNode* Prev = Head;
		const uint32 TargetIndex = InPosition - 1;
		for (uint32 i = 0; i < TargetIndex; i++)
		{
			Prev = Prev->Next;						// 헤드부터 시작해서 삭제할 노드의 앞 노드 찾기
		}
		NodeToDelete = Prev->Next;					// 삭제할 노드는, 앞노드의 다음 노드
		Prev->Next = NodeToDelete->Next;			// 앞노드의 다음노드는, 삭제할 노드의 다음노드
		if (NodeToDelete == Tail)
		{
			Tail = Prev;							// 삭제할 노드가 Tail이면 이전 노드가 새 Tail
		}
	}

	delete NodeToDelete;							// 실제 삭제하고
	NodeToDelete = nullptr;							// 무조건 하는습관 들이기(좋은 습관)
	Size--;											// 사이즈 줄이기
}

ListNode* LinkedList::Search(int32 InData) const
{
	ListNode* Result = nullptr;						// 찾은 결과가 들어갈 포인터 변수
	ListNode* Current = Head;						// 하나씩 진행해나가기 위한 임시 변수
	while (Current != nullptr)  // while(Current)
	{
		if (Current->Data == InData)
		{
			Result = Current;						// 찾았으면 Result에 기록하고 while 종료
			break;
		}
		Current = Current->Next;
	}
	return Result;
}

void LinkedList::PrintList() const
{
	if (IsEmpty())
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}
	printf("리스트(크기:%u) : ", Size);
	ListNode* Current = Head;
	printf("NewNode : { ");
	while (Current != nullptr)
	{
		printf("%d -> ", Current->Data);
		Current = Current->Next;
	}
	printf("nullptr }\n");
}
