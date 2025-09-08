
#define _CRT_SECURE_NO_WARNINGS // ← 보라색 글씨는 매크로?

//소스파일

#include <iostream> //include : 포함시키다 / iostream을 포함시켜라 / iostream : 인풋 아웃풋 스트림 입출력 관련 정보가 담겨있는거
//#include <cstdio> // iostream이 아니더라도 사용 가능
#include <stdio.h> // stdio.h에 네임스페이스 추가한 래퍼
#include <time.h> // c 스타일 랜덤 시드값 설정할때
#include <random> // c++ 스타일 랜덤 쓸때 
#include "TestMath.h" //헤더를 선언하면 헤더에 있는 내용이 전부 선언됨
#include "Practice.h"


int main() // 앤트리 포인트(코드가 시작되는곳) / main함수는 반드시 하나만 있어야함
{

	// 중간 실습(0908)

	/*
	1. 6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기
	 - 6면체 주사위를 돌리는 함수 만들기
	*/

	printf("중간실습1\n주사위를 1000000만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기\n\n");

	srand(time(0));
	int Dice[6] = {0};
	for (int i = 0; i < 1000000; i++)
	{
		int DiceNumber = rand() % 6 + 1;
		if (DiceNumber == 1)
		{
			Dice[DiceNumber -1]++;
		}
		else if (DiceNumber == 2)
		{
			Dice[DiceNumber -1]++;
		}
		else if (DiceNumber == 3)
		{
			Dice[DiceNumber -1]++;
		}
		else if (DiceNumber == 4)
		{
			Dice[DiceNumber -1]++;
		}
		else if (DiceNumber == 5)
		{
			Dice[DiceNumber -1]++;
		}
		else
		{
			Dice[DiceNumber -1]++;
		}
	}
	printf("주사위 값 결과\n");
	printf("1 : %d번\n", Dice[0]);
	printf("2 : %d번\n", Dice[1]);
	printf("3 : %d번\n", Dice[2]);
	printf("4 : %d번\n", Dice[3]);
	printf("5 : %d번\n", Dice[4]);
	printf("6 : %d번\n\n", Dice[5]);

	


	/*
	2. 배열에 저장된 값을 거꾸로 뒤집는 함수 만들기
	 - 파라메터 int Array[], int Size
	*/

	printf("중간실습2\n배열에 저장된 값을 거꾸로 뒤집는 함수 만들기\n\n");

	int Number2_1[5] = { 1, 2, 3, 4, 5 };

	printf("배열의 저장된 값\n{ 1 2 3 4 5 }\n\n");
	printf("배열을 뒤집은 값\n{ ");

	Swap(Number2_1, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", Number2_1[i]);
	}
	printf("}\n\n");



	/*
	3. 로또 번호 생성기
	 - 전체 숫자 범위 : 1번부터 45번까지.
	 - 맞춰야 하는 숫자 개수 : 6개.
	*/

	printf("중간실습3\n로또 번호 생성기\n\n");

	int LottoNumber[6] = { 0 };		

	for (int i = 0; i < 6; i++)
	{
		int Num = rand() % 45 + 1;
		bool Something = false;
		for (int j = 0; j < i; j++)
		{
			if (LottoNumber[j] == Num)
			{
				Something = true;
				break;
			}
		}
		if (!Something)
		{
			LottoNumber[i] = Num;
		}
		else
		{
			i--;
		}
	}

	printf("로또 번호 : { ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", LottoNumber[i]);
	}
	printf("}\n\n");

	/*
	4.미로 탈출 게임 만들기
	 - 2차원 배열을 활용하여 텍스트 기반 미로 탈출 게임을 구현.
	 - 미로의 구성
	 - 10행 20열의 2차원 배열
	 - 저장 방식
	 - 길(0): '. '으로 표시
	 - 벽(1): '# '으로 표시
	 - 시작점(2): 'S '로 표시
	 - 출구(3): 'E '로 표시
	*/

	printf("중간실습4\n미로탈출 게임 만들기\n\n");

	// 미로 크기
	const int MazeHeight = 10;
	const int MazeWidth = 20;

	// 미로 배열
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

	int PlayerX = 1;
	int PlayerY = 1;

	Maze[PlayerY][PlayerX];


	while (Maze[PlayerY][PlayerX]!=3)
	{
		MazeMap(Maze, PlayerY, PlayerX);


		char MoveBotten;
		printf("이동 방향을 입력하시오.(↑:w ↓:s ←:a →:d)");
		std::cin >> MoveBotten;
		printf("\n");
		
		int PlayerNewX = PlayerX;
		int PlayerNewY = PlayerY;

		if (MoveBotten == 'w' || MoveBotten == 'W')
		{
			PlayerNewY--;
		}
		else if (MoveBotten == 's' || MoveBotten == 'S')
		{
			PlayerNewY++;
		}
		else if (MoveBotten == 'a' || MoveBotten == 'A')
		{
			PlayerNewX--;
		}
		else if(MoveBotten == 'd' || MoveBotten == 'D')
		{
			PlayerNewX++;
		}
		else
		{
			printf("올바른 방향을 입력하시오.\n");
		}

		if (Maze[PlayerNewY][PlayerNewX] != 1)
		{
			PlayerY = PlayerNewY;
			PlayerX = PlayerNewX;
		}
		else
		{
			printf("벽으로 막혀있습니다.\n");
		}
	}
	printf("미로를 통과하셨습니다.\n");








	



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	return 0;
}
