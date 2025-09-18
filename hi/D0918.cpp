#include "D0918.h"
#include "LinkedList.h"
#include "DLinkedList.h"
#include <stdio.h>



void D0918::TestSingleLinkedList()
{
	LinkedList MyList;

	// Add �׽�Ʈ
	printf("Add �׽�Ʈ---------------------------------\n");
	MyList.Add(10);
	MyList.Add(20);
	MyList.Add(30);
	MyList.PrintList();

	// InsertAt test
	printf("\n");
	printf("InsertAt �׽�Ʈ---------------------------------\n");
	MyList.InsertAt(40, 100);
	MyList.PrintList();
	MyList.InsertAt(5, 0);
	MyList.PrintList();
	MyList.InsertAt(15, 2);
	MyList.PrintList();

	// Remove test
	printf("\n");
	printf("Remove �׽�Ʈ---------------------------------\n");
	MyList.Remove(20);
	MyList.PrintList();
	MyList.Remove(123);
	MyList.PrintList();

	// RemoveAt test
	printf("\n");
	printf("RemoveAt �׽�Ʈ---------------------------------\n");
	MyList.RemoveAt(10);
	MyList.PrintList();
	MyList.RemoveAt(1);
	MyList.PrintList();

	// Search test
	printf("\n");
	printf("Search �׽�Ʈ---------------------------------\n");
	ListNode* Found = MyList.Search(15);
	if (Found)
	{
		printf("15�� ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("15�� �����ϴ�.\n");
	}
	Found = MyList.Search(999);
	if (Found)
	{
		printf("999�� ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("999�� �����ϴ�.\n");
	}

}

void D0918::Test0918()
{
	LinkedList MyList;

	MyList.Add(10);
	MyList.Add(20);
	MyList.Add(30);
	MyList.PrintList();

	MyList.InsertAt(15, 0);
	MyList.PrintList();
}

void D0918::TestDoubleLinkedList()
{
	DLinkedList MyDList;

	// Add �׽�Ʈ
	printf("Add �׽�Ʈ---------------------------------\n");
	MyDList.DAdd(10);
	MyDList.DAdd(20);
	MyDList.DAdd(30);
	MyDList.DPrintList();

	// InsertAt test
	printf("\n");
	printf("InsertAt �׽�Ʈ---------------------------------\n");
	MyDList.DInsertAt(40, 100);
	MyDList.DPrintList();
	MyDList.DInsertAt(5, 0);
	MyDList.DPrintList();
	MyDList.DInsertAt(15, 2);
	MyDList.DPrintList();

	// Remove test
	printf("\n");
	printf("Remove �׽�Ʈ---------------------------------\n");
	MyDList.DRemove(20);
	MyDList.DPrintList();
	MyDList.DRemove(123);
	MyDList.DPrintList();

	// RemoveAt test
	printf("\n");
	printf("RemoveAt �׽�Ʈ---------------------------------\n");
	MyDList.DRemoveAt(10);
	MyDList.DPrintList();
	MyDList.DRemoveAt(1);
	MyDList.DPrintList();

	// Search test
	printf("\n");
	printf("Search �׽�Ʈ---------------------------------\n");
	DListNode* Found = MyDList.DSearch(15);
	if (Found)
	{
		printf("15�� ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("15�� �����ϴ�.\n");
	}
	Found = MyDList.DSearch(999);
	if (Found)
	{
		printf("999�� ã�ҽ��ϴ�.\n");
	}
	else
	{
		printf("999�� �����ϴ�.\n");
	}


}
