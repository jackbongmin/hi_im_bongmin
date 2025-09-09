#pragma once

/*
1. 특정범위안에 랜덤한 수를 리턴하는 함수
	- int 파라메터 2개
	- int 리턴

*/

// 실습1
int RandomNumber1(int Number1, int Number2);

// 실습2
void Age(int Number1);

// 실습3
float Radius(float Number1);

// 실습 4
bool Number4_1(int Number1);

// 실습 5
int Score(int Number1);

// 실습 6

enum ItemList
{
	Sword  = 1 << 0,
	Shield = 1 << 1,
	Arnmor = 1 << 2
};

void SetItem(int Inventory, ItemList Item);
void UnSetItem(int Inventory, ItemList Item);
void ToggleItem(int Inventory, ItemList Item);

// 실습 7
int Pyramid(int Number1);

// 실습 8
template <typename M>
M Min(M Number1, M Number2)
{
	if (Number1 > Number2)
	{
		printf("둘 중 작은 숫자는 %d입니다.\n", Number2);
		return 0;
	}
	else
	{
		printf("둘 중 작은 숫자는 %d입니다.\n", Number1);
		return 0;
	}
}

// 실습 9
template <typename MM>
MM Max(MM Number1, MM Number2)
{
	if (Number1 > Number2)
	{
		printf("둘 중 큰 숫자는 %d입니다.\n", Number1);
		return 0;
	}
	else
	{
		printf("둘 중 큰 숫자는 %d입니다.\n", Number2);
		return 0;
	}
}

// 실습 10

template <typename C1>
C1 Clamp1(C1 Number1, C1 Number2, C1 Number3)
{
	if (Number1 < Number2)
	{
		printf("min은 %d입니다.\n", Number2);
		return 0;
	}
	else if (Number1 > Number3)
	{
		printf("max은 %d입니다.\n", Number3);
		return 0;
	}
	else
	{
		printf("%d은 value입니다.\n", Number1);
		return 0;
	}
}

// 실습 11

int Factorial(int Number1);


//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

/*
주말 실습1
3개의파라메터를 받아 평균값을 리턴하는 함수 만들기
*/

float Average(float Number1, float Number2, float Number3);

/*
주말 실습2
정가와 할인율 입력 받아 할인가 구하는 함수 만들기
*/

float SalePrice(float Number1, float Number2);


/*
주말 실습3
주사위를 굴린 결과를 리턴하는 함수 만들기
*/

int Dice(int Number1);

/*
주말 실습4
점수를 주면 성적(A~F)를 주는 함수 만들기
*/

int Score1(int Number1);

/*
주말 실습5
템플릿 함수로 Clamp 함수 구현하기
*/

template <typename C>
C Clamp(C Number1, C Number2, C Number3)
{
	if (Number1 < Number2)
	{
		printf("min은 %d입니다.\n", Number2);
		return 0;
	}
	else if (Number1 > Number3)
	{
		printf("max은 %d입니다.\n", Number3);
		return 0;
	}
	else
	{
		printf("%d은 value입니다.\n", Number1);
		return 0;
	}
}

/*
주말 실습(심화)1
자리수 분리하기(입력은 자리 수 제한 없음)
	- 각 자리의 수를 합해서 출력하기
*/
int TotalSum(int Number1);

/*
주말 실습(심화)2
재귀 함수를 이용하여 10진수를 입력받아 2진수로 출력하는 함수 만들기
*/
void DecToBin(int Number1);

/*
주말 실습(심화)3
슬롯 머신 게임 만들기
	- 시작 금액 10000
	- 한판에 무조건  최소 100 배팅해야 함. 만약 소지금액이 100 이하일 경우 게임 종료.
	- 같은 숫자 3개가 나오면 50배로 돌려 받는다.
	- 만약 777이면 10000배 받음
*/
void Spin(int Number1, int Number2, int Number3);
int Result(int Number1, int Number2, int Number3, int Number4);



/*
주말 실습(심화)4
플레이어와 적의 턴제 전투 만들기
	- HP는 100으로 시작
	- 공격을 할 때 상대방에게 5~15의 데미지를 준다.
	- 10%의 확률로 크리티컬이 발생해 2배의 데미지를 준다.
	- 상대방의 HP가 0 이하가 되면 승리한다.
*/
int PlayerAttack(int Number1);
int ComputerAttack(int Number1);



/*
주말 실습(심화)5
도둑 잡기 만들기
	- 시작 금액 10000
	- 한판에 무조건 최소 100 배팅해야 함. 만약 소지금액이 100 이하일 경우 게임 종료.
	- 딜러는 A~K까지의 트럼프 카드 중 2장을 중복없이 선택하고 조커 카드가 추가된다.
	- 플레이어는 딜러의 카드 중 한장을 선택한다.
	- 만약 플레이어가 조커를 뽑있다면 플레이어의 승리. 배팅 금액의 2배를 받는다.
	- 플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.
*/

void Card(int Number1);

// void Shuffle(int Number1, int Number2);

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//주말실습5 풀이

// 탬플릿
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

// 주말실습(심화)5 풀이

void Practice0905_02_05();


void Shuffle(int Array[], int Length);
// = void Shuffle(int* Array, int Length);	// 일반적으로 이렇게 사용하는것이 보통


void Day0908_Ref();

void Swap(int Array[], int Size);

void MazeMap(int Maze[10][20], int PlayerY, int PlayerX);

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 25.09.09


// 간단실습3

void TestPointer(int* pInt, float* pFloat);


void d0909_2();

void d0909_DynamicAllocation();