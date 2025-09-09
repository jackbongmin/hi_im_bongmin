#pragma once

/*
1. Ư�������ȿ� ������ ���� �����ϴ� �Լ�
	- int �Ķ���� 2��
	- int ����

*/

// �ǽ�1
int RandomNumber1(int Number1, int Number2);

// �ǽ�2
void Age(int Number1);

// �ǽ�3
float Radius(float Number1);

// �ǽ� 4
bool Number4_1(int Number1);

// �ǽ� 5
int Score(int Number1);

// �ǽ� 6

enum ItemList
{
	Sword  = 1 << 0,
	Shield = 1 << 1,
	Arnmor = 1 << 2
};

void SetItem(int Inventory, ItemList Item);
void UnSetItem(int Inventory, ItemList Item);
void ToggleItem(int Inventory, ItemList Item);

// �ǽ� 7
int Pyramid(int Number1);

// �ǽ� 8
template <typename M>
M Min(M Number1, M Number2)
{
	if (Number1 > Number2)
	{
		printf("�� �� ���� ���ڴ� %d�Դϴ�.\n", Number2);
		return 0;
	}
	else
	{
		printf("�� �� ���� ���ڴ� %d�Դϴ�.\n", Number1);
		return 0;
	}
}

// �ǽ� 9
template <typename MM>
MM Max(MM Number1, MM Number2)
{
	if (Number1 > Number2)
	{
		printf("�� �� ū ���ڴ� %d�Դϴ�.\n", Number1);
		return 0;
	}
	else
	{
		printf("�� �� ū ���ڴ� %d�Դϴ�.\n", Number2);
		return 0;
	}
}

// �ǽ� 10

template <typename C1>
C1 Clamp1(C1 Number1, C1 Number2, C1 Number3)
{
	if (Number1 < Number2)
	{
		printf("min�� %d�Դϴ�.\n", Number2);
		return 0;
	}
	else if (Number1 > Number3)
	{
		printf("max�� %d�Դϴ�.\n", Number3);
		return 0;
	}
	else
	{
		printf("%d�� value�Դϴ�.\n", Number1);
		return 0;
	}
}

// �ǽ� 11

int Factorial(int Number1);


//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//
///*
//�ָ� �ǽ�1
//3�����Ķ���͸� �޾� ��հ��� �����ϴ� �Լ� �����
//*/
//
//float Average(float Number1, float Number2, float Number3);
//
///*
//�ָ� �ǽ�2
//������ ������ �Է� �޾� ���ΰ� ���ϴ� �Լ� �����
//*/
//
//float SalePrice(float Number1, float Number2);
//
//
///*
//�ָ� �ǽ�3
//�ֻ����� ���� ����� �����ϴ� �Լ� �����
//*/
//
//int Dice(int Number1);
//
///*
//�ָ� �ǽ�4
//������ �ָ� ����(A~F)�� �ִ� �Լ� �����
//*/
//
//int Score1(int Number1);
//
///*
//�ָ� �ǽ�5
//���ø� �Լ��� Clamp �Լ� �����ϱ�
//*/
//
//template <typename C>
//C Clamp(C Number1, C Number2, C Number3)
//{
//	if (Number1 < Number2)
//	{
//		printf("min�� %d�Դϴ�.\n", Number2);
//		return 0;
//	}
//	else if (Number1 > Number3)
//	{
//		printf("max�� %d�Դϴ�.\n", Number3);
//		return 0;
//	}
//	else
//	{
//		printf("%d�� value�Դϴ�.\n", Number1);
//		return 0;
//	}
//}

