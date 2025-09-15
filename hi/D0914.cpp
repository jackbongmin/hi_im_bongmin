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

// 주말 실습1

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
	printf("년도를 입력하시오 : ");
	std::cin >> Year;
	printf("월을 입력하시오 : ");
	std::cin >> Month;
	printf("일을 입력하시오 : ");
	std::cin >> Day;

	int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int TotalDays = 0;

	// 년도
	for(int year=1;year<Year;year++ )
	{
		if (LeapYear(year) == true)
			TotalDays += 366;
		else
			TotalDays += 365;
	}

	// 월
	if(LeapYear(Year) == true)
		MonthDays[1] = 29;
	for (int month = 1; month < Month; month++)
	{
		TotalDays += MonthDays[month -1];
	}

	// 일
	TotalDays += (Day-1);

	// 요일
	int WeekDay = TotalDays % 7;

	const char* WeekDayNames[7] = { "월요일","화요일","수요일","목요일","금요일","토요일","일요일" };
	printf("%d년 %d월 %d일은 %s입니다.\n", Year, Month, Day, WeekDayNames[WeekDay]);
}


// 주말실습 2


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

	printf("당신의 카드 : ");
	for (int i = 0; i < PlayerHandCount; i++)
	{
		PrintCard(PlayerHand[i]);
	}
	printf("\n점수 : %d\n", CardScore(PlayerHand, PlayerHandCount));

	printf("딜러의 카드 : ");
	PrintCard(DealerHand[0]);
	printf(" ? \n\n");

	while (true)
	{
		int score = CardScore(PlayerHand, PlayerHandCount);
		if (score > 21)
		{
			printf("당신의 점수 : %d\n", score);
			printf("버스트! 당신이 졌습니다.\n");
			return;
		}
		printf("카드를 더 받겠습니까? (y/n) : ");
		char choice;
		std::cin >> choice;
		printf("\n");

		if (choice == 'y' || choice == 'Y')
		{
			PlayerHand[PlayerHandCount++] = DrawCard();
			printf("당신의 카드 : ");
			for (int i = 0; i < PlayerHandCount; i++)
			{
				PrintCard(PlayerHand[i]);
			}
			printf("\n점수 : %d\n", CardScore(PlayerHand, PlayerHandCount));
		}
		else if (choice == 'n' || choice == 'N')
		{
			break;
		}
		else
		{
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
		}
	}
	printf("\n딜러의 카드 : ");
	for (int i = 0; i < DealerHandCount; i++)
	{
		PrintCard(DealerHand[i]);
	}
	printf("\n점수 : %d\n", CardScore(DealerHand, DealerHandCount));
	while (CardScore(DealerHand, DealerHandCount) < 17)
	{
		DealerHand[DealerHandCount++] = DrawCard();
		printf("딜러의 카드 : ");
		for (int i = 0; i < DealerHandCount; i++)
		{
			PrintCard(DealerHand[i]);
		}
		printf("\n점수 : %d\n", CardScore(DealerHand, DealerHandCount));
	}

	int PlayerScore = CardScore(PlayerHand, PlayerHandCount);
	int DealerScore = CardScore(DealerHand, DealerHandCount);

	if (DealerScore > 21 || PlayerScore > DealerScore)
	{
		printf("당신이 이겼습니다!\n");
	}
	else if (PlayerScore < DealerScore)
	{
		printf("딜러가 이겼습니다!\n");
	}
	else
	{
		printf("무승부입니다!\n");
	}

}

