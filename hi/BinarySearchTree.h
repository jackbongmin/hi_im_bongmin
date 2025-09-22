#pragma once

struct TreeNode
{
	int Key = 0;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;

	TreeNode() = default;
	TreeNode(int InKey) : Key(InKey) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree() = default;
	~BinarySearchTree();

	void Insert(int InKey);
	void Delete(int InKey);
	TreeNode* Search(int InKey);

	void PrintPreOrder() const;	// ���� ��ȸ
	void PrintInOrder();	// ���� ��ȸ
	void PrintPoseOrder();// ���� ��ȸ

	inline bool IsEmpty() const { return Root == nullptr; }

private:
	TreeNode* Root = nullptr;

	TreeNode* InsertNode(TreeNode* InNode, int InKey);
	TreeNode* DeleteNode(TreeNode* InNode, int InKey);
	TreeNode* SearchNode(TreeNode* InNode, int InKey);
	TreeNode* FindMinNode(TreeNode* InNode);	// InNode�� ��Ʈ���ϴ� ����Ʈ������ ���� ���� Ű�� ������ ��带 ã�� �Լ�

	void PreOrderTraversal(const TreeNode* InNode) const;
	void InOrderTraversal(TreeNode* InNode);
	void PostOrderTraversal(TreeNode* InNode);

	void DestroyTree(TreeNode* InNode);
};

