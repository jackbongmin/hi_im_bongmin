#include "D0918.h"
#include "LinkedList.h"
#include "DLinkedList.h"
#include <stdio.h>



void D0918::TestSingleLinkedList()
{
	LinkedList MyList;

	// Add 테스트
	printf("Add 테스트---------------------------------\n");
	MyList.Add(10);
	MyList.Add(20);
	MyList.Add(30);
	MyList.PrintList();

	// InsertAt test
	printf("\n");
	printf("InsertAt 테스트---------------------------------\n");
	MyList.InsertAt(40, 100);
	MyList.PrintList();
	MyList.InsertAt(5, 0);
	MyList.PrintList();
	MyList.InsertAt(15, 2);
	MyList.PrintList();

	// Remove test
	printf("\n");
	printf("Remove 테스트---------------------------------\n");
	MyList.Remove(20);
	MyList.PrintList();
	MyList.Remove(123);
	MyList.PrintList();

	// RemoveAt test
	printf("\n");
	printf("RemoveAt 테스트---------------------------------\n");
	MyList.RemoveAt(10);
	MyList.PrintList();
	MyList.RemoveAt(1);
	MyList.PrintList();

	// Search test
	printf("\n");
	printf("Search 테스트---------------------------------\n");
	ListNode* Found = MyList.Search(15);
	if (Found)
	{
		printf("15를 찾았습니다.\n");
	}
	else
	{
		printf("15가 없습니다.\n");
	}
	Found = MyList.Search(999);
	if (Found)
	{
		printf("999를 찾았습니다.\n");
	}
	else
	{
		printf("999가 없습니다.\n");
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

	// Add 테스트
	printf("Add 테스트---------------------------------\n");
	MyDList.DAdd(10);
	MyDList.DAdd(20);
	MyDList.DAdd(30);
	MyDList.DPrintList();

	// InsertAt test
	printf("\n");
	printf("InsertAt 테스트---------------------------------\n");
	MyDList.DInsertAt(40, 100);
	MyDList.DPrintList();
	MyDList.DInsertAt(5, 0);
	MyDList.DPrintList();
	MyDList.DInsertAt(15, 2);
	MyDList.DPrintList();

	// Remove test
	printf("\n");
	printf("Remove 테스트---------------------------------\n");
	MyDList.DRemove(20);
	MyDList.DPrintList();
	MyDList.DRemove(123);
	MyDList.DPrintList();

	// RemoveAt test
	printf("\n");
	printf("RemoveAt 테스트---------------------------------\n");
	MyDList.DRemoveAt(10);
	MyDList.DPrintList();
	MyDList.DRemoveAt(1);
	MyDList.DPrintList();

	// Search test
	printf("\n");
	printf("Search 테스트---------------------------------\n");
	DListNode* Found = MyDList.DSearch(15);
	if (Found)
	{
		printf("15를 찾았습니다.\n");
	}
	else
	{
		printf("15가 없습니다.\n");
	}
	Found = MyDList.DSearch(999);
	if (Found)
	{
		printf("999를 찾았습니다.\n");
	}
	else
	{
		printf("999가 없습니다.\n");
	}


}
