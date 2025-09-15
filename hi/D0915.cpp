#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include "fstream"
#include "D0915.h"
#include <iostream>
#include <random>
#include "direct.h"

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
// �ָ� �ǽ� 1

// �� ���� ��¥
const int DaysInMonth[12] = { 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31 };

// ����
const char* Week[7] = { "������", "ȭ����", "������", "�����", "�ݿ���", "�����", "�Ͽ���" };


const char* GetDayOfWeek(int Year, int Month, int Day)
{
	int Days = GetTotalDays(Year, Month, Day);
	return Week[Days % 7];
}

bool IsLeap(int Year)
{
	// 4�� ����� �����̴�. �׸��� 100�� ����� ������ �ƴϴ�.
	// �׷��� 400�� ����� �����̴�.
	// (Year % 4 == 0) : 4�� ����̴�. -> �����̴�.
	// (Year % 100 != 0) : 100�� ����� �ƴϴ� -> �����̴�.
	// (Year % 400 == 0) : 400�� ����̴� -> �����̴�.
	
	// 4�� ����̰� 100�� ����� �ƴϰų� 400�� ����� �����̴�.
	return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
}

int GetTotalDays(int Year, int Month, int Day)
{
	int Days = 0;
	
	for (int Y = 1; Y < Year; Y++)
	{
		Days += (IsLeap(Y) ? 366 : 365);	// �����̸� 366�� �߰�, �ƴϸ� 365�� �߰�
	}
	
	for (int M = 1; M < Month; M++)
	{
		Days += DaysInMonth[M - 1];
		if (M == 2 && IsLeap(Year))
		{
			Days += 1;			 			// �����̸� 2���� �� �Ϸ� �߰�
		}
	}

	Days += (Day - 1);

	return Days;
}

void D0915_LastWeekP1()
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
	printf("��¥�� �Է� �ϼ���.(�� : 2025 9 15) : ");
	std::cin >> Year >> Month >> Day;
	printf("�ش� ��¥�� [%s]�Դϴ�.\n", GetDayOfWeek(Year, Month, Day));


}

//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
void D0915_LastWeekP2()
{
	PlayBlackjack();
}

const int MaxHand = 12; // 1*4, 2*4, 3*4

