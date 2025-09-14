#pragma once

// 林富角嚼 1

bool LeapYear(int year);

void D0914_P1();


// 林富角嚼2

struct Card
{
	int Number;
};

int CardValue(int Number);

int CardScore(Card hand[], int HandCount);

Card DrawCard();

void PrintCard(Card x);

void D0914_P2();