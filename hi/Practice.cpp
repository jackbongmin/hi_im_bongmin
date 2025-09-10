#include "Practice.h"
#include <iostream>
#include <stdio.h>
#include <random>

//�ѤѤѤѤѤѤѤѤѤѤѤѤ� �ǽ� 0905 �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

/*
[�⺻ �Լ� �ǽ�]

1. Ư�������ȿ� ������ ���� �����ϴ� �Լ�
	- int �Ķ���� 2��
	- int ����

2. "����� ���̸� �Է����ּ��� : " �� "����� 00�� �Դϴ�."
	- int �Ķ���� 1��

3. ���� �������� �Է� �ް� ���̸� ���ϱ�
	- float �Ķ���� 1��
	- float ����

4. ���ڸ� �Է¹޾� Ȧ������ ¦������ �Ǵ��ϴ� �Լ�
	- int �Ķ���� 1��
	- bool ����(true�� Ȧ��, false�� ¦��)

5. �����з� �Լ� (A ~ F)
	- int �Ķ���� 1��
	- int ����(enum ��)

6. ������ ����, ������ ����, ������ ��ۿ� �Լ� �� 3��
	- ��Ʈ�÷����κ��丮 ����
	- int �Ķ���� 2��(Inventory, ��Ʈ�÷��׿� enum)
	- ���� ����

7. �Ƕ�̵� ��� �Լ�
	- int �Ķ���� 1��

[�⺻ ���ø� �ǽ�]

8. Min
	- �Ķ���� 2��
	- ���� : �Ķ���� �� ���� �� ����

9. Max
	- �Ķ���� 2��
	- ���� : �Ķ���� �� ū �� ����

10. Clamp
	- �Ķ���� 3��(value, min, max)
	- ����
		value ���� min���� ������ min
		value ���� max���� ũ�� max
		value ���� min�� max���̸� value

[�⺻ ����Լ� �ǽ�]

11. ����Լ��� �̿��ؼ� ���丮�� ���� ����� �Լ� �����(for��� x)

*/

//�ǽ� 1
	int RandomNumber1(int Number1, int Number2)
	{
		return rand() % (Number2 - Number1) + Number1;
	}

//�ǽ� 2
	void Age(int Number1)
	{
		printf("����� %d�� �Դϴ�.\n", Number1);
	}

//�ǽ� 3
	float Radius(float Number1)
	{
		const float Pie = 3.141592f;
		return Number1 * Number1 * Pie;
	}

//�ǽ� 4

	bool Number4_1(int Number1)
	{
		if (Number1 % 2 == 1)
		{
			printf("�Է��Ͻ� ���ڴ� Ȧ�� �Դϴ�.\n");
			return true;
		}
		else
		{
			printf("�Է��Ͻ� ���ڴ� ¦�� �Դϴ�.\n");
			return false;
		}
	}

