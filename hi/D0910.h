#pragma once

//전일 실습 4

//미로 탈출 실행용 코드
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
//// 미로 크기가 고정이었을때의 코드
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
///// 미로를 출력하는 함수
//void PrintMaze(int PlayerX, int PlayerY);
//
///// 플레이어의 시작위치를 받아오는 함수
//void FindStartPosition(int& OutStartX, int& OutStartY);
//
///// 플레이어의 현재 위치에서 가능한 이동 경로를 출력하고 모든 경로를 합친 비트 플레그를 반환합니다.
//int PrintAvailableMoves(int PlayerX, int PlayerY);
//
///// 해당위치가 벽인지 확인하는 함수
//bool IsWall(int X, int Y);
//
///// 해당위치가 도착점인지 확인하는 함수
//bool IsEnd(int X, int Y);
//
///// 입력처리를 하는 함수, 최종적으로 결정된 이동 방향 리턴
//MoveDirection GetMoveInput(int MoveFlags);
//




// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

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