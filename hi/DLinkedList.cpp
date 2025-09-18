#include "DLinkedList.h"
#include "stdio.h"

DLinkedList::~DLinkedList()
{
	DListNode* Current = Head;
	while (Current)
	{
		DListNode* NodeToDelete = Current;
		Current = Current->Next;
		delete NodeToDelete;
		NodeToDelete = nullptr;
	}
}

void DLinkedList::DAdd(int32 InData)
{
	DListNode* NewNode = new DListNode(InData);

	if (Head == nullptr)
	{
		Head = NewNode;							
		Tail = NewNode;
	}
	else
	{
		Tail->Next = NewNode;		
		NewNode->Prev = Tail;
		Tail = NewNode;						
	}
	Size++;
}

void DLinkedList::DInsertAt(int32 InData, uint32 InPosition)
{
	DListNode* NewNode = new DListNode(InData);


	if (Head == nullptr)
	{
		Head = NewNode;
		Tail = NewNode;
	}
	else if (InPosition == 0)
	{
		NewNode->Next = Head;
		Head->Prev = NewNode;
		Head = NewNode;
	}
	if (InPosition >= Size)
	{
		Tail->Next = NewNode;
		NewNode->Prev = Tail;
		Tail = NewNode;
	}

	DListNode* PrevNode = Head;
	if (InPosition > 0 && InPosition < Size)
	{
		const uint32 TargetIndex = InPosition - 1;
		for (int i = 0; i < TargetIndex; i++)
		{
			PrevNode = PrevNode->Next;
		}
		DListNode* NextNode = PrevNode->Next;
		NewNode->Next = NextNode;
		NewNode->Prev = PrevNode;
		PrevNode->Next = NewNode;
		NextNode->Prev = NewNode;

		if (NewNode != nullptr)
		{
			NewNode->Next = NextNode;
		}
	}
	Size++;
}

void DLinkedList::DRemove(int32 InData)
{
	if (Head == nullptr)	
		return;

	DListNode* NodeToDelete = nullptr;				

	if (Head->Data == InData)
	{
		NodeToDelete = Head;						
		Head = Head->Next;						
		if (Head != nullptr)
		{
			Head->Prev = nullptr;
		}
		else
		{
			Tail = nullptr;						
		}
	}
	else
	{
		DListNode* Current = Head;					
		while (Current != nullptr
			&& Current->Data != InData)
		{
			Current = Current->Next;
		}
		if (Current != nullptr)			
		{
			NodeToDelete = Current;		

			if (NodeToDelete->Prev != nullptr)
			{
				NodeToDelete->Prev->Next = NodeToDelete->Next;
			}
			if (NodeToDelete->Next != nullptr)
			{
				NodeToDelete->Next->Prev = NodeToDelete->Prev;
			}
			if (NodeToDelete == Tail)
				Tail = NodeToDelete->Prev;				
		}
	}
	if (NodeToDelete != nullptr)
	{
		delete NodeToDelete;
		NodeToDelete = nullptr;
		Size--;	
	}
	else
	{
	
		printf("오류 : %d값을 가진 노드가 없습니다.\n", InData);
	}


}

void DLinkedList::DRemoveAt(uint32 InPosition)
{
	if (InPosition >= Size)
	{
		printf("오류: %u위치는 범위를 벗어났습니다.(현재 크기: %u)\n", InPosition, Size);
		return;
	}

	DListNode* NodeToDelete = nullptr;				
	if (InPosition == 0)
	{
		NodeToDelete = Head;
		Head = Head->Next;
		if (Head != nullptr)
		{
			Head->Prev = nullptr;
		}
		else
		{
			Tail = nullptr;
		}
	}
	else
	{
		DListNode* Current = Head;
		for (uint32 i = 0; i < InPosition; i++)
		{
			Current = Current->Next;						
		}
		NodeToDelete = Current;

		if (NodeToDelete->Prev != nullptr)
		{
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		if (NodeToDelete->Next != nullptr)
		{
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}
		if (NodeToDelete == Tail)
		{
			Tail = NodeToDelete->Prev;
			if (Tail = nullptr)
			{
				Head = nullptr;
			}
		}
	}

	delete NodeToDelete;							
	NodeToDelete = nullptr;							
	Size--;											

}

DListNode* DLinkedList::DSearch(int32 InData) const
{
	DListNode* Result = nullptr;						
	DListNode* Current = Head;						
	while (Current != nullptr)  
	{
		if (Current->Data == InData)
		{
			Result = Current;					
			break;
		}
		Current = Current->Next;
	}
	return Result;
}

void DLinkedList::DPrintList() const
{
	if (IsEmpty())
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}
	printf("리스트(크기:%u) : ", Size);
	DListNode* Current = Head;
	printf("NewNode : { ");
	while (Current != nullptr)
	{
		printf("%d -> ", Current->Data);
		Current = Current->Next;
	}
	printf("nullptr }\n");
}
