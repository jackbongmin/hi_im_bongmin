#include "Practice.h"
#include <iostream>
#include <stdio.h>
#include <random>

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 실습 0905 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

/*
[기본 함수 실습]

1. 특정범위안에 랜덤한 수를 리턴하는 함수
	- int 파라메터 2개
	- int 리턴

2. "당신의 나이를 입력해주세요 : " → "당신은 00살 입니다."
	- int 파라메터 1개

3. 원의 반지름을 입력 받고 넓이를 구하기
	- float 파라메터 1개
	- float 리턴

4. 숫자를 입력받아 홀수인지 짝수인지 판단하는 함수
	- int 파라메터 1개
	- bool 리턴(true면 홀수, false면 짝수)

5. 성적분류 함수 (A ~ F)
	- int 파라메터 1개
	- int 리터(enum 값)

6. 아이템 설정, 아이템 해제, 아이템 토글용 함수 총 3개
	- 비트플래그인벤토리 수정
	- int 파라메터 2개(Inventory, 비트플래그용 enum)
	- 리턴 없음

7. 피라미드 출력 함수
	- int 파라메터 1개

[기본 탬플릿 실습]

8. Min
	- 파라메터 2개
	- 리턴 : 파라메터 중 작은 수 리턴

9. Max
	- 파라메터 2개
	- 리턴 : 파라메터 중 큰 수 리턴

10. Clamp
	- 파라메터 3개(value, min, max)
	- 리턴
		value 값이 min보다 작으면 min
		value 값이 max보다 크면 max
		value 값이 min과 max사이면 value

[기본 재귀함수 실습]

11. 재귀함수를 이용해서 팩토리얼 값을 만드는 함수 만들기(for사용 x)

*/

//실습 1
	int RandomNumber1(int Number1, int Number2)
	{
		return rand() % (Number2 - Number1) + Number1;
	}

//실습 2
	void Age(int Number1)
	{
		printf("당신은 %d살 입니다.\n", Number1);
	}

//실습 3
	float Radius(float Number1)
	{
		const float Pie = 3.141592f;
		return Number1 * Number1 * Pie;
	}

//실습 4

	bool Number4_1(int Number1)
	{
		if (Number1 % 2 == 1)
		{
			printf("입력하신 숫자는 홀수 입니다.\n");
			return true;
		}
		else
		{
			printf("입력하신 숫자는 짝수 입니다.\n");
			return false;
		}
	}

//실습 5
	int Score(int Number1)
	{
		enum score
		{
			A,
			B,
			C,
			D,
			F
		};
		if (Number1 >= 90)
		{
			printf("당신의 점수는 A입니다.\n");
			return 0;
		}
		else if (Number1 >= 80)
		{
			printf("당신의 점수는 B입니다.\n");
			return 0;
		}
		else if (Number1 >= 70)
		{
			printf("당신의 점수는 C입니다.\n");
			return 0;
		}
		else if (Number1 >= 60)
		{
			printf("당신의 점수는 D입니다.\n");
			return 0;
		}
		else
		{
			printf("당신의 점수는 F입니다.\n");
			return 0;
		}
	}

//실습 6

	void SetItem(int Inventory, ItemList Item)
	{
		Inventory |= Item;
	}

	void UnSetItem(int Inventory, ItemList Item)
	{
		Inventory &= ~Item;
	}

	void ToggleItem(int Inventory, ItemList Item)
	{
		Inventory ^= Item;
	}

	//실습 7
	int Pyramid(int Number1)
	{
		for (int Line = 0; Line <= Number1; Line++)

		{

			for (int Space = 0; Space < (Number1 - Line); Space++)

			{

				printf(" ");

			}

			for (int Star = 0; Star < (2 * Line) - 1; Star++)

			{

				printf("*");

			}

			printf("\n");

		}
		return 0;
	}

