#pragma once

//���� �ǽ� 4

//�̷� Ż�� ����� �ڵ�
void D0910_p4();

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
//// �̷� ũ�Ⱑ �����̾������� �ڵ�
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
//
//
//
//
///// �̷θ� ����ϴ� �Լ�
//void PrintMaze(int PlayerX, int PlayerY);
//
///// �÷��̾��� ������ġ�� �޾ƿ��� �Լ�
//void FindStartPosition(int& OutStartX, int& OutStartY);
//
///// �÷��̾��� ���� ��ġ���� ������ �̵� ��θ� ����ϰ� ��� ��θ� ��ģ ��Ʈ �÷��׸� ��ȯ�մϴ�.
//int PrintAvailableMoves(int PlayerX, int PlayerY);
//
///// �ش���ġ�� ������ Ȯ���ϴ� �Լ�
//bool IsWall(int X, int Y);
//
///// �ش���ġ�� ���������� Ȯ���ϴ� �Լ�
//bool IsEnd(int X, int Y);
//
///// �Է�ó���� �ϴ� �Լ�, ���������� ������ �̵� ���� ����
//MoveDirection GetMoveInput(int MoveFlags);
//




// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

void D0910_String();

int FindCharIndex(const char* TargetString, const char TargetCharacter);

int MyStringLenth(const char* Target);

void MyStringCopy(const char* Source, char* Destination);

void MyStingCat(char* Source, const char* Destination);

int MyStringCompare(const char* String1, const char* String2);

int MyAtoI(const char* Source);

float MyAtoF(const char* Source);

void D0910_Parsing();

void SimplerParser(char* Source, const char Delimiter);

void ReadFile();

void TestString();

void D0910_P2();