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

	// 만들어진 노드들을 정리하기 위해 필요
	~DLinkedList();

	// 데이터를 리스트에 하나 추가하는 함수(리스트의 마지막에 추가)
	void DAdd(int32 InData);

	// 데이터를 특정 위치에 추가하는 함수(범위를 벗어나면 마지막에 추가)
	void DInsertAt(int32 InData, uint32 InPosition);

	// 데이터를 삭제하는 함수(InData와 같은 값을 가지고 노드를 삭제하는 함수. 중복 없음.)
	void DRemove(int32 InData);

	// 데이터를 삭제하는 함수(Position 번째의 데이터를 삭제하는 함수. 범위 벗어나면 에러만 출력.)
	void DRemoveAt(uint32 InPosition);

	// InData를 가진 노드를 찾아 리턴하는 함수(없으면 nullptr 리턴)
	DListNode* DSearch(int32 InData) const;

	// 리스트 내용을 출력하는 함수
	void DPrintList() const;

private:
	inline bool IsEmpty() const { return Head == nullptr; }

	// 리스트의 첫번째 노드
	DListNode* Head = nullptr;

	// 리스트의 마지막 노드
	DListNode* Tail = nullptr;

	// 리스트에 있는 노드의 수
	uint32 Size = 0;

};