///*
//�ָ� �ǽ�(��ȭ)1
//�ڸ��� �и��ϱ�(�Է��� �ڸ� �� ���� ����)
//	- �� �ڸ��� ���� ���ؼ� ����ϱ�
//*/
//int TotalSum(int Number1);
//
///*
//�ָ� �ǽ�(��ȭ)2
//��� �Լ��� �̿��Ͽ� 10������ �Է¹޾� 2������ ����ϴ� �Լ� �����
//*/
//void DecToBin(int Number1);
//
///*
//�ָ� �ǽ�(��ȭ)3
//���� �ӽ� ���� �����
//	- ���� �ݾ� 10000
//	- ���ǿ� ������  �ּ� 100 �����ؾ� ��. ���� �����ݾ��� 100 ������ ��� ���� ����.
//	- ���� ���� 3���� ������ 50��� ���� �޴´�.
//	- ���� 777�̸� 10000�� ����
//*/
//void Spin(int Number1, int Number2, int Number3);
//int Result(int Number1, int Number2, int Number3, int Number4);
//
//
//
///*
//�ָ� �ǽ�(��ȭ)4
//�÷��̾�� ���� ���� ���� �����
//	- HP�� 100���� ����
//	- ������ �� �� ���濡�� 5~15�� �������� �ش�.
//	- 10%�� Ȯ���� ũ��Ƽ���� �߻��� 2���� �������� �ش�.
//	- ������ HP�� 0 ���ϰ� �Ǹ� �¸��Ѵ�.
//*/
//int PlayerAttack(int Number1);
//int ComputerAttack(int Number1);
//
//
//
///*
//�ָ� �ǽ�(��ȭ)5
//���� ��� �����
//	- ���� �ݾ� 10000
//	- ���ǿ� ������ �ּ� 100 �����ؾ� ��. ���� �����ݾ��� 100 ������ ��� ���� ����.
//	- ������ A~K������ Ʈ���� ī�� �� 2���� �ߺ����� �����ϰ� ��Ŀ ī�尡 �߰��ȴ�.
//	- �÷��̾�� ������ ī�� �� ������ �����Ѵ�.
//	- ���� �÷��̾ ��Ŀ�� ���ִٸ� �÷��̾��� �¸�. ���� �ݾ��� 2�踦 �޴´�.
//	- �÷��̾ ��Ŀ�� ���� ���ߴٸ� ���� ������ �����ϰų� ���� �ݾ��� 2�踦 �߰��� �����ϰ� �ѹ� �� ������ �� �ִ�.
//*/
//
//void Card(int Number1);
//
//// void Shuffle(int Number1, int Number2);
//
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//�ָ��ǽ�5 Ǯ��

// ���ø�
template<typename T>
T Clamp1(const T& Value, const T& Min, const T& Max)
{
	if (Value < Min)
		return Min;
	else if (Value > Max)
		return Max;
	else
		return Value;
}

// �ָ��ǽ�(��ȭ)5 Ǯ��

void Practice0905_02_05();


void Shuffle(int Array[], int Length);
// = void Shuffle(int* Array, int Length);	// �Ϲ������� �̷��� ����ϴ°��� ����


//void Day0908_Ref();
//
//void Swap(int Array[], int Size);
//
//void MazeMap(int Maze2[10][20], int PlayerY, int PlayerX);
//
////�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//// 25.09.09
//
//
//// ���ܽǽ�3
//
//void TestPointer(int* pInt, float* pFloat);
//
//
//void d0909_2();
//
//void d0909_DynamicAllocation();

//0908 �ǽ�2 Ǯ��
void Reverse(int* Array, int Size);
void p2();

//0908 �ǽ�3 Ǯ��
void p3();

//0908 �ǽ�4 Ǯ��

// 0909 �ǽ�1
// 1. ���� ���θ� �Է¹޾� �迭�� �����ϰ� �迭�� ���� 0���� 1�� �����ϴ� ������ ä��� ����ϱ�
void d0909_p1();

// 0909 �ǽ�2
// 2. ���̷ο� �����ϱ�
//	- ������ ����Ǿ��� �� �̶����� �÷��̾ �Է��� ��� ���� ����ؼ� �����ֱ�



// 0909 �ǽ�3
// 3. �̷�Ż����� �����ϱ�
//	- �̵����� �� ����Ȯ��(20%)�� ������ �߻��Ѵ�.
//  - �̵����� �� ����Ȯ��(10%)�� Player HP�� ȸ���ȴ�.
//	- �� �̺�Ʈ�� �ߺ����� �߻����� �ʴ´�.

void d0909_p3();

enum MazeTile
{
	Path = 0,
	Wall = 1,
	Start = 2,
	End = 3
};

enum MoveDirection
{
	DirNone = 0,
	DirUp = 1 << 0,
	DirDown = 1 << 1,
	DirLeft = 1 << 2,
	DirRight = 1 << 3
};

const int MazeHeight = 10;
const int MazeWidth = 20;

int Maze[MazeHeight][MazeWidth] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
	{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
	{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/// �̷θ� ����ϴ� �Լ�
void PrintMaze(int PlayerX, int PlayerY);

/// �÷��̾��� ������ġ�� �޾ƿ��� �Լ�
void FindStartPosition(int& OutStartX, int& OutStartY);

/// �÷��̾��� ���� ��ġ���� ������ �̵� ��θ� ����ϰ� ��� ��θ� ��ģ ��Ʈ �÷��׸� ��ȯ�մϴ�.
int PrintAvailableMoves(int PlayerX, int PlayerY);

/// �ش���ġ�� ������ Ȯ���ϴ� �Լ�
bool IsWall(int X, int Y);

/// �ش���ġ�� ���������� Ȯ���ϴ� �Լ�
bool IsEnd(int X, int Y);

/// �Է�ó���� �ϴ� �Լ�, ���������� ������ �̵� ���� ����
MoveDirection GetMoveInput(int MoveFlags);