//�ǽ� 5
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
			printf("����� ������ A�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 80)
		{
			printf("����� ������ B�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 70)
		{
			printf("����� ������ C�Դϴ�.\n");
			return 0;
		}
		else if (Number1 >= 60)
		{
			printf("����� ������ D�Դϴ�.\n");
			return 0;
		}
		else
		{
			printf("����� ������ F�Դϴ�.\n");
			return 0;
		}
	}

//�ǽ� 6

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

	//�ǽ� 7
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

//�ǽ� 11
	
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
//// �ָ��ǽ� 1
//	float Average(float Number1, float Number2, float Number3)
//	{
//		return (Number1 + Number2 + Number3) / 3.0f;
//	}
//
//// �ָ��ǽ� 2
//	float SalePrice(float Number1, float Number2)
//	{
//		return Number1 - (Number1 * Number2 * 0.01);
//	}
//
//// �ָ��ǽ� 3
//	int Dice(int Number1)
//	{
//		return rand() % 6 +1;
//	}
//
//// �ָ��ǽ� 4
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
//			printf("����� ������ A�Դϴ�.\n");
//			return 0;
//		}
//		else if (Number1 >= 80)
//		{
//			printf("����� ������ B�Դϴ�.\n");
//			return 0;
//		}
//		else if (Number1 >= 70)
//		{
//			printf("����� ������ C�Դϴ�.\n");
//			return 0;
//		}
//		else if (Number1 >= 60)
//		{
//			printf("����� ������ D�Դϴ�.\n");
//			return 0;
//		}
//		else
//		{
//			printf("����� ������ F�Դϴ�.\n");
//			return 0;
//		}
//	}
//
//// �ָ��ǽ�(��ȭ) 1
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
//// �ָ��ǽ�(��ȭ) 2
//	void DecToBin(int Number1)
//	{
//		if (Number1 > 1)
//		{
//			DecToBin(Number1 / 2);
//		}
//		printf("%d", Number1 % 2);
//	}
//
//// �ָ��ǽ�(��ȭ) 3
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
//// �ָ��ǽ�(��ȭ) 4
//
//	int PlayerAttack(int Number1)
//	{
//		int Damage = rand() % 11 + 5;
//		if (rand() % 10 == 0)
//		{
//			Damage *= 2;
//			printf("ũ��Ƽ�� ��Ʈ!\n");
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
//			printf("ũ��Ƽ�� ��Ʈ!\n");
//		}
//		return Damage;
//	}
//
//	//�ָ� �ǽ�(��ȭ) 5
//
//	const int Jocker = 14;

	//// ī�� ����
	//void Card(int Number1)                 
	//{
	//	if (Number1 == Jocker)
	//	{
	//		printf("��Ŀ");
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


	//// ī�� ����
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

				printf("������ ���ּ��� (100~%d) : ", Money);
				std::cin >> CurrentBet;
				printf("%d���� �����߽��ϴ�.\n", CurrentBet);

				Money -= CurrentBet;

				// ������ ���ϰ� �ִ�.

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
					// ���� ������ �ȵȴ�.
					break;
				}

				printf("ī�带 �����ϼ��� (0, 1, 2) : ");
				int PlayerInput = 0;
				std::cin >> PlayerInput;

				bool PlayerWin = false;
				printf("�÷��̾�� %d�� �����߽��ϴ�.\n", PlayerInput);
				switch (PlayerInput)
				{
				case 0:
					if (Dealer1 == CardJoker)
					{
						// �߰���
						PlayerWin = true;
					}
					break;
				case 1:
					if (Dealer2 == CardJoker)
					{
						// �߰���
						PlayerWin = true;
					}
					break;
				case 2:
					if (Dealer3 == CardJoker)
					{
						// �߰���
						PlayerWin = true;
					}
					break;
				default:
					// ���� ������ �ȵȴ�.
					break;
				}

				if (PlayerWin)
				{
					Money += CurrentBet * 2;
					printf("��Ŀ�� �̾ҽ��ϴ�. ����� ���� �ݾ��� %d�Դϴ�.\n", Money);
				}
				else
				{
					printf("����� ���� ī��� ��Ŀ�� �ƴմϴ�.\n");

					if (Money >= CurrentBet * 2)
					{
						printf("�߰� ���� �Ͻðڽ��ϱ� ? (0:yes, 1 : no) : ");
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
									printf("���� ī�� �� �ϳ��� �����ϼ��� (1,2) : ");
									std::cin >> PlayerSecondInput;
								} //while (!(PlayerSecondInput == 1 || PlayerSecondInput == 2));
								while (PlayerSecondInput != 1 && PlayerSecondInput != 2);
							}
							break;
							case 1:
							{
								do
								{
									printf("���� ī�� �� �ϳ��� �����ϼ��� (0,2) : ");
									std::cin >> PlayerSecondInput;
								} while (PlayerSecondInput != 0 && PlayerSecondInput != 2);
							}
							break;
							case 2:
							{
								do
								{
									printf("���� ī�� �� �ϳ��� �����ϼ��� (0,1) : ");
									std::cin >> PlayerSecondInput;
								} while (PlayerSecondInput != 0 && PlayerSecondInput != 1);
							}
							break;
							default:
								// ���� ������ �ȵȴ�.
								break;
							}

							printf("�÷��̾�� �ι�°�� %d�� �����߽��ϴ�.\n", PlayerSecondInput);
							switch (PlayerSecondInput)
							{
							case 0:
								if (Dealer1 == CardJoker)
								{
									// �߰���
									PlayerWin = true;
								}
								break;
							case 1:
								if (Dealer2 == CardJoker)
								{
									// �߰���
									PlayerWin = true;
								}
								break;
							case 2:
								if (Dealer3 == CardJoker)
								{
									// �߰���
									PlayerWin = true;
								}
								break;
							default:
								// ���� ������ �ȵȴ�.
								break;
							}

							if (PlayerWin)
							{
								Money += CurrentBet * 2;
								printf("��Ŀ�� �̾ҽ��ϴ�. ����� ���� �ݾ��� %d�Դϴ�.\n", Money);
							}
							else
							{
								printf("����� �й��Դϴ�.\n");
							}
						}
						else
						{
							printf("����� �й��Դϴ�.\n");
						}
					}
					else
					{
						printf("����� �й��Դϴ�.\n");
					}
				}
			}
	}

	void Shuffle(int Array[], int Length)	// Length = �迭 ��
	{
		/*
		1. �迭�� ��������ҿ��� ù ��ұ��� ��ȸ.
		2. ���� ����� �ε���(i)��, 0 ~ i �� ������ �ε���(j)�� �����Ѵ�.
		3. i��° ��ҿ� j��° ��Ҹ� ���� ��ȯ
		4. i�� 0�� �ɶ����� �ݺ�
		*/
		
		for (int i = Length - 1; i > 0; i--)		// 1,4��
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
	//	int& Ref = Number;	// Number�� ������ Ref��.

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
	//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	// 25.09.09


	//void PointerParameter(int* pNumber)
	//{
	//	(*pNumber) = (*pNumber) * 2;		// �Է¹��� �ּҰ� �ִ� int���� 2��� �������
	//}

	//int Number = 10;

	//void d0909()
	//{
	//	PointerParameter(&Number);
	//}

	//// ���ܽǽ�3
	//// int*�� float*�� �Ķ���ͷ� ���� �Լ� �����
	//// int*���� ���� 3 ���ϱ�, float*�� ���� ���� �������� �����
	//
	//void TestPointer(int* pInt, float* pFloat)
	//{
	//	(*pInt) += 3;
	//	(*pFloat) *= 0.5f;	// *�� / �߿� ������ �� �ִ� ��Ȳ�̸� *�� ���ɻ� �����ϴ�.
	//}

	//void d0909_2()
	//{
	//	//�迭�� ������
	//	int Array[5] = { 10, 20, 30, 40, 50 };
	//	int* pArray = Array;		// �迭�� �̸��� �迭�� ù��° ����� �ּҿ� ����.
	//	int* pArray2 = &Array[0];	// Array == &Array[0] �ΰ��� ���� �ǹ�

	//	//pArray�� �̿��ؼ� Array[2]�� 300���� �����ϱ�
	//	*(pArray + 2) = 300;

	//	for (int i = 0; i < 5; i++)
	//	{
	//		printf("%d ", Array[i]);
	//	}


	//	for (int data : Array)		// range-for : Array���� ��ҵ��� ���������� �ϳ��� data�� �־� ó��
	//	{
	//		printf("%d ", data);
	//	}

	//	printf("\n");

	//}


	// ���� �Ҵ�


	void d0909_DynamicAllocation()
	{
		//// c��Ÿ�� �޸� �Ҵ� �� ����
		//int Size = 5;
		//int* Array10 = nullptr;
		//Array10 = (int*)malloc(sizeof(int) * Size);	// int 5��¥�� �޸� �� �Ҵ� �ޱ�
		//

		//Array10[2] = 20;
		///*
		//�۾���
		//*/
		//
		//free(Array10);								// Array�� ����. malloc�� ������ ������ free���� ����� �۾��Ұ�
		//Array10 = nullptr;							// ��۸� ������ ����


		// c++ ��Ÿ�� �޸� �Ҵ� �� ����

		int* Data = new int(5); // int �ϳ��� �Ҵ� �޴µ� �ּҰ� ����Ű�� ���� 5�� �����ض�
		delete Data;
		Data = nullptr;

		int* Array1 = new int[10]; // int 10��¥�� �迭�� ������
		delete[] Array1; // �迭�� �ݵ�� �̷��� �����ؾ� �Ѵ�.
		Array1 = nullptr;

		// ���� �ǽ�4
		// int �迭 �Ҵ�ޱ�(ù �Ҵ��� 3����)
		// ���ڸ� �Է¹��� ������ �迭�� �߰��ϱ�

		const int ExitInput = -1;	// �Է� ���ᰪ or ��ĭ ǥ����
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
			printf("�迭�� ���� ���ڸ� �Է��Ͻÿ� : ");
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

			printf("�Էµ� ������ : ");
			for (int i = 0; i < CurrentSize; i++)
			{
				printf("%d ", Array4[i]);
			}
			printf("\n");
		}

		delete[] Array4;
		Array4 = nullptr;
	}

	//0908�ǽ� 1 Ǯ��
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

	//0908�ǽ�2 Ǯ��
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

	//0908�ǽ�3 Ǯ��
	void p3()
	{
		const int MaxNumber = 45;
		int Array[45];
		for (int i = 0; i < MaxNumber; i++)
		{
			Array[i] = i + 1;
		}
		Shuffle(Array, MaxNumber);


		printf("�ζ� ��ȣ�� : ");
		const int PickCount = 6;
		for (int i = 0; i < PickCount; i++)
		{
			printf("%d ", Array[i]);
		}
		printf("�Դϴ�.\n");
	}
	////0908�ǽ�4 Ǯ��

	//void p4()
	//{
	//	int PlayerX = 0;
	//	int PlayerY = 0;
	//	FindStartPosition(PlayerX, PlayerY);

	//	printf("~~ �̷� Ż�� ���� ~~\n");

	//	while (true)
	//	{
	//		PrintMaze(PlayerX, PlayerY);

	//		if (IsEnd(PlayerX, PlayerY))
	//		{
	//			printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
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
	//			// ���� �� ����
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
	//				// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
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

	//	printf("�̵��� �� �ִ� ������ �����ϼ��� (w:�� a:���� s:�Ʒ��� d:������):\n");
	//	if (!IsWall(PlayerX, PlayerY - 1))
	//	{
	//		printf("W(��) ");
	//		MoveFlags |= DirUp;
	//	}
	//	if (!IsWall(PlayerX, PlayerY + 1))
	//	{
	//		printf("S(��) ");
	//		MoveFlags |= DirDown;
	//	}
	//	if (!IsWall(PlayerX - 1, PlayerY))
	//	{
	//		printf("A(��) ");
	//		MoveFlags |= DirLeft;
	//	}
	//	if (!IsWall(PlayerX + 1, PlayerY))
	//	{
	//		printf("D(��) ");
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
	//		printf("������ �Է��ϼ��� : ");
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

	//		printf("�߸��� �Է��Դϴ�. �̵��� �� �ִ� ���� �߿��� �����ϼ���.\n");
	//	}

	//	return Direction;
	//}




