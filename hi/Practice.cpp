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



// 주말실습 1
	float Average(float Number1, float Number2, float Number3)
	{
		return (Number1 + Number2 + Number3) / 3.0f;
	}

// 주말실습 2
	float SalePrice(float Number1, float Number2)
	{
		return Number1 - (Number1 * Number2 * 0.01);
	}

// 주말실습 3
	int Dice(int Number1)
	{
		return rand() % 6 +1;
	}

// 주말실습 4
	int Score1(int Number1)
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

// 주말실습(심화) 1
	int TotalSum(int Number1)
	{
		int Sum = 0;
		while (Number1 > 0)
		{
			Sum += Number1 % 10;
			Number1 = Number1 / 10;
		}
		return Sum;
	}


// 주말실습(심화) 2
	void DecToBin(int Number1)
	{
		if (Number1 > 1)
		{
			DecToBin(Number1 / 2);
		}
		printf("%d", Number1 % 2);
	}

// 주말실습(심화) 3
	void Spin(int Number1, int Number2, int Number3)
	{
		Number1 = rand() % 10 + 1;
		Number2 = rand() % 10 + 1;
		Number3 = rand() % 10 + 1;
		
	}

	int Result(int Numberone, int Numbertwo, int Numberthree, int Number4)
	{
		return 0;
	}


// 주말실습(심화) 4

	int PlayerAttack(int Number1)
	{
		int Damage = rand() % 11 + 5;
		if (rand() % 10 == 0)
		{
			Damage *= 2;
			printf("크리티컬 히트!\n");
		}
			return Damage;
	}


	int ComputerAttack(int Number1)
	{
		int Damage = rand() % 11 + 5;
		if (rand() % 10 == 0)
		{
			Damage *= 2;
			printf("크리티컬 히트!\n");
		}
		return Damage;
	}

	//주말 실습(심화) 5

	const int Jocker = 14;

	// 카드 종류
	void Card(int Number1)                 
	{
		if (Number1 == Jocker)
		{
			printf("조커");
		}
		else
		{
			switch (Number1)
			{
				case 1 : printf("A");
					break;
				case 11: printf("J");
					break;
				case 12: printf("Q");
					break;
				case 13: printf("K");
					break;
				default: printf("%d", Number1);
			
			}
		}
			
	}


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




	void TestRef(int& OutData, const int& ReadData)
	{
		OutData *= 2;
	}

	void Day0908_Ref()
	{
		int Number = 10;
		int Number2 = 10;
		int& Ref = Number;	// Number의 참조는 Ref다.

		TestRef(Number, Number2);

		int i = 0;
	}


	


