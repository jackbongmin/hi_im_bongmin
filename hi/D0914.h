#pragma once

// �ָ��ǽ� 1

bool LeapYear(int year);

void D0914_P1();


// �ָ��ǽ�2

struct Card
{
	int Number;
};

int CardValue(int Number);

int CardScore(Card hand[], int HandCount);

Card DrawCard();

void PrintCard(Card x);

void D0914_P2();