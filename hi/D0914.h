#pragma once

// 林富角嚼 1

bool LeapYear(int year);

void D0914_P1();


// 林富角嚼2

struct Card1
{
	int Number;
};

int CardValue(int Number);

int CardScore(Card1 hand[], int HandCount);

Card1 DrawCard();

void PrintCard(Card1 x);

void D0914_P2();