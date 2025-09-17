#pragma once
#include <string>

//  ����ü�� �ش��� �����Ѵ�.

struct Enemy
{
	std::string Name = "���";
	float Health = 100.0f;
	float AttackPower = 10.0f;
	int DropGold = 100;

	// �⺻ ������.
	Enemy()
	{
		// ������ ���� �ƴ� ����� �ʱ�ȭ �Ǿ�� �� �� ���
		DropGold = rand() % 100 + 50;	//50 ~ 150 �������� ������
	}

	Enemy(std::string _Name)
	{
		Name = _Name;
	}

	Enemy(float Modifier)
	{
		Health = Modifier * 10.0f;
		AttackPower = Modifier * 5.0f;
		DropGold = static_cast<int>(Modifier * 100.0f);


	}

	Enemy(std::string _Name, float _Health, float _AttackPower, int _DropGold)
		:Name(_Name), Health(_Health), AttackPower(_AttackPower), DropGold(_DropGold)	// ���鶧���� ���� ����ä�� ���������.
	{
		// ���⼭ ���� ���� ����� ���� ���� ���� ��(�׷��� ����� �ʿ��� �͵��� ���ʿ� �ؾ���)
	/*	Name = _Name;
		Health = _Health;
		AttackPower = _AttackPower;
		DropGold = _DropGold;*/
	}


	// + �����ڸ� ���� ���ڴ�.
	// +�� ���׿�����(+�� ���ʰ� �������� ����ϴµ� ����Ѵ�.)
	// ���� : �ڱ��ڽ�
	// ������ : other
	// ��� : ���� ��
	Enemy operator+(const Enemy& other) const	// �������� ���� const�� �� �Լ����� �ɹ� ������ ������ ���ϰڴٴ� �ǹ�
	{
		// �̸��� ���ʰ��� ���
		// Health�� ��ġ��
		// AttackPower�� ���ʴ� 70%���
		// DropGold�� ��ġ��
		return Enemy(
			Name + "(��ü)",
			Health + other.Health,
			AttackPower * 0.7f + other.AttackPower*0.7f,
			DropGold + other.DropGold);
	}


	/*
	���� �ǽ� 1
	Enemy -������ �����ε��ϱ�
		���ʿ� �ִ� �Ϳ��� �������� �� ������ ����
	*/
	Enemy operator-(const Enemy& other) const
	{
		return Enemy(
			Name + "(��ü-)",
			Health - other.Health * 0.5f,
			AttackPower - other.AttackPower * 0.5f,
			DropGold - other.DropGold * 0.5f);
	}


	/*
	���� �ǽ� 2
	Enemy *������ �����ε��ϱ�
		������ floatŸ��
		Enemy operator*(float Multiplier) const { return };
	*/

	Enemy operator*(float Multiplier) const
	{
		return Enemy(
			Name + "(��ȭ)",
			Health * Multiplier,
			AttackPower * Multiplier,
			DropGold * Multiplier);
	}


	/*
	���� �ǽ� 3
	Enemy *= ������ �����ε��ϱ�
		Enemy& operator*=(float Multiplier) { return };
	*/


};

struct Weapon
{
	std::string Name = "����";
	std::string Desc = "���� ��� �̾߱�";
	float AttackPower = 10.0f;
	int Price = 100;

	//Weapon()		// ��� �ڵ����� ���� / �׷��� �ȳ־ ��!
	//{
	//}
};

void D0912_Struct();

void D0912_OperatorOverLoading();

/// <summary>
/// �� ���� ����ϴ� �Լ�
/// </summary>
/// <param name="pEnemy">����� ��(�б� ����)</param>
void PrintEnemy(const Enemy* pEnemy);	// pEnemy�� �б� ����

/*
9 / 12 ��������
��ġ ǥ���� ����ü Position �����
## �䱸����
	����ü �̸��� Position���� �Ѵ�.
	��� ������ int x, int y�� ������.
	�� ��� ������ �⺻���� 0�̾�� �Ѵ�.
	�� ���� ���� ���� �޾Ƽ� ��� ������ �Ҵ��ϴ� �����ڸ� �����.
	+ �����ڸ� �����ε��Ͽ� �� Position ��ü�� ������ ��, ������ ������� ���� ����� ���� ���ο� Position ��ü�� �����ǵ��� �Ѵ�.
	�����ڵ� �����ε��Ͽ� �� Position ��ü�� ���� ��, ������ ������� �� ����� ���� ���ο� Position ��ü�� �����ǵ��� �Ѵ�.
*/

