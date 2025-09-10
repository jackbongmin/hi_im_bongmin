
#define _CRT_SECURE_NO_WARNINGS // ← 보라색 글씨는 매크로?
//#define _CRTDBG_MAP_ALLOC
//#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#include <crtdbg.h>
//소스파일

#include <iostream> //include : 포함시키다 / iostream을 포함시켜라 / iostream : 인풋 아웃풋 스트림 입출력 관련 정보가 담겨있는거
//#include <cstdio> // iostream이 아니더라도 사용 가능
#include <stdio.h> // stdio.h에 네임스페이스 추가한 래퍼
#include <time.h> // c 스타일 랜덤 시드값 설정할때
#include <random> // c++ 스타일 랜덤 쓸때 
#include "TestMath.h" //헤더를 선언하면 헤더에 있는 내용이 전부 선언됨
//#include "Practice.h"
#include "D0910.h"

int main() // 앤트리 포인트(코드가 시작되는곳) / main함수는 반드시 하나만 있어야함
{



	//// 0909 실습1
	//// 1. 가로 세로를 입력받아 배열을 생성하고 배열의 안을 0부터 1씩 증가하는 값으로 채우고 출력하기

	//int X = 0;
	//int Y = 0;
	//printf("가로 값을 입력하시오 : ");
	//std::cin >> X;

	//printf("세로 값을 입력하시오 : ");
	//std::cin >> Y;

	//if (X <= 0 || Y <= 0) 
	//{
	//	printf("가로/세로는 양수여야 합니다.\n");
	//	return 0;
	//}

	//const int XY = X * Y;
	//int* Number = new int[XY];

	//for (int i = 0; i < XY; i++)
	//{
	//	Number[i] = i;
	//}

	//for (int i = 0; i < XY; ++i)
	//{
	//	printf("%d ", Number[i]);
	//	if ((i + 1) % X == 0)
	//	{
	//		printf("\n"); 
	//	}
	//}
	//delete[] Number;

	//// 0909 실습2
	//// 2. 하이로우 수정하기
	////	- 게임이 종료되었을 때 이때까지 플레이어가 입력한 모든 수를 출력해서 보여주기

	//	printf("1 ~ 100 사이의 숫자를 맞추시오. \n");

	//	int InputNumber3 = 0;

	//	int Count3 = 0;

	//	srand(time(0));

	//	int RandomNumber3 = rand() % 100 + 1;

	//	const int ExitInput = -1;	
	//	const int StartSize = 1;
	//	int* Array4 = new int[StartSize];

	//	for (int i = 0; i < StartSize; i++)
	//	{
	//		Array4[i] = ExitInput;
	//	}
	//	int CurrentIndex = 0;
	//	int CurrentSize = StartSize;

	//	while (InputNumber3 != RandomNumber3)

	//	{
	//		printf("숫자를 입력하시오 :");
	//		std::cin >> InputNumber3;

	//		if (InputNumber3 > RandomNumber3)
	//		{
	//			printf("DOWN\n\n");
	//			Count3++;
	//		}
	//		else if (InputNumber3 < RandomNumber3)
	//		{
	//			printf("UP\n\n");
	//			Count3++;
	//		}
	//		else
	//		{
	//			printf("정답입니다.\n\n");
	//		}
	//		Array4[CurrentIndex] = InputNumber3;
	//		CurrentIndex++;

	//		if (CurrentIndex >= CurrentSize)
	//		{
	//			int* newArray = new int[CurrentSize + 1];
	//			for (int i = 0; i < CurrentSize; i++)
	//			{
	//				newArray[i] = Array4[i];
	//			}
	//			newArray[CurrentSize] = ExitInput;

	//			delete[] Array4;
	//			Array4 = newArray;
	//			CurrentSize++;
	//		}
	//	}
	//	if (Count3 <= 5)
	//	{
	//		printf("승리하였습니다.\n\n");
	//	}
	//	else
	//	{
	//		printf("승리하지 못했습니다.\n\n");
	//	}


	//	printf("입력된 데이터 : ");
	//	for (int i = 0; i < CurrentIndex; i++)
	//	{
	//		printf("%d ", Array4[i]);
	//	}
	//	printf("\n");

	//	delete[] Array4;
	//	Array4 = nullptr;


	// 0909 실습3
	// 3. 미로탈출게임 수정하기
	//	- 이동했을 때 일정확률(20%)로 전투가 발생한다.
	//  - 이동했을 때 일정확률(10%)로 Player HP가 회복된다.
	//	- 두 이벤트는 중복으로 발생하지 않는다.

	//D0910_p4();

	//D0910_String();
	//D0910_Parsing();


//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	return 0;
}
