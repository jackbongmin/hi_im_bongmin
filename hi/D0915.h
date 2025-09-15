#pragma once
//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
// �ָ� �ǽ� 1 (���ϱ��ϱ�)


/// <summary>
/// ��¥�� �Է��ϸ� ������ �˷��ִ� �Լ�
/// </summary>
/// <param name="Year">����</param>
/// <param name="Month">��</param>
/// <param name="Day">��</param>
/// <returns>�ش� ���� ���ڿ�</returns>
const char* GetDayOfWeek(int Year, int Month, int Day);

/// <summary>
/// ���� �Ǻ� �Լ�
/// </summary>
/// <param name="Year">Ȯ���� ����</param>
/// <returns>�����̸� true, �ƴϸ� false</returns>
bool IsLeap(int Year);

/// <summary>
/// 1�� 1�� 1�Ͽ��� ��ĥ�� �������� ����ϴ� �Լ�
/// </summary>
/// <param name="Year">���</param>
/// <param name="Month">���</param>
/// <param name="Day">����</param>
/// <returns>��ü �ϼ�</returns>

int GetTotalDays(int Year, int Month, int Day);


void D0915_LastWeekP1();


//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
// �ָ� �ǽ� 2 (���� �����)

struct Card
{
	int Value;
	char Suit;

	// ����ü�ȿ� �ִ� �Լ��� �����ϰ� �ڽ��� �����͸� ����ϴ� ��쿡�� ����� ���� ����.
	bool IsAce() { return Value == 1; }
	int GetCardValue() { return Value > 10 ? 10 : Value; }
};

void PlayBlackjack();

void InitializeDeck(Card* InDeck);

void ShuffleDeck(Card* InDeck);

const Card& DrawCard1(Card* InDeck, int& InTop);
void AddCardToHand(Card* InHand, int& InCount, const Card& InCard);

void PrintHands(const Card* InPlayerHand, int InPlayerCount, const Card* InDealerHand, int InDealerCount, bool InRevealHole);
void PrintCard1(const Card& InCard);

void PrintPlayerHand(const Card* InHand, int InCount);
void PrintDealerHand(const Card* InHand, int InCount, bool inRevealHole);

void D0915_LastWeekP2();

bool IsBlackjack(const Card* InHand, int InCount);

int GetCardValue(const Card& InCard);

bool IsBust(Card* InHand, int InCount);
int GetBestScore(Card* InHand, int InCount);

bool IsSoft17(Card* InHand, int InCount);