struct Position1
{
	int x = 0;
	int y = 0;

	Position1(int i, int j)
	{
		x = i;
		y = j;
	}

	Position1 operator+(const Position1& other) const
	{
		return Position1(x + other.x, y + other.y);
	}

	Position1 operator-(const Position1& other) const
	{
		return Position1(x - other.x, y - other.y);
	}

};

////�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//enum MazeTile
//{
//	Path = 0,
//	Wall = 1,
//	Start = 2,
//	End = 3
//};
//
//enum MoveDirection
//{
//	DirNone = 0,
//	DirUp = 1 << 0,
//	DirDown = 1 << 1,
//	DirLeft = 1 << 2,
//	DirRight = 1 << 3
//};
//
//
//const int MazeHeight = 10;
//const int MazeWidth = 20;
//
//const int Maze[MazeHeight][MazeWidth] =
//{
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
//	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
//	{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
//
//
//void D0912_P1();
//
//// �̷ι���(���� ����)
//void D0912_P2_1();
//
///// �̷θ� ����ϴ� �Լ�
//void PrintMaze1(int PlayerX, int PlayerY);
//
///// �÷��̾��� ������ġ�� �޾ƿ��� �Լ�
//void FindStartPosition1(int& OutStartX, int& OutStartY);
//
///// �÷��̾��� ���� ��ġ���� ������ �̵� ��θ� ����ϰ� ��� ��θ� ��ģ ��Ʈ �÷��׸� ��ȯ�մϴ�.
//int PrintAvailableMoves1(int PlayerX, int PlayerY);
//
///// �ش���ġ�� ������ Ȯ���ϴ� �Լ�
//bool IsWall1(int X, int Y);
//
///// �ش���ġ�� ���������� Ȯ���ϴ� �Լ�
//bool IsEnd1(int X, int Y);
//
///// �Է�ó���� �ϴ� �Լ�, ���������� ������ �̵� ���� ����
//MoveDirection GetMoveInput1(int MoveFlags);
//
//void BattleStart(int& PlayerHP);
//
//int PlayerAttack();
//
//int ComputerAttack();
//
//void HPHeal(int& PlayerHP);
//

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
//struct MazePosition
//{
//	int x = 0;
//	int y = 0;
//
//	MazePosition(){}
//	MazePosition(int i, int j)
//	{
//		x = i;
//		y = j;
//	}
//};

//struct Player
//{
//	MazePosition pos;
//	int HP = 100;
//
//	Player(int StartX, int StartY, int HPValue)
//	{
//		pos.x = StartX;
//		pos.y = StartY;
//		HP = HPValue;
//	}
//};
//
//// �̷ι���(����ü Ȱ��)
//void D0912_P2_2();
//
///// �̷θ� ����ϴ� �Լ�
//void PrintMaze2(int PlayerX, int PlayerY);
//
///// �÷��̾��� ������ġ�� �޾ƿ��� �Լ�
//void FindStartPosition2(int& OutStartX, int& OutStartY);
//
///// �÷��̾��� ���� ��ġ���� ������ �̵� ��θ� ����ϰ� ��� ��θ� ��ģ ��Ʈ �÷��׸� ��ȯ�մϴ�.
//int PrintAvailableMoves2(int PlayerX, int PlayerY);
//
///// �ش���ġ�� ������ Ȯ���ϴ� �Լ�
//bool IsWall2(int X, int Y);
//
///// �ش���ġ�� ���������� Ȯ���ϴ� �Լ�
//bool IsEnd2(int X, int Y);
//
///// �Է�ó���� �ϴ� �Լ�, ���������� ������ �̵� ���� ����
//MoveDirection GetMoveInput2(int MoveFlags);
//
//void BattleStart2(Player& Jongmin);
//
//int PlayerAttack2();
//
//int ComputerAttack2();
//
//void HPHeal2(int& PlayerHP);
