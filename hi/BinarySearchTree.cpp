#include "BinarySearchTree.h"
#include <cstdio>

BinarySearchTree::~BinarySearchTree()
{
    DestroyTree(Root);
}

void BinarySearchTree::Insert(int InKey)
{
    Root = InsertNode(Root, InKey);
}

void BinarySearchTree::Delete(int InKey)
{
    Root = DeleteNode(Root, InKey);
}

TreeNode* BinarySearchTree::Search(int InKey)
{
    return SearchNode(Root, InKey);
}

void BinarySearchTree::PrintPreOrder() const
{
    printf("PreOrder : ");
    PreOrderTraversal(Root);
    printf("\n");
}

void BinarySearchTree::PrintInOrder()
{
}

void BinarySearchTree::PrintPoseOrder()
{
}

TreeNode* BinarySearchTree::InsertNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return new TreeNode(InKey); // �����Ʈ�� null�̸� �װ��� �� ��� ���� ����ǰ� �ϱ�
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = InsertNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = InsertNode(InNode->Right, InKey);
    }
    //else
    //{
    //    // Ʈ�������� Ű�� �ߺ��Ǹ� �ȵ�.
    //    // �ߺ��� Ű�� ����
    //}

    return InNode;
}

TreeNode* BinarySearchTree::DeleteNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return InNode;
    }

    if (InKey < InNode->Key)
    {
        InNode->Left = DeleteNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key)
    {
        InNode->Right = DeleteNode(InNode->Right, InKey);
    }
    else
    {
        // ������ ��带 ã�Ҵ�.
        if (InNode->Left == nullptr)
        {
            // ���� �ڽ��� ����.
        }
        else if (InNode->Right == nullptr)
        {
            // ������ �ڽĸ� ����.
            TreeNode* Temp = InNode->Left;
            delete InNode;
            return Temp;
        }

        // �� �ڽ��� ��� �ִ�. -> ������ ����Ʈ���� �ּҰ����� ��ü
        TreeNode* Temp = FindMinNode(InNode->Right);
        InNode->Key = Temp->Key;
        InNode->Right = DeleteNode(InNode->Right, Temp->Key);
    }
    return InNode;
}

TreeNode* BinarySearchTree::SearchNode(TreeNode* InNode, int InKey)
{
    if (InNode == nullptr)
    {
        return nullptr; // ��ã�Ҵ�.
    }

    if (InKey < InNode->Key)
    {
        return SearchNode(InNode->Left, InKey);     // ã�� ��
    }
    else if (InKey > InNode->Key)
    {
            return SearchNode(InNode->Right, InKey);    // ã�� ��
    }
    else
    {
        return InNode;  // ã�Ҵ�.
    }

}   
TreeNode* BinarySearchTree::FindMinNode(TreeNode* InNode)
{
    while (InNode != nullptr && InNode->Left != nullptr)
    {
        InNode = InNode->Left;
    }
    return InNode;
}

void BinarySearchTree::PreOrderTraversal(const TreeNode* InNode) const
{
    if (InNode != nullptr)
    {
        printf("%d ", InNode->Key);
        PreOrderTraversal(InNode->Left);
        PreOrderTraversal(InNode->Left);
    }
}

void BinarySearchTree::InOrderTraversal(TreeNode* InNode)
{
}

void BinarySearchTree::PostOrderTraversal(TreeNode* InNode)
{
}

void BinarySearchTree::DestroyTree(TreeNode* InNode)
{
    if (InNode != nullptr)
    {
        DestroyTree(InNode->Left);  // ���� ����Ʈ�� �����ϰ�
        DestroyTree(InNode->Right); // ������ ����Ʈ�� �����ϰ� 
        delete InNode;  // ���� ������(������ȸ�ϸ� �����ϱ�)
    }
}
