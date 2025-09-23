#include "D0923.h"
#include "Coordinate.h"
#include "Calcurator.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>


void D0923::TestTemplateClass()
{
	Coordinate<int> PositionInt(1, 3);
	Coordinate<float> PositionFloat(0.05f, 5.7f);

	printf("PositionInt : %d, %d\n", PositionInt.x, PositionInt.y);
	printf("PositionFloat : %f, %f\n", PositionFloat.x, PositionFloat.y);
}

void D0923::TestCalcurator()
{
	Calcurator Calc;
	int ResultInt = Calc.Add(1, 3);
	float ResultFloat = Calc.Add(2.5f, 7.3f);
	Coordinate<int> ResultCoord = Calc.Add(Coordinate<int>(1, 2), Coordinate<int>(3, 4));

	ResultInt = Calc.Multiply(5, 3);
	ResultFloat = Calc.Multiply(3.5f, 2.0f);
	ResultCoord = Calc.Multiply(Coordinate<int>(1, 2), Coordinate<int>(3, 4));

	ResultFloat = Calc.Add(2.5f, 7.3f);
	bool ResultBool = Calc.Equal(9.8f, ResultFloat);
	bool ResultBool2 = (9.8 == ResultFloat);

	int i = 0;
}

void D0923::TestVector()
{
	// #include <vector> 필수
	std::vector<int> Scores;	// int배열 scores를 만듬
	Scores.reserve(5);			// 내가 사용할 것으로 예상되는 최대 크기를 적는 것이 좋음

	Scores.push_back(10);		// vector의 뒤에 추가
	Scores.push_back(20);
	Scores.push_back(30);

	// 특정 값으로 초기화된 vector를 만들고 싶을때(3개가 "무명"으로 초기화된 vector)
	std::vector<std::string> Name(3, "무명");

	printf("첫번째 점수 : %d\n", Scores[0]);		// 배열 사용하듯이 사용. 다만 범위를 벗어나면 터진다
	//printf("네번째 점수 : %d\n", Scores[3]);		// 터짐
	printf("두번째 점수 : %d\n", Scores.at(1));		// 두번째 요소에 접근
	//printf("네번째 점수 : %d\n", Scores.at(3));	// 네번째 요소에 접근(=예외를 발생)
	printf("세번째 점수 : %d\n", Scores.back());	// 마지막 요소에 접근
	printf("첫번째 점수 : %d\n", Scores.front());	// 첫번째 요소에 접근



// 일반적인 순회 방식
printf("모든 점수 : ");
for (int i = 0; i < Scores.size(); i++)
{
	printf("%d ", Scores[i]);
}
printf("\n");

// 반복자를 통한 순회 방식
printf("모든 점수 : ");
for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
{
	printf("%d ", *iter);	// 현재 iter위치에 있는 값을 출력
}
printf("\n");


// 용량 확인(Size, Capacity)
// Size : 현재 vector에서 실제 사용되는 값이 들어있는 개수
// Capacity : 현재 vector에 할당된 메모리 개수(실제 사용하지 않은 것도 포함)

printf("현재 점수 개수(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
printf("할당된 메모리(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));


// 삭제하기 : 뒤에서 삭제하는 것이 좋다.
Scores.pop_back(); // 마지막 원소 하나 제거
printf("모든 점수 : ");
for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
{
	printf("%d ", *iter);
}
printf("\n");

Scores.clear();	// 모든 원소 제거(Size는 0, Capacity는 그대로)
printf("모든 점수 : ");
for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
{
	printf("%d ", *iter);
}
printf("\n");
printf("현재 점수 개수(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
printf("할당된 메모리(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));

if (Scores.empty())
{
	printf("Scores가 비었다.\n");
}

// 중간에 추가 삭제하는 함수.(어지간하면 쓰지 말것)
//Scores.insert();
//Scores.erase();


// 스왑 앤 팝
std::vector<int> Numbers = { 10,20,30,40,50 };
int DeleteNumber = 20;

std::vector<int>::iterator FindIter = std::find(Numbers.begin(), Numbers.end(), DeleteNumber);
if (FindIter != Numbers.end())
{
	// 찾았다.
	*FindIter = Numbers.back();		// 찾은 위치에 마지막 값을 넣어라.
	Numbers.pop_back();				// 마지막 요소 제거

}
else
{
	// 없다.
}

int i = 0;
}

void D0923::TestVectorPractice()
{
	/*
	실습
	1. 정수 입력받고 출력하기
	2. 최대, 최소 구하기
	3. 정렬하기
	4. 특정 값 찾기.
	5. 중복 제거하기
	6. 벡터 합치기
	7. 문자열 뒤집기
	8. 모든 요소 더하기
	*/

	// 1. 정수 입력받고 출력하기
	printf("1. 정수 입력받고 출력하기\n\n");
	std::vector<int> Practice1;
	Practice1.reserve(10);
	
	constexpr int ExitNumber = -1;
	int i = 0;

	while (i != ExitNumber)
	{
		printf("숫자를 입력하세요(-1이면 종료) : ");
		std::cin >> i;
		if (i != ExitNumber)
		{
		Practice1.push_back(i);
		}
	}

	printf("Practice : ");
	for (auto iter = Practice1.begin(); iter != Practice1.end(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");
	printf("\n");

	// 2. 최대 최소 구하기
	printf("2. 최대 최소 구하기\n\n");

	std::vector<int> Practice2 = { 10,20,30,40,50 };
	Practice2.reserve(5);

	int MaxNumber_0923 = INT_MIN;
	int MinNumber_0923 = INT_MAX;
	
	for (auto iter = Practice2.begin(); iter != Practice2.end(); iter++)
	{
		if (MaxNumber_0923 < *iter)
		{
			MaxNumber_0923 = *iter;
		}
		if (MinNumber_0923 > *iter)
		{
			MinNumber_0923 = *iter;
		}
	}
	printf("Practice2 : ");
	for (auto iter = Practice2.begin(); iter != Practice2.end(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");
	printf("최대값 : %d, 최소값 : %d\n", MaxNumber_0923, MinNumber_0923);
	printf("\n");


	// 3. 정렬하기
	printf("3. 정렬하기\n\n");

	std::vector<int> Practice3 = { 5, 1, 3, 2, 4 };
	Practice3.reserve(5);
	
	printf("Practice3 : 5 1 3 2 4\n");

	std::sort(Practice3.begin(), Practice3.end());
	printf("Practice3_sort : ");
	for (auto iter = Practice3.begin(); iter != Practice3.end(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");
	printf("\n");



	// 4. 특정 값 찾기
	printf("4. 특정 값 찾기\n\n");

	std::vector<int> Practice4 = { 1,2,3,4,5 };
	Practice4.reserve(5);

	printf("찾을 값을 입력하시오 : ");
	int SearchNumber_0923 = 0;
	std::cin >> SearchNumber_0923;

	int index_0923 = 0;
	bool Found_0923 = false;
	for (auto iter = Practice4.begin(); iter != Practice4.end(); iter++, index_0923++)
	{
		if (SearchNumber_0923 == *iter)
		{
			printf("찾는 값은 %d번째에 있습니다.\n", index_0923+1);
			Found_0923 = true;
			break;
		}
	}
	if(!Found_0923)
	{
		printf("입력하신 값이 없습니다.");
		return;
	}

	// 5. 중복값 제거
	printf("5. 중복값 제거하기\n\n");

	std::vector<int> Practice5 = { 10,20,30,30,40,50,30,40 };
	std::vector<int> Result5;
	Result5.reserve(Practice5.size());

	for (int n : Practice5)
	{
		auto iter = std::find(Result5.begin(), Result5.end(), n);
		if(iter == Result5.end())
		{
			Result5.push_back(n);
		}
	}
	//Practice5 = Result5;
	std::sort(Practice5.begin(), Practice5.end());					// unique를 쓰기 위해서는 정렬되어 있어야 한다.
	auto last = std::unique(Practice5.begin(), Practice5.end());	// 중복되는 값들은 뒤로 보내고 중복되기 전 마지막을 리턴
	Practice5.erase(last, Practice5.end());							// 중복되던 부분들을 실제로 삭제

	printf("중복제거 결과 : ");
	for (int n : Practice5)
	{
		printf("$d", n);
	}
	printf("\n\n");


	// 6. 벡터 합치기
	printf("6. 벡터 합치기\n\n");

	std::vector<int> Practice6_1 = { 10,20,30 };
	std::vector<int> Practice6_2 = { 100,200,300 };
	std::vector<int> Result6(Practice6_1);

	for (int n : Practice6_2)
	{
		Result6.push_back(n);
	}



	// 7. 문자열 뒤집기
	printf("7. 문자열 뒤집기\n\n");

	printf("문자열을 입력하세요 : ");
	std::string InputWord;
	std::cin >> InputWord;
	std::vector<char> chars(InputWord.begin(), InputWord.end());
	printf("뒤집힌 결과 : ");
	for (auto rIter = chars.rbegin(); rIter != chars.rend(); rIter++)
	{
		printf("%c", *rIter);
	}
	printf("\n\n");

	//std::reverse(chars.begin(), chars.end());

	// 8. 모든 요소 더하기
	printf("8. 모든 요소 더하기기\n\n");

	std::vector<int> Practice8;
	Practice8.reserve(5);



	
}	