#pragma once
#include <string>

//  구조체는 해더에 선언한다.

struct Enemy
{
	std::string Name = "고블린";
	float Health = 100.0f;
	float AttackPower = 10.0f;
	int DropGold = 100;

	// 기본 생성자.
	Enemy()
	{
		// 정해진 값이 아닌 값들로 초기화 되어야 할 때 사용
		DropGold = rand() % 100 + 50;	//50 ~ 150 랜덤으로 생성됨
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
		:Name(_Name), Health(_Health), AttackPower(_AttackPower), DropGold(_DropGold)	// 만들때부터 값이 박힌채로 만들어진다.
	{
		// 여기서 쓰는 것은 만들어 놓고 고쳐 쓰는 것(그래서 계산이 필요한 것들은 이쪽에 해야함)
	/*	Name = _Name;
		Health = _Health;
		AttackPower = _AttackPower;
		DropGold = _DropGold;*/
	}


	// + 연산자를 새로 쓰겠다.
	// +는 이항연산자(+의 왼쪽과 오른쪽을 계산하는데 사용한다.)
	// 왼쪽 : 자기자신
	// 오른쪽 : other
	// 결과 : 리턴 값
	Enemy operator+(const Enemy& other) const	// 마지막에 붙은 const는 이 함수에서 맴버 변수의 수정을 안하겠다는 의미
	{
		// 이름은 왼쪽것을 사용
		// Health는 합치고
		// AttackPower는 양쪽다 70%사용
		// DropGold는 합치기
		return Enemy(
			Name + "(합체)",
			Health + other.Health,
			AttackPower * 0.7f + other.AttackPower*0.7f,
			DropGold + other.DropGold);
	}


	/*
	간단 실습 1
	Enemy -연산자 오버로딩하기
		왼쪽에 있는 것에서 오른쪽의 값 절반을 빼기
	*/
	Enemy operator-(const Enemy& other) const
	{
		return Enemy(
			Name + "(합체-)",
			Health - other.Health * 0.5f,
			AttackPower - other.AttackPower * 0.5f,
			DropGold - other.DropGold * 0.5f);
	}


	/*
	간단 실습 2
	Enemy *연산자 오버로딩하기
		왼쪽은 float타입
		Enemy operator*(float Multiplier) const { return };
	*/

	Enemy operator*(float Multiplier) const
	{
		return Enemy(
			Name + "(진화)",
			Health * Multiplier,
			AttackPower * Multiplier,
			DropGold * Multiplier);
	}


	/*
	간단 실습 3
	Enemy *= 연산자 오버로딩하기
		Enemy& operator*=(float Multiplier) { return };
	*/


};

struct Weapon
{
	std::string Name = "무기";
	std::string Desc = "무기 배경 이야기";
	float AttackPower = 10.0f;
	int Price = 100;

	//Weapon()		// 없어도 자동으로 생김 / 그래서 안넣어도 됨!
	//{
	//}
};

void D0912_Struct();

void D0912_OperatorOverLoading();

/// <summary>
/// 적 정보 출력하는 함수
/// </summary>
/// <param name="pEnemy">출력할 적(읽기 전용)</param>
void PrintEnemy(const Enemy* pEnemy);	// pEnemy는 읽기 전용

/*
9 / 12 연습문제
위치 표현용 구조체 Position 만들기
## 요구사항
	구조체 이름은 Position으로 한다.
	멤버 변수로 int x, int y를 가진다.
	두 멤버 변수는 기본값이 0이어야 한다.
	두 개의 정수 값을 받아서 멤버 변수에 할당하는 생성자를 만든다.
	+ 연산자를 오버로딩하여 두 Position 객체를 더했을 때, 각각의 멤버끼리 더한 결과를 갖는 새로운 Position 객체가 생성되도록 한다.
	연산자도 오버로딩하여 두 Position 객체를 뺐을 때, 각각의 멤버끼리 뺀 결과를 갖는 새로운 Position 객체가 생성되도록 한다.
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

////ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
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
//// 미로문제(몬스터 만남)
//void D0912_P2_1();
//
///// 미로를 출력하는 함수
//void PrintMaze1(int PlayerX, int PlayerY);
//
///// 플레이어의 시작위치를 받아오는 함수
//void FindStartPosition1(int& OutStartX, int& OutStartY);
//
///// 플레이어의 현재 위치에서 가능한 이동 경로를 출력하고 모든 경로를 합친 비트 플레그를 반환합니다.
//int PrintAvailableMoves1(int PlayerX, int PlayerY);
//
///// 해당위치가 벽인지 확인하는 함수
//bool IsWall1(int X, int Y);
//
///// 해당위치가 도착점인지 확인하는 함수
//bool IsEnd1(int X, int Y);
//
///// 입력처리를 하는 함수, 최종적으로 결정된 이동 방향 리턴
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

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
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
//// 미로문제(구조체 활용)
//void D0912_P2_2();
//
///// 미로를 출력하는 함수
//void PrintMaze2(int PlayerX, int PlayerY);
//
///// 플레이어의 시작위치를 받아오는 함수
//void FindStartPosition2(int& OutStartX, int& OutStartY);
//
///// 플레이어의 현재 위치에서 가능한 이동 경로를 출력하고 모든 경로를 합친 비트 플레그를 반환합니다.
//int PrintAvailableMoves2(int PlayerX, int PlayerY);
//
///// 해당위치가 벽인지 확인하는 함수
//bool IsWall2(int X, int Y);
//
///// 해당위치가 도착점인지 확인하는 함수
//bool IsEnd2(int X, int Y);
//
///// 입력처리를 하는 함수, 최종적으로 결정된 이동 방향 리턴
//MoveDirection GetMoveInput2(int MoveFlags);
//
//void BattleStart2(Player& Jongmin);
//
//int PlayerAttack2();
//
//int ComputerAttack2();
//
//void HPHeal2(int& PlayerHP);