void PlayBlackjack()
{
	Card Deck[52];
	int DeckTop = 0;
	InitializeDeck(Deck);	// �� ����
	ShuffleDeck(Deck);		// �� ����

	// �÷��̾�� ������ ī�� 2�徿 ����
	Card DealerHand[MaxHand];
	int DealerCount = 0;
	Card PlayerHand[MaxHand];
	int PlayerCount = 0;
	AddCardToHand(PlayerHand, PlayerCount, DrawCard1(Deck, DeckTop));	
	AddCardToHand(DealerHand, DealerCount, DrawCard1(Deck, DeckTop));
	AddCardToHand(PlayerHand, PlayerCount, DrawCard1(Deck, DeckTop));
	AddCardToHand(DealerHand, DealerCount, DrawCard1(Deck, DeckTop));

	// �÷��̾�� ������ ���� ī�� ���(������ ������ �����)
	PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, false);

	// �����̸� ���̴ϱ� ������ �ִ��� ���� Ȯ��
	bool IsPlayerBlackjack = IsBlackjack(PlayerHand, PlayerCount);
	bool IsDealerBlackjack = IsBlackjack(DealerHand, DealerCount);
	if (IsPlayerBlackjack && IsDealerBlackjack)
	{
		printf("�� �� ����! ���º�!\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
	}
	else if (IsPlayerBlackjack)
	{
		printf("�÷��̾ �����Դϴ�! �¸�!\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
	}
	else if (IsDealerBlackjack)
	{
		printf("������ �����Դϴ�. �й�...\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
	}
	else
	{
		// ���� ���� ����. �÷��̾� �� ����.
		bool IsPlayerStand = false;
		while (!IsPlayerStand && !IsBust(PlayerHand, PlayerCount)) // ���ĵ� ���߰� ����Ʈ ���ϸ� ���
		{
			printf("�÷��̾� ���� : %d\n", GetBestScore(PlayerHand, PlayerCount));
			printf("Hit(1) / Stand(2)? :");
			int Input = 0;
			std::cin >> Input;
			if (Input == 1)
			{
				AddCardToHand(PlayerHand, PlayerCount, DrawCard1(Deck, DeckTop));
				PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, false);
				if (IsBust(PlayerHand, PlayerCount))
				{
					printf("�÷��̾� ����Ʈ! �й�!\n");
					PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
					return;	// ���� ����
				}
			}
			else
			{
				IsPlayerStand = true;
			}
		}

		// ���� �� ����
		printf("���� �� ����....\n");
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
		while (GetBestScore(DealerHand, DealerCount) < 17)
		{
			if (IsSoft17(DealerHand, DealerCount))
				break;
			AddCardToHand(DealerHand, DealerCount, DrawCard1(Deck, DeckTop));
			printf("���� ī�� : ");
			PrintDealerHand(DealerHand, DealerCount, true);
			printf("\n");

			if (IsBust(DealerHand, DealerCount))
			{
				printf("���� ����Ʈ! �÷��̾� �¸�!\n");
				return;
			}
		}

		// ���� Ȯ��
		int PlayerScore = GetBestScore(PlayerHand, PlayerCount);
		int DealerScore = GetBestScore(DealerHand, DealerCount);
		PrintHands(PlayerHand, PlayerCount, DealerHand, DealerCount, true);
		printf("�÷��̾� ����: %d, ���� ����:%d\n", PlayerScore, DealerScore);
		if (PlayerScore > DealerScore)
		{
			printf("�÷��̾� �¸�!\n");
		}
		else if (PlayerScore < DealerScore)
		{
			printf("���� �¸�!\n");
		}
		else
		{
			printf("���º�!\n");
		}
	}
}

void InitializeDeck(Card* Deck)
{
	const char SuitShape[4] = {'S', 'H', 'D', 'C'};
	int Index = 0;
	for (int Value = 0; Value < 13; Value++)
	{
		for (int Suit = 0; Suit < 4; Suit++)
		{
			//Deck[Index] = { Value + 1, SuitShape[Suit] };
			Deck[Index].Value = Value + 1;
			Deck[Index].Suit = SuitShape[Suit];
			Index++;
		}
	}
}

void ShuffleDeck(Card* Deck)
{
	for(int i = 51; i>0;i--)
	{
		int j = rand() % (i + 1);
		Card Temp = Deck[i];
		Deck[i] = Deck[j];
		Deck[j] = Temp;
	}
}

const Card& DrawCard1(Card* InDeck, int& InTop)
{
	if (InTop >= 52)
	{
		ShuffleDeck(InDeck);
		InTop = 0;
	}
	return InDeck[InTop++];
}

void AddCardToHand(Card* InHand, int& InCount, const Card& InCard)
{
	if (InCount < MaxHand)
	{
		InHand[InCount] = InCard;
		InCount++;
	}
}

void PrintHands(const Card* InPlayerHand, int InPlayerCount, const Card* InDealerHand, int InDealerCount, bool InRevealHole)
{
	printf("�÷��̾� ī�� : ");
	PrintPlayerHand(InPlayerHand, InPlayerCount);
	printf("\n���� ī�� : ");
	PrintDealerHand(InDealerHand, InDealerCount, InRevealHole);
	printf("\n");
}

void PrintCard1(const Card& InCard)
{
	const char* ValueStrs[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	printf("%c%s", InCard.Suit, ValueStrs[InCard.Value - 1]);
}

void PrintPlayerHand(const Card* InHand, int InCount)
{
	for (int i = 0; i < InCount; i++)
	{
		PrintCard1(InHand[i]);
		printf(" ");
	}
}

void PrintDealerHand(const Card* InHand, int InCount, bool InRevealHole)
{
	for (int i = 0; i < InCount; i++)
	{
		if (i == 1 && !InRevealHole)
		{
			printf("??");
		}
		else
		{
			PrintCard1(InHand[i]);
		}
		printf(" ");
	}
}

bool IsBlackjack(const Card* InHand, int InCount)
{
	// A + 10(10, J, Q, K)�� ������ ���� ����
	bool Result = false;
	if (InCount == 2)	// �ϴ� ����
	{
		//if (InHand[0].Value == 1 || InHand[1].Value == 1)	// Ace�� �־�� ��
		//{
		//	if (GetCardValue(InHand[0]) == 10 || GetCardValue(InHand[1]) == 10) // 10�� �־�� ��
		//	{
		//		Result = true;
		//	}
		//}

		if (InHand[0].Value == 1 && GetCardValue(InHand[1]) == 10		// �ϳ��� Ace�� �������� 10�̴�.
			|| InHand[1].Value == 1 && GetCardValue(InHand[0]) == 10)
		{
			Result = true;
		}
	}

	return Result;
}

int GetCardValue(const Card& InCard)
{
	int Value = InCard.Value;	// �ϴ� Ace�� 1�� ó��
	if (Value > 10)
	{
		Value = 10; // J,Q,K = 10
	}
	
	return Value;
}

bool IsBust(Card* InHand, int InCount)
{
	return GetBestScore(InHand, InCount) > 21;
}

int GetBestScore(Card* InHand, int InCount)
{
	int Sum = 0;
	int AceCount = 0;
	for (int i = 0; i < InCount; i++)
	{
		Sum += GetCardValue(InHand[i]);
		if (InHand[i].IsAce())
		{
			AceCount++;
		}
	}

	// AceCount�� �����ְ� 10�� �������ѵ� ����Ʈ�� �ȵǸ� Ace�ϳ��� 11�� ����ϱ�
	while ((AceCount > 0) && ((Sum + 10) <= 21))
	//while ((AceCount > 0) && (Sum < 12))
	{
		Sum += 10;
		AceCount--;
	}
	return Sum;
}

bool IsSoft17(Card* InHand, int InCount)
{
	int Sum = 0;
	for (int i = 0; i < InCount; i++)
	{
		Sum += GetCardValue(InHand[i]);
		if (InHand[i].IsAce())
		{
			Sum += 10;
		}
	}
	return Sum >= 17;
}








