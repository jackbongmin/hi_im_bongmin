#pragma once
#include <cstdint>

using int32 = int32_t;
using uint32 = uint32_t;

struct DListNode
{
	int32 Data = 0;
	DListNode* Next = nullptr;
	DListNode* Prev = nullptr;

	DListNode() = default;
	DListNode(int32 InData) : Data(InData) {};

};

class DLinkedList
{
public:
	DLinkedList() = default;

	// ������� ������ �����ϱ� ���� �ʿ�
	~DLinkedList();

	// �����͸� ����Ʈ�� �ϳ� �߰��ϴ� �Լ�(����Ʈ�� �������� �߰�)
	void DAdd(int32 InData);

	// �����͸� Ư�� ��ġ�� �߰��ϴ� �Լ�(������ ����� �������� �߰�)
	void DInsertAt(int32 InData, uint32 InPosition);

	// �����͸� �����ϴ� �Լ�(InData�� ���� ���� ������ ��带 �����ϴ� �Լ�. �ߺ� ����.)
	void DRemove(int32 InData);

	// �����͸� �����ϴ� �Լ�(Position ��°�� �����͸� �����ϴ� �Լ�. ���� ����� ������ ���.)
	void DRemoveAt(uint32 InPosition);

	// InData�� ���� ��带 ã�� �����ϴ� �Լ�(������ nullptr ����)
	DListNode* DSearch(int32 InData) const;

	// ����Ʈ ������ ����ϴ� �Լ�
	void DPrintList() const;

private:
	inline bool IsEmpty() const { return Head == nullptr; }

	// ����Ʈ�� ù��° ���
	DListNode* Head = nullptr;

	// ����Ʈ�� ������ ���
	DListNode* Tail = nullptr;

	// ����Ʈ�� �ִ� ����� ��
	uint32 Size = 0;

};