// 0909 �ǽ�1
// 1. ���� ���θ� �Է¹޾� �迭�� �����ϰ� �迭�� ���� 0���� 1�� �����ϴ� ������ ä��� ����ϱ�
	

void d0909_p1()
	{
		int X = 0;
		int Y = 0;
		printf("���� ���� �Է��Ͻÿ� : ");
		std::cin >> X;

		printf("���� ���� �Է��Ͻÿ� : ");
		std::cin >> Y;

		if (X <= 0 || Y <= 0)
		{
			printf("����/���δ� ������� �մϴ�.\n");
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



// 0909 �ǽ�2
// 2. ���̷ο� �����ϱ�
//	- ������ ����Ǿ��� �� �̶����� �÷��̾ �Է��� ��� ���� ����ؼ� �����ֱ�


//
//// 0909 �ǽ�3
//// 3. �̷�Ż����� �����ϱ�
////	- �̵����� �� ����Ȯ��(20%)�� ������ �߻��Ѵ�.
////  - �̵����� �� ����Ȯ��(10%)�� Player HP�� ȸ���ȴ�.
////	- �� �̺�Ʈ�� �ߺ����� �߻����� �ʴ´�.
//
//	void d0909_p3()
//	{
//			int PlayerX = 0;
//		int PlayerY = 0;
//		FindStartPosition(PlayerX, PlayerY);
//
//		printf("~~ �̷� Ż�� ���� ~~\n");
//
//		while (true)
//		{
//			PrintMaze(PlayerX, PlayerY);
//
//			if (IsEnd(PlayerX, PlayerY))
//			{
//				printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
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
//				// ���� �� ����
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
//					// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
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
//		printf("�̵��� �� �ִ� ������ �����ϼ��� (w:�� a:���� s:�Ʒ��� d:������):\n");
//		if (!IsWall(PlayerX, PlayerY - 1))
//		{
//			printf("W(��) ");
//			MoveFlags |= DirUp;
//		}
//		if (!IsWall(PlayerX, PlayerY + 1))
//		{
//			printf("S(��) ");
//			MoveFlags |= DirDown;
//		}
//		if (!IsWall(PlayerX - 1, PlayerY))
//		{
//			printf("A(��) ");
//			MoveFlags |= DirLeft;
//		}
//		if (!IsWall(PlayerX + 1, PlayerY))
//		{
//			printf("D(��) ");
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
//			printf("������ �Է��ϼ��� : ");
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
//			printf("�߸��� �Է��Դϴ�. �̵��� �� �ִ� ���� �߿��� �����ϼ���.\n");
//		}
//
//		return Direction;
//
//	}


