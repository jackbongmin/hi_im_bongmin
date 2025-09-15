#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include "fstream"
#include "D0914.h"
#include "D0911.h"
#include "D0912.h"
#include <iostream>
#include <random>
#include "direct.h"

// �ָ� �ǽ�1

bool LeapYear(int year)
{
	if(year % 400 == 0)
		return true;
	if(year % 100 == 0)
		return false;
	if(year % 4 == 0)
		return true;

	return false;
}

void D0914_P1()
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
	printf("�⵵�� �Է��Ͻÿ� : ");
	std::cin >> Year;
	printf("���� �Է��Ͻÿ� : ");
	std::cin >> Month;
	printf("���� �Է��Ͻÿ� : ");
	std::cin >> Day;

	int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int TotalDays = 0;

	// �⵵
	for(int year=1;year<Year;year++ )
	{
		if (LeapYear(year) == true)
			TotalDays += 366;
		else
			TotalDays += 365;
	}

	// ��
	if(LeapYear(Year) == true)
		MonthDays[1] = 29;
	for (int month = 1; month < Month; month++)
	{
		TotalDays += MonthDays[month -1];
	}

	// ��
	TotalDays += (Day-1);

	// ����
	int WeekDay = TotalDays % 7;

	const char* WeekDayNames[7] = { "������","ȭ����","������","�����","�ݿ���","�����","�Ͽ���" };
	printf("%d�� %d�� %d���� %s�Դϴ�.\n", Year, Month, Day, WeekDayNames[WeekDay]);
}


// �ָ��ǽ� 2


int CardValue(int Number)
{
	if(Number >= 2 && Number <= 10)
		return Number;
	if(Number >= 11 && Number <= 13)
		return 10;

	return 11;
}

int CardScore(Card1 hand[], int HandCount)
{
	int sum = 0;
	int AceCount = 0;

	for (int i = 0; i < HandCount; i++)
	{
		if (hand[i].Number == 1)
		{
			sum += 11;
			AceCount++;
		}
		else
		{
			sum += CardValue(hand[i].Number);
		}
	}
	while (sum > 21 && AceCount > 0)
	{
		sum -= 10;
		AceCount--;
	}

	return sum;
}

Card1 DrawCard()
{
	Card1 x;
	x.Number = rand() % 13 + 1;
	return x;
}

void PrintCard(Card1 x)
{
	if (x.Number == 1) printf("A ");
	else if (x.Number == 11) printf("J ");
	else if (x.Number == 12) printf("Q ");
	else if (x.Number == 13) printf("K ");
	else printf("%d ", x.Number);
}

void D0914_P2()
{
	srand(time(0));

	Card1 PlayerHand[10];
	Card1 DealerHand[10];
	
	int PlayerHandCount = 0;
	int DealerHandCount = 0;

	PlayerHand[PlayerHandCount++] = DrawCard();
	DealerHand[DealerHandCount++] = DrawCard();
	PlayerHand[PlayerHandCount++] = DrawCard();
	DealerHand[DealerHandCount++] = DrawCard();

	printf("����� ī�� : ");
	for (int i = 0; i < PlayerHandCount; i++)
	{
		PrintCard(PlayerHand[i]);
	}
	printf("\n���� : %d\n", CardScore(PlayerHand, PlayerHandCount));

	printf("������ ī�� : ");
	PrintCard(DealerHand[0]);
	printf(" ? \n\n");

	while (true)
	{
		int score = CardScore(PlayerHand, PlayerHandCount);
		if (score > 21)
		{
			printf("����� ���� : %d\n", score);
			printf("����Ʈ! ����� �����ϴ�.\n");
			return;
		}
		printf("ī�带 �� �ްڽ��ϱ�? (y/n) : ");
		char choice;
		std::cin >> choice;
		printf("\n");

		if (choice == 'y' || choice == 'Y')
		{
			PlayerHand[PlayerHandCount++] = DrawCard();
			printf("����� ī�� : ");
			for (int i = 0; i < PlayerHandCount; i++)
			{
				PrintCard(PlayerHand[i]);
			}
			printf("\n���� : %d\n", CardScore(PlayerHand, PlayerHandCount));
		}
		else if (choice == 'n' || choice == 'N')
		{
			break;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
		}
	}
	printf("\n������ ī�� : ");
	for (int i = 0; i < DealerHandCount; i++)
	{
		PrintCard(DealerHand[i]);
	}
	printf("\n���� : %d\n", CardScore(DealerHand, DealerHandCount));
	while (CardScore(DealerHand, DealerHandCount) < 17)
	{
		DealerHand[DealerHandCount++] = DrawCard();
		printf("������ ī�� : ");
		for (int i = 0; i < DealerHandCount; i++)
		{
			PrintCard(DealerHand[i]);
		}
		printf("\n���� : %d\n", CardScore(DealerHand, DealerHandCount));
	}

	int PlayerScore = CardScore(PlayerHand, PlayerHandCount);
	int DealerScore = CardScore(DealerHand, DealerHandCount);

	if (DealerScore > 21 || PlayerScore > DealerScore)
	{
		printf("����� �̰���ϴ�!\n");
	}
	else if (PlayerScore < DealerScore)
	{
		printf("������ �̰���ϴ�!\n");
	}
	else
	{
		printf("���º��Դϴ�!\n");
	}

}