//실습 11
	
	int Factorial(int Number1)
	{
		if (Number1 <= 1)
		{
			return 1;
		}
		else
		{
			return Number1 * (Number1 - 1);
		}		
	}


//
//// 주말실습 1
//	float Average(float Number1, float Number2, float Number3)
//	{
//		return (Number1 + Number2 + Number3) / 3.0f;
//	}
//
//// 주말실습 2
//	float SalePrice(float Number1, float Number2)
//	{
//		return Number1 - (Number1 * Number2 * 0.01);
//	}
//
//// 주말실습 3
//	int Dice(int Number1)
//	{
//		return rand() % 6 +1;
//	}
//
//// 주말실습 4
//	int Score1(int Number1)
//	{
//		enum score
//		{
//			A,
//			B,
//			C,
//			D,
//			F
//		};
//		if (Number1 >= 90)
//		{
//			printf("당신의 점수는 A입니다.\n");
//			return 0;
//		}
//		else if (Number1 >= 80)
//		{
//			printf("당신의 점수는 B입니다.\n");
//			return 0;
//		}
//		else if (Number1 >= 70)
//		{
//			printf("당신의 점수는 C입니다.\n");
//			return 0;
//		}
//		else if (Number1 >= 60)
//		{
//			printf("당신의 점수는 D입니다.\n");
//			return 0;
//		}
//		else
//		{
//			printf("당신의 점수는 F입니다.\n");
//			return 0;
//		}
//	}
//
//// 주말실습(심화) 1
//	int TotalSum(int Number1)
//	{
//		int Sum = 0;
//		while (Number1 > 0)
//		{
//			Sum += Number1 % 10;
//			Number1 = Number1 / 10;
//		}
//		return Sum;
//	}
//
//
//// 주말실습(심화) 2
//	void DecToBin(int Number1)
//	{
//		if (Number1 > 1)
//		{
//			DecToBin(Number1 / 2);
//		}
//		printf("%d", Number1 % 2);
//	}
//
//// 주말실습(심화) 3
//	void Spin(int Number1, int Number2, int Number3)
//	{
//		Number1 = rand() % 10 + 1;
//		Number2 = rand() % 10 + 1;
//		Number3 = rand() % 10 + 1;
//		
//	}
//
//	int Result(int Numberone, int Numbertwo, int Numberthree, int Number4)
//	{
//		return 0;
//	}
//
//
//// 주말실습(심화) 4
//
//	int PlayerAttack(int Number1)
//	{
//		int Damage = rand() % 11 + 5;
//		if (rand() % 10 == 0)
//		{
//			Damage *= 2;
//			printf("크리티컬 히트!\n");
//		}
//			return Damage;
//	}
//
//
//	int ComputerAttack(int Number1)
//	{
//		int Damage = rand() % 11 + 5;
//		if (rand() % 10 == 0)
//		{
//			Damage *= 2;
//			printf("크리티컬 히트!\n");
//		}
//		return Damage;
//	}
//
//	//주말 실습(심화) 5
//
//	const int Jocker = 14;

	//// 카드 종류
	//void Card(int Number1)                 
	//{
	//	if (Number1 == Jocker)
	//	{
	//		printf("조커");
	//	}
	//	else
	//	{
	//		switch (Number1)
	//		{
	//			case 1 : printf("A");
	//				break;
	//			case 11: printf("J");
	//				break;
	//			case 12: printf("Q");
	//				break;
	//			case 13: printf("K");
	//				break;
	//			default: printf("%d", Number1);
	//		
	//		}
	//	}
	//		
	//}


	//// 카드 섞기
	//void Shuffle(int Number1, int Number2)      
	//{
	//	for(int a = Number2 - 1; a > 0; a--)
	//	{
	//		int b = rand() % (a + 1);
	//		int c = (Number1 + a);
	//		(Number1 + a) = (Number1 + b);
	//		(Number1 + b) = c;
	//	}
	//}


	void Practice0905_02_05()
	{
			enum Card
			{
				CardA = 0,
				Card2,	
				Card3,
				Card4,
				Card5,
				Card6,
				Card7,
				Card8,
				Card9,
				Card10,
				CardJ,
				CardQ,
				CardK,
				CardJoker, 
				NumOfCards
			};

			int Money = 10000;
			const int MinimumBet = 100;

			while (Money >= MinimumBet)
			{
				int CurrentBet = MinimumBet;

				printf("배팅을 해주세요 (100~%d) : ", Money);
				std::cin >> CurrentBet;
				printf("%d원을 배팅했습니다.\n", CurrentBet);

				Money -= CurrentBet;

				// 배팅을 안하고 있다.

				int Dealer1 = rand() % CardJoker;
				int Dealer2 = -1;
				do
				{
					Dealer2 = rand() % CardJoker;
				} while (Dealer2 == Dealer1);
				int Dealer3 = -1;
				do
				{
					Dealer3 = rand() % CardJoker;
				} while (Dealer3 == Dealer1 || Dealer3 == Dealer2);

				int JokerIndex = rand() % 3;
				switch (JokerIndex)
				{
				case 0:
					Dealer1 = CardJoker;
					break;
				case 1:
					Dealer2 = CardJoker;
					break;
				case 2:
					Dealer3 = CardJoker;
					break;
				default:
					// 절대 들어오면 안된다.
					break;
				}

				printf("카드를 선택하세요 (0, 1, 2) : ");
				int PlayerInput = 0;
				std::cin >> PlayerInput;

				bool PlayerWin = false;
				printf("플레이어는 %d를 선택했습니다.\n", PlayerInput);
				switch (PlayerInput)
				{
				case 0:
					if (Dealer1 == CardJoker)
					{
						// 발견함
						PlayerWin = true;
					}
					break;
				case 1:
					if (Dealer2 == CardJoker)
					{
						// 발견함
						PlayerWin = true;
					}
					break;
				case 2:
					if (Dealer3 == CardJoker)
					{
						// 발견함
						PlayerWin = true;
					}
					break;
				default:
					// 절대 들어오면 안된다.
					break;
				}

				if (PlayerWin)
				{
					Money += CurrentBet * 2;
					printf("조커를 뽑았습니다. 당신의 현재 금액은 %d입니다.\n", Money);
				}
				else
				{
					printf("당신이 뽑은 카드는 조커가 아닙니다.\n");

					if (Money >= CurrentBet * 2)
					{
						printf("추가 도전 하시겠습니까 ? (0:yes, 1 : no) : ");
						int Select = -1;
						std::cin >> Select;
						if (Select == 0)
						{
							Money -= CurrentBet * 2;
							CurrentBet *= 3;
							int PlayerSecondInput = -1;
							switch (PlayerInput)
							{
							case 0:
							{
								do
								{
									printf("남은 카드 중 하나를 선택하세요 (1,2) : ");
									std::cin >> PlayerSecondInput;
								} //while (!(PlayerSecondInput == 1 || PlayerSecondInput == 2));
								while (PlayerSecondInput != 1 && PlayerSecondInput != 2);
							}
							break;
							case 1:
							{
								do
								{
									printf("남은 카드 중 하나를 선택하세요 (0,2) : ");
									std::cin >> PlayerSecondInput;
								} while (PlayerSecondInput != 0 && PlayerSecondInput != 2);
							}
							break;
							case 2:
							{
								do
								{
									printf("남은 카드 중 하나를 선택하세요 (0,1) : ");
									std::cin >> PlayerSecondInput;
								} while (PlayerSecondInput != 0 && PlayerSecondInput != 1);
							}
							break;
							default:
								// 절대 들어오면 안된다.
								break;
							}

							printf("플레이어는 두번째로 %d를 선택했습니다.\n", PlayerSecondInput);
							switch (PlayerSecondInput)
							{
							case 0:
								if (Dealer1 == CardJoker)
								{
									// 발견함
									PlayerWin = true;
								}
								break;
							case 1:
								if (Dealer2 == CardJoker)
								{
									// 발견함
									PlayerWin = true;
								}
								break;
							case 2:
								if (Dealer3 == CardJoker)
								{
									// 발견함
									PlayerWin = true;
								}
								break;
							default:
								// 절대 들어오면 안된다.
								break;
							}

							if (PlayerWin)
							{
								Money += CurrentBet * 2;
								printf("조커를 뽑았습니다. 당신의 현재 금액은 %d입니다.\n", Money);
							}
							else
							{
								printf("당신의 패배입니다.\n");
							}
						}
						else
						{
							printf("당신의 패배입니다.\n");
						}
					}
					else
					{
						printf("당신의 패배입니다.\n");
					}
				}
			}
	}

	void Shuffle(int Array[], int Length)	// Length = 배열 수
	{
		/*
		1. 배열의 마지막요소에서 첫 요소까지 순회.
		2. 현재 요소의 인덱스(i)와, 0 ~ i 중 임의의 인덱스(j)를 선택한다.
		3. i번째 요소와 j번째 요소를 서로 교환
		4. i가 0이 될때까지 반복
		*/
		
		for (int i = Length - 1; i > 0; i--)		// 1,4번
		{
			int j = rand() % (i + 1);
			int Temp = Array[i];
			Array[i] = Array[j];
			Array[j] = Temp;
		}
	}




	//void TestRef(int& OutData, const int& ReadData)
	//{
	//	OutData *= 2;
	//}

	//void Day0908_Ref()
	//{
	//	int Number = 10;
	//	int Number2 = 10;
	//	int& Ref = Number;	// Number의 참조는 Ref다.

	//	TestRef(Number, Number2);

	//	int i = 0;
	//}

	//void Swap(int Array[], int Size)
	//{
	//	for (int i = 0; i < (Size / 2); i++)
	//	{
	//		int j = Size - 1 - i;
	//		int Temp = Array[i];
	//		Array[i] = Array[j];
	//		Array[j] = Temp;
	//	}
	//}

	//void MazeMap(int Maze[10][20], int PlayerY, int PlayerX)
	//{
	//	for (int y = 0; y < 10; y++)
	//	{
	//		for (int x = 0; x < 20; x++)
	//		{
	//			if (PlayerY == y && PlayerX == x)
	//			{
	//				printf("P ");
	//			}
	//			else
	//			{
	//				switch(Maze[y][x])
	//				{
	//				case 0:
	//					printf(". ");
	//					break;
	//				case 1:
	//					printf("# ");
	//					break;
	//				case 2:
	//					printf("S ");
	//					break;
	//				case 3:
	//					printf("E ");
	//					break;
	//				}
	//			}
	//		}
	//		printf("\n");
	//	}
	//}
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	// 25.09.09


	//void PointerParameter(int* pNumber)
	//{
	//	(*pNumber) = (*pNumber) * 2;		// 입력받은 주소게 있는 int값을 2배로 만들어줌
	//}

	//int Number = 10;

	//void d0909()
	//{
	//	PointerParameter(&Number);
	//}

	//// 간단실습3
	//// int*와 float*를 파라메터로 받은 함수 만들기
	//// int*받은 값은 3 더하기, float*로 받은 값은 절반으로 만들기
	//
	//void TestPointer(int* pInt, float* pFloat)
	//{
	//	(*pInt) += 3;
	//	(*pFloat) *= 0.5f;	// *와 / 중에 선택할 수 있는 상황이면 *가 성능상 유리하다.
	//}

	//void d0909_2()
	//{
	//	//배열과 포인터
	//	int Array[5] = { 10, 20, 30, 40, 50 };
	//	int* pArray = Array;		// 배열의 이름은 배열의 첫번째 요소의 주소와 같다.
	//	int* pArray2 = &Array[0];	// Array == &Array[0] 두개는 같은 의미

	//	//pArray를 이용해서 Array[2]를 300으로 수정하기
	//	*(pArray + 2) = 300;

	//	for (int i = 0; i < 5; i++)
	//	{
	//		printf("%d ", Array[i]);
	//	}


	//	for (int data : Array)		// range-for : Array안의 요소들을 순차적으로 하나씩 data에 넣어 처리
	//	{
	//		printf("%d ", data);
	//	}

	//	printf("\n");

	//}


	// 동적 할당


	void d0909_DynamicAllocation()
	{
		//// c스타일 메모리 할당 및 해제
		//int Size = 5;
		//int* Array10 = nullptr;
		//Array10 = (int*)malloc(sizeof(int) * Size);	// int 5개짜리 메모리 블럭 할당 받기
		//

		//Array10[2] = 20;
		///*
		//작업들
		//*/
		//
		//free(Array10);								// Array를 해제. malloc을 했으면 무조건 free부터 만들고 작업할것
		//Array10 = nullptr;							// 댕글링 포인터 방지


		// c++ 스타일 메모리 할당 및 해제

		int* Data = new int(5); // int 하나를 할당 받는데 주소가 가리키는 값은 5를 설정해라
		delete Data;
		Data = nullptr;

		int* Array1 = new int[10]; // int 10개짜리 배열을 만들어라
		delete[] Array1; // 배열은 반드시 이렇게 해제해야 한다.
		Array1 = nullptr;

		// 간단 실습4
		// int 배열 할당받기(첫 할당은 3개만)
		// 숫자를 입력받을 때마다 배열에 추가하기

		const int ExitInput = -1;	// 입력 종료값 or 빈칸 표현값
		const int StartSize = 3;
		int* Array4 = nullptr;
		Array4 = new int[StartSize];
		for (int i = 0; i < StartSize; i++)
		{
			Array4[i] = ExitInput;
		}
		int CurrentIndex = 0;
		int CurrentSize = StartSize;


		int InputNumber4 = 0;
		while (InputNumber4 != ExitInput)
		{
			printf("배열에 넣을 숫자를 입력하시오 : ");
			std::cin >> InputNumber4;

			Array4[CurrentIndex] = InputNumber4;
			CurrentIndex++;

			if (CurrentIndex >= CurrentSize)
			{
				int* newArray = new int[CurrentSize + 1];
				for (int i = 0; i < CurrentSize; i++)
				{
					newArray[i] = Array4[i];
				}
				newArray[CurrentSize] = ExitInput;

				delete[] Array4;
				Array4 = newArray;
				CurrentSize++;
			}

			printf("입력된 데이터 : ");
			for (int i = 0; i < CurrentSize; i++)
			{
				printf("%d ", Array4[i]);
			}
			printf("\n");
		}

		delete[] Array4;
		Array4 = nullptr;
	}

	//0908실습 1 풀이
	void Reverse(int* Array, int Size)
	{
		int HalfSize = Size / 2;
		for (int i = 0; i < HalfSize; i++)
		{
			int temp = Array[i];
			Array[i] = Array[Size - 1 - i];
			Array[Size - 1 - i] = temp;
		}
	}

	//0908실습2 풀이
	void p2()
	{
		int Array[10] = { 1,2,3,4,5,6,7,8,9,0 };

		Reverse(Array, 10);

		printf("Array : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", Array[i]);
		}
		printf("\n");
		Reverse(Array, 10);
		printf("Array(Reverse) : ");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", Array[i]);
		}
		printf("\n");
	}

	//0908실습3 풀이
	void p3()
	{
		const int MaxNumber = 45;
		int Array[45];
		for (int i = 0; i < MaxNumber; i++)
		{
			Array[i] = i + 1;
		}
		Shuffle(Array, MaxNumber);


		printf("로또 번호는 : ");
		const int PickCount = 6;
		for (int i = 0; i < PickCount; i++)
		{
			printf("%d ", Array[i]);
		}
		printf("입니다.\n");
	}
	////0908실습4 풀이

	//void p4()
	//{
	//	int PlayerX = 0;
	//	int PlayerY = 0;
	//	FindStartPosition(PlayerX, PlayerY);

	//	printf("~~ 미로 탈출 게임 ~~\n");

	//	while (true)
	//	{
	//		PrintMaze(PlayerX, PlayerY);

	//		if (IsEnd(PlayerX, PlayerY))
	//		{
	//			printf("축하합니다! 미로를 탈출했습니다!\n");
	//			break;
	//		}

	//		int MoveFlags = PrintAvailableMoves(PlayerX, PlayerY);
	//		MoveDirection Direction = GetMoveInput(MoveFlags);
	//		switch (Direction)
	//		{
	//		case DirUp:
	//			PlayerY--;
	//			break;
	//		case DirDown:
	//			PlayerY++;
	//			break;
	//		case DirLeft:
	//			PlayerX--;
	//			break;
	//		case DirRight:
	//			PlayerX++;
	//			break;
	//		case DirNone:
	//		default:
	//			// 있을 수 없음
	//			break;
	//		}
	//	}

	//}

	//void PrintMaze(int PlayerX, int PlayerY)
	//{
	//	for (int y = 0; y < MazeHeight; y++)
	//	{
	//		for (int x = 0; x < MazeWidth; x++)
	//		{
	//			if (PlayerX == x && PlayerY == y)
	//			{
	//				printf("P ");
	//			}
	//			else if (Maze[y][x] == Wall)
	//			{
	//				printf("# ");
	//			}
	//			else if (Maze[y][x] == Path)
	//			{
	//				printf(". ");
	//			}
	//			else if (Maze[y][x] == Start)
	//			{
	//				printf("S ");
	//			}
	//			else if (Maze[y][x] == End)
	//			{
	//				printf("E ");
	//			}
	//			else
	//			{
	//				// 절대 들어오면 안되는 곳 == 맵 데이터가 잘못된 것
	//			}
	//		}
	//		printf("\n");
	//	}
	//}

	//void FindStartPosition(int& OutStartX, int& OutStartY)
	//{
	//	for (int y = 0; y < MazeHeight; y++)
	//	{
	//		for (int x = 0; x < MazeWidth; x++)
	//		{
	//			if (Maze[y][x] == Start)
	//			{
	//				OutStartX = x;
	//				OutStartY = y;
	//				return;
	//			}
	//		}
	//	}
	//	OutStartX = 0;
	//	OutStartY = 0;
	//}

	//int PrintAvailableMoves(int PlayerX, int PlayerY)
	//{
	//	int MoveFlags = DirNone;

	//	printf("이동할 수 있는 방향을 선택하세요 (w:위 a:왼쪽 s:아래쪽 d:오른쪽):\n");
	//	if (!IsWall(PlayerX, PlayerY - 1))
	//	{
	//		printf("W(↑) ");
	//		MoveFlags |= DirUp;
	//	}
	//	if (!IsWall(PlayerX, PlayerY + 1))
	//	{
	//		printf("S(↓) ");
	//		MoveFlags |= DirDown;
	//	}
	//	if (!IsWall(PlayerX - 1, PlayerY))
	//	{
	//		printf("A(←) ");
	//		MoveFlags |= DirLeft;
	//	}
	//	if (!IsWall(PlayerX + 1, PlayerY))
	//	{
	//		printf("D(→) ");
	//		MoveFlags |= DirRight;
	//	}
	//	printf("\n");

	//	return MoveFlags;
	//}

	//bool IsWall(int X, int Y)
	//{
	//	bool isWall = false;
	//	if (Y < 0 || Y >= MazeHeight ||
	//		X < 0 || X >= MazeWidth ||
	//		Maze[Y][X] == Wall)
	//		isWall = true;
	//	return isWall;
	//}

	//bool IsEnd(int X, int Y)
	//{
	//	return Maze[Y][X] == End;
	//}

	//MoveDirection GetMoveInput(int MoveFlags)
	//{
	//	char InputChar = 0;
	//	MoveDirection Direction = DirNone;

	//	while (true)
	//	{
	//		printf("방향을 입력하세요 : ");
	//		std::cin >> InputChar;

	//		if ((InputChar == 'w' || InputChar == 'W')
	//			&& (MoveFlags & DirUp) /*!= 0*/)
	//		{
	//			Direction = DirUp;
	//			break;
	//		}
	//		if ((InputChar == 's' || InputChar == 'S')
	//			&& (MoveFlags & DirDown) /*!= 0*/)
	//		{
	//			Direction = DirDown;
	//			break;
	//		}
	//		if ((InputChar == 'a' || InputChar == 'A')
	//			&& (MoveFlags & DirLeft) /*!= 0*/)
	//		{
	//			Direction = DirLeft;
	//			break;
	//		}
	//		if ((InputChar == 'd' || InputChar == 'D')
	//			&& (MoveFlags & DirRight) /*!= 0*/)
	//		{
	//			Direction = DirRight;
	//			break;
	//		}

	//		printf("잘못된 입력입니다. 이동할 수 있는 방향 중에서 선택하세요.\n");
	//	}

	//	return Direction;
	//}




