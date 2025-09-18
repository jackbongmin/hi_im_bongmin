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
	ListNode* NewNode = new ListNode(InData);	// �� ��� �ϳ� ����

	if (Head == nullptr)
	{
		Head = NewNode;							// �ϳ��ۿ� �����ϱ� �� ��尡 Head���� Tail�̴�.
		Tail = NewNode;
	}
	else
	{
		Tail->Next = NewNode;					// ������ ��� �ڿ� �� ��� �߰�
		Tail = NewNode;							// �� ��带 ���ο� ������ ���� ����
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
		NewNode->Next = PrevNode->Next;				// �� ����� ���� ��带, ���� ����� ���� ���� ����
		PrevNode->Next = NewNode;					// ���� ����� ���� ��带, �� ���� ����
	}
	Size++;

}

void LinkedList::Remove(int32 InData)
{
	if (Head == nullptr)	// ��������� �׳� ������.
		return;

	ListNode* NodeToDelete = nullptr;				// ������ ���
	ListNode* PrevNode = nullptr;					// ������ ����� �� ���
	
	if (Head->Data == InData)
	{
		NodeToDelete = Head;						// ������ �����ͷ� Head�� ����
		Head = Head->Next;							// Head�� Head�� ���� ���� ����
		if (IsEmpty())
		{
			Tail = nullptr;							// Head�� ������� ����Ʈ�� ��ԵǸ� Tail�� nullptr�� ����
		}
	}
	else
	{
		PrevNode = Head;							// PrevNode�� ã��. Head���� �����ؼ� ��� �������� �����ϸ� ã�´�.
		while (PrevNode->Next != nullptr            // Prev�� ���� ��尡 ������� �ʴ�.
			&& PrevNode->Next->Data != InData)      // �׸��� Prev�� ���� ����� �����Ͱ� ã�� �����Ͱ� �ƴϴ�.
		{
			PrevNode = PrevNode->Next;
		}
		if (PrevNode->Next != nullptr)			// PrevNode�� �O�Ҵٸ�
		{
			NodeToDelete = PrevNode->Next;		// Prev�� ���� ��带 ������ ���� ����
			PrevNode->Next = NodeToDelete->Next;// Prev�� ���� ��带 ������ ����� ���� ���� ����
			if (NodeToDelete == Tail)
				Tail = PrevNode;				// ������ ��尡 ������ ���� Prev�� ���ο� ������ ���
		}
	}
	if (NodeToDelete != nullptr)
	{
		delete NodeToDelete;					// NodeToDelete�� ã������ delete
		NodeToDelete = nullptr;
		Size--;									// Size ���̱�
	}
	else
	{
		// ��ã������ ���� ���
		printf("���� : %d���� ���� ��尡 �����ϴ�.\n", InData);
	}

}

void LinkedList::RemoveAt(uint32 InPosition)
{
	if (InPosition >= Size)
	{
		printf("����: %u��ġ�� ������ ������ϴ�.(���� ũ��: %u)\n", InPosition, Size);
		return;
	}

	ListNode* NodeToDelete = nullptr;				// ������ ����� �ּҰ� ����� ����
	if (InPosition == 0)
	{
		// ��带 �����ϴ� ���
		NodeToDelete = Head;
		Head = Head->Next;
		if (Head == nullptr)
		{
			Tail = nullptr;							// ����Ʈ�� ��ԵǸ� Tail�� nullptr�� ����
		}
	}
	else
	{
		// ��尡 �ƴ� ���
		ListNode* Prev = Head;
		const uint32 TargetIndex = InPosition - 1;
		for (uint32 i = 0; i < TargetIndex; i++)
		{
			Prev = Prev->Next;						// ������ �����ؼ� ������ ����� �� ��� ã��
		}
		NodeToDelete = Prev->Next;					// ������ ����, �ճ���� ���� ���
		Prev->Next = NodeToDelete->Next;			// �ճ���� ��������, ������ ����� �������
		if (NodeToDelete == Tail)
		{
			Tail = Prev;							// ������ ��尡 Tail�̸� ���� ��尡 �� Tail
		}
	}

	delete NodeToDelete;							// ���� �����ϰ�
	NodeToDelete = nullptr;							// ������ �ϴ½��� ���̱�(���� ����)
	Size--;											// ������ ���̱�
}

ListNode* LinkedList::Search(int32 InData) const
{
	ListNode* Result = nullptr;						// ã�� ����� �� ������ ����
	ListNode* Current = Head;						// �ϳ��� �����س����� ���� �ӽ� ����
	while (Current != nullptr)  // while(Current)
	{
		if (Current->Data == InData)
		{
			Result = Current;						// ã������ Result�� ����ϰ� while ����
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
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return;
	}
	printf("����Ʈ(ũ��:%u) : ", Size);
	ListNode* Current = Head;
	printf("NewNode : { ");
	while (Current != nullptr)
	{
		printf("%d -> ", Current->Data);
		Current = Current->Next;
	}
	printf("nullptr }\n");
}
