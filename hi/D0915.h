#pragma once
//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 주말 실습 1 (요일구하기)


/// <summary>
/// 날짜를 입력하면 요일을 알려주는 함수
/// </summary>
/// <param name="Year">연도</param>
/// <param name="Month">월</param>
/// <param name="Day">일</param>
/// <returns>해당 요일 문자열</returns>
const char* GetDayOfWeek(int Year, int Month, int Day);

/// <summary>
/// 윤년 판별 함수
/// </summary>
/// <param name="Year">확인할 연도</param>
/// <returns>윤년이면 true, 아니면 false</returns>
bool IsLeap(int Year);

/// <summary>
/// 1년 1월 1일에서 며칠이 지났는지 계산하는 함수
/// </summary>
/// <param name="Year">몇년</param>
/// <param name="Month">몇월</param>
/// <param name="Day">몇일</param>
/// <returns>전체 일수</returns>

int GetTotalDays(int Year, int Month, int Day);


void D0915_LastWeekP1();


//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 주말 실습 2 (블랙잭 만들기)

struct Card
{
	int Value;
	char Suit;

	// 구조체안에 있는 함수는 순수하게 자신의 데이터만 사용하는 경우에만 만드는 것이 좋다.
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