// 0909 실습1
// 1. 가로 세로를 입력받아 배열을 생성하고 배열의 안을 0부터 1씩 증가하는 값으로 채우고 출력하기
	

void d0909_p1()
	{
		int X = 0;
		int Y = 0;
		printf("가로 값을 입력하시오 : ");
		std::cin >> X;

		printf("세로 값을 입력하시오 : ");
		std::cin >> Y;

		if (X <= 0 || Y <= 0)
		{
			printf("가로/세로는 양수여야 합니다.\n");
			return ;
		}

		const int XY = X * Y;
		int* Number = new int[XY];

		for (int i = 0; i < XY; i++)
		{
			Number[i] = i;
		}

		for (int i = 0; i < XY; ++i)
		{
			printf("%d ", Number[i]);
			if ((i + 1) % X == 0)
			{
				printf("\n");
			}
		}
		delete[] Number;
	}



// 0909 실습2
// 2. 하이로우 수정하기
//	- 게임이 종료되었을 때 이때까지 플레이어가 입력한 모든 수를 출력해서 보여주기


//
//// 0909 실습3
//// 3. 미로탈출게임 수정하기
////	- 이동했을 때 일정확률(20%)로 전투가 발생한다.
////  - 이동했을 때 일정확률(10%)로 Player HP가 회복된다.
////	- 두 이벤트는 중복으로 발생하지 않는다.
//
//	void d0909_p3()
//	{
//			int PlayerX = 0;
//		int PlayerY = 0;
//		FindStartPosition(PlayerX, PlayerY);
//
//		printf("~~ 미로 탈출 게임 ~~\n");
//
//		while (true)
//		{
//			PrintMaze(PlayerX, PlayerY);
//
//			if (IsEnd(PlayerX, PlayerY))
//			{
//				printf("축하합니다! 미로를 탈출했습니다!\n");
//				break;
//			}
//
//			int MoveFlags = PrintAvailableMoves(PlayerX, PlayerY);
//			MoveDirection Direction = GetMoveInput(MoveFlags);
//			switch (Direction)
//			{
//			case DirUp:
//				PlayerY--;
//				break;
//			case DirDown:
//				PlayerY++;
//				break;
//			case DirLeft:
//				PlayerX--;
//				break;
//			case DirRight:
//				PlayerX++;
//				break;
//			case DirNone:
//			default:
//				// 있을 수 없음
//				break;
//			}
//		}
//
//	}
//
//	void PrintMaze(int PlayerX, int PlayerY)
//	{
//		for (int y = 0; y < MazeHeight; y++)
//		{
//			for (int x = 0; x < MazeWidth; x++)
//			{
//				if (PlayerX == x && PlayerY == y)
//				{
//					printf("P ");
//				}
//				else if (Maze[y][x] == Wall)
//				{
//					printf("# ");
//				}
//				else if (Maze[y][x] == Path)
//				{
//					printf(". ");
//				}
//				else if (Maze[y][x] == Start)
//				{
//					printf("S ");
//				}
//				else if (Maze[y][x] == End)
//				{
//					printf("E ");
//				}
//				else
//				{
//					// 절대 들어오면 안되는 곳 == 맵 데이터가 잘못된 것
//				}
//			}
//			printf("\n");
//		}
//
//	}
//	
//	void FindStartPosition(int& OutStartX, int& OutStartY)
//	{
//		for (int y = 0; y < MazeHeight; y++)
//		{
//			for (int x = 0; x < MazeWidth; x++)
//			{
//				if (Maze[y][x] == Start)
//				{
//					OutStartX = x;
//					OutStartY = y;
//					return;
//				}
//			}
//		}
//		OutStartX = 0;
//		OutStartY = 0;
//	}
//	
//	int PrintAvailableMoves(int PlayerX, int PlayerY)
//	{
//		int MoveFlags = DirNone;
//
//		printf("이동할 수 있는 방향을 선택하세요 (w:위 a:왼쪽 s:아래쪽 d:오른쪽):\n");
//		if (!IsWall(PlayerX, PlayerY - 1))
//		{
//			printf("W(↑) ");
//			MoveFlags |= DirUp;
//		}
//		if (!IsWall(PlayerX, PlayerY + 1))
//		{
//			printf("S(↓) ");
//			MoveFlags |= DirDown;
//		}
//		if (!IsWall(PlayerX - 1, PlayerY))
//		{
//			printf("A(←) ");
//			MoveFlags |= DirLeft;
//		}
//		if (!IsWall(PlayerX + 1, PlayerY))
//		{
//			printf("D(→) ");
//			MoveFlags |= DirRight;
//		}
//		printf("\n");
//
//		return MoveFlags;
//
//	}
//	
//	bool IsWall(int X, int Y)
//	{
//		bool isWall = false;
//		if (Y < 0 || Y >= MazeHeight ||
//			X < 0 || X >= MazeWidth ||
//			Maze[Y][X] == Wall)
//			isWall = true;
//		return isWall;
//	}
//	
//	bool IsEnd(int X, int Y)
//	{
//		return Maze[Y][X] == End;
//	}
//	
//	MoveDirection GetMoveInput(int MoveFlags)
//	{
//		char InputChar = 0;
//		MoveDirection Direction = DirNone;
//
//		while (true)
//		{
//			printf("방향을 입력하세요 : ");
//			std::cin >> InputChar;
//
//			if ((InputChar == 'w' || InputChar == 'W')
//				&& (MoveFlags & DirUp) /*!= 0*/)
//			{
//				Direction = DirUp;
//				break;
//			}
//			if ((InputChar == 's' || InputChar == 'S')
//				&& (MoveFlags & DirDown) /*!= 0*/)
//			{
//				Direction = DirDown;
//				break;
//			}
//			if ((InputChar == 'a' || InputChar == 'A')
//				&& (MoveFlags & DirLeft) /*!= 0*/)
//			{
//				Direction = DirLeft;
//				break;
//			}
//			if ((InputChar == 'd' || InputChar == 'D')
//				&& (MoveFlags & DirRight) /*!= 0*/)
//			{
//				Direction = DirRight;
//				break;
//			}
//
//			printf("잘못된 입력입니다. 이동할 수 있는 방향 중에서 선택하세요.\n");
//		}
//
//		return Direction;
//
//	}


