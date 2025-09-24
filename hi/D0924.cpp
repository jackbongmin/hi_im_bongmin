#include "D0924.h"
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <unordered_map>

bool operator<(const SortTest& Left, const SortTest& Right)
{
	return Left.a < Right.a;
}

void PrintVector(std::vector<int>& InVector)
{
	printf("Vector : ");
	for (int n : InVector)
	{
		printf("%d ", n);
	}
	printf("\n");
}

void PrintVector(std::vector<SortTest>& InVector)
{
	printf("Vector : ");
	for (const SortTest& n : InVector)
	{
		printf("(%d, %.1f) ", n.a, n.b);
	}
	printf("\n");
}

void D0924::TestLambda()
{
	std::vector<int> Numbers = { 5,7,1,9,3 };
	//std::sort(Numbers.begin(), Numbers.end());	// 오름차순 정렬
	PrintVector(Numbers);

	std::sort(Numbers.begin(), Numbers.end(),
		[](int a, int b)
		{
			return a > b;	// 내림차순 정렬
		}
	);
	PrintVector(Numbers);
}

void D0924::TestLambda2()
{
	std::vector<SortTest> Test = { {1, 5.0f}, {7, 3.5f}, {5, 10.0f} };
	PrintVector(Test);
	std::sort(Test.begin(), Test.end());
	PrintVector(Test);
	std::sort(Test.begin(), Test.end(),
		[](const SortTest& first, const SortTest& second)
		{
			return first.b < second.b;
		}
	);
	PrintVector(Test);

}

void D0924::TestLambdaPractice()
{
	/*
	간단 실습
	1. 람다로 SortTest의 a, b 내림차순 정렬 각각 만들어보기
	*/

	std::vector<SortTest> Test = { {1, 5.0f}, {7, 3.5f}, {5, 10.0f} };
	std::sort(Test.begin(), Test.end(),
		[](const SortTest& first, const SortTest& second)
		{
			return first.a > second.a;
		}
	);
	PrintVector(Test);

	std::sort(Test.begin(), Test.end(),
		[](const SortTest& first, const SortTest& second)
		{
			return first.b > second.b;
		}
	);
	PrintVector(Test);

	/*
	 2. 특정 조건을 만족하는 첫번째 원소 찾기
	 [](int n)
	 { return 참/거짓; }
	*/

	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int Threshold = 5;	// threshold보다 큰 첫번째 원소 찾기
	std::vector<int>::iterator iter = std::find_if(numbers.begin(), numbers.end(), 
		[Threshold](int n)
		{

			return Threshold < n;	// 캡쳐한 Threshold보다 크면 true
		}
	);
	if (iter != numbers.end())
	{
		// 찾았다.
		printf("% d보다 큰 첫번째 원소는 % d입니다.\n", Threshold, *iter);
	}
}

void PrintSet(const std::set<int>& InSet)
{
	printf("Set : ");
	for (int n : InSet)
	{
		printf("%d ", n);
	}
	printf("\n");
}


void D0924::TestSet()
{
	// #include<set> 필수
	std::set<int> TestSet;
	printf("\nset에 추가히기\n");
	TestSet.insert(30);
	TestSet.insert(10);
	TestSet.insert(50);
	TestSet.insert(20);
	TestSet.insert(30);	// 무시됨
	PrintSet(TestSet);



	printf("set의 크기\n");
	printf("size : %d\n", static_cast<int>(TestSet.size()));



	printf("원소 찾기\n");
	const int Target = 20;
	std::set<int>::iterator iter = TestSet.find(Target);	// 존재 확인 + 값도 확인
	if (iter != TestSet.end())
	{
		// 찾았다.
		printf("find : %d를 찾았습니다.\n", Target);
	}
	else
	{
		// 못찾았다.
		printf("find : %d를 못찾았습니다.\n", Target);
	}



	bool IsFind = TestSet.contains(Target);					// Target이 있는지 없는지 확인하는 함수
	if (IsFind)
	{
		// 찾았다.
		printf("contains : %d를 찾았습니다.\n", Target);
	}
	else
	{
		// 못찾았다.
		printf("contains : %d를 못찾았습니다.\n", Target);
	}


	printf("\n삭제하기\n");

	TestSet.erase(30);
	PrintSet(TestSet);


	printf("\n전부삭제하기\n");
	TestSet.clear();
	PrintSet(TestSet);

	
	printf("\nset이 비었는지 안비었는지 확인하기\n");
	if (TestSet.empty())
	{
		// 비었다.
		printf("비어있다.");
	}
	else
	{
		// 안비었다.
		printf("안비어있다.");
	}
}

void D0924::TestSetPractice()
{
	/*
	1. 중복 없는 정수 입력 및 출력
		사용자가 여러 개의 정수를 입력하면 중복 없이 저장하고 출력하는 프로그램을 만들어보세요.
	2. 집합 연산(합집합, 교집합, 차집합)
		두 개의 set을 만들어서 합집합, 교집합, 차집합을 구하는 실습을 해보세요.
	3. 특정 값의 존재 여부 확인
		set에 특정 값이 들어있는지 검사하는 프로그램을 만들어보세요.
	4. 오름차순/내림차순 출력
		set의 원소를 오름차순 또는 내림차순으로 출력하는 실습을 해보세요.(반복자의 종류)
	5. 문자열 중복 제거
		여러 개의 문자열을 입력받아 중복 없이 저장하고 출력하는 실습을 해보세요.
	6. 최댓값, 최솟값 찾기
		set에서 가장 큰 값과 작은 값을 찾아 출력하는 실습을 해보세요.
	7. set을 vector로 변환
		set에 저장된 값을 vector로 옮겨서 활용하는 프로그램을 만들어보세요.
	*/

	printf("\n1. 중복 없는 정수 입력 및 출력\n");
	std::set<int> TestSet1;
	int i_p1 = 0;
	int ExitNumber_p1 = -1;

	while (i_p1 != ExitNumber_p1)
	{
		printf("수를 입력하시오(-1을 입력하면 종료) : ");
		std::cin >> i_p1;
		if (i_p1 != ExitNumber_p1)
		{
			TestSet1.insert(i_p1);
		}
	}

	PrintSet(TestSet1);
	printf("\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

	printf("\n2. 집합 연산(합집합, 교집합, 차집합)\n");
	std::set<int> TestSet2_1 = { 10,20,30,40,50 };
	std::set<int> TestSet2_2 = { 10,30,50,70,90 };
	std::set<int> TestSet2Union;
	std::set<int> TestSet2Intersection;
	std::set<int> TestSet2Difference;


	PrintSet(TestSet2_1);
	PrintSet(TestSet2_2);

	for (int n : TestSet2_1)
	{
		TestSet2Union.insert(n);
	}
	for (int n : TestSet2_2)
	{
		TestSet2Union.insert(n);
	}
	printf("합집합 : ");
	PrintSet(TestSet2Union);

	for (int n : TestSet2_1)
	{
		if (TestSet2_2.contains(n))
		{
			TestSet2Intersection.insert(n);
		}
	}
	printf("교집합 : ");
	PrintSet(TestSet2Intersection);
	
	TestSet2Difference = TestSet2_2;
	for (int n : TestSet2_1)
	{
		if (TestSet2_2.contains(n))
		{
			TestSet2Difference.erase(n);
		}
	}
	printf("차집합 : ");
	PrintSet(TestSet2Difference);
	printf("\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

	printf("\n3. 특정 값의 존재 여부 확인\n");
	std::set<int> TestSet3 = { 10,20,30,40,50 };

	const int Test3_Target = 30;
	std::set<int>::iterator iter = TestSet3.find(Test3_Target);
	if (iter != TestSet3.end())
	{
		// 찾았다.
		printf("find : %d를 찾았습니다.\n", Test3_Target);
	}
	else
	{
		// 못찾았다.
		printf("find : %d를 못찾았습니다.\n", Test3_Target);
	}
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

	printf("\n4. 오름차순/내림차순 출력\n");
	std::set<int> TestSet4 = { 10,20,30,40,50 };
	printf("오름차순 출력: ");
	PrintSet(TestSet4);

	printf("내림차순 출력: ");
	printf("Set : ");
	for (auto iter = TestSet4.rbegin(); iter != TestSet4.rend(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");


	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("\n5. 문자열 중복 제거\n");
	std::set<char> TestSet5;
	char ExitNumber5 = 'x';
	char i_p5 = 0;
	while (i_p5 != ExitNumber5)
	{
		printf("문자열을 입력하시오(x를 입력하면 종료 : ");
		std::cin >> i_p5;
		if (i_p5 != ExitNumber5)
		{
			TestSet5.insert(i_p5);
		}
	}
	for (int n : TestSet5)
	{
		printf("%c ", n);
	}
	printf("\n");


	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("\n6. 최댓값, 최솟값 찾기\n");
	std::set<int> TestSet6 = { 5,7,6,25,8,87,65,2,4,7,52 };
	PrintSet(TestSet6);
	if (!TestSet6.empty())
	{
		printf("최대값 = %d, 최소값 = %d\n", *TestSet6.begin(), *TestSet6.rbegin());
	}

	
	
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("\n7. set을 vector로 변환\n");
	std::set<int> TestSet7_1 = { 10,20,30,40,50 };
	std::vector<int> TestSet7_2;

	for (int n : TestSet7_1)
	{
		TestSet7_2.push_back(n);
	}

	printf("Vector : ");
	for (int n : TestSet7_2)
	{
		printf("%d ", n);
	}
	printf("\n");


}

std::string ToString(CharacterType InType)
{
	switch (InType)
	{
	case CharacterType::Warrior:
		return "전사";
	case CharacterType::Mage:
		return "마법사";
	case CharacterType::Archer:
		return "궁수";
	case CharacterType::Thief:
		return "도적";
	default:
		break;
	}
	return "알 수 없음";
}
void PrintStatus(const CharacterStatus& InStatus)
{
	printf(" | 레벨 : %2d | 체력 : %3d | 공격력 : %2d\n", InStatus.Level, InStatus.Health, InStatus.Attack);
}

void D0924::TestMap()
{
	std::map<CharacterType, CharacterStatus> Characters;

	Characters[CharacterType::Warrior] = { 10, 200, 15 };
	Characters[CharacterType::Mage] = { 8, 100, 5 };
	Characters[CharacterType::Archer] = { 12, 150, 20 };

	if (Characters.contains(CharacterType::Mage))	// 없는 키에 접근하는 것을 방지하기 위해 반드시 체크해야 한다.
	{
		// 있다.
		CharacterStatus& MageStatus = Characters[CharacterType::Mage]; // []연산자로 Value에 접근
		printf("\n[] 접근법 : %s", ToString(CharacterType::Mage).c_str());
		PrintStatus(MageStatus);
	}
	else
	{
		// 없다.
	}

	// 없는 항목에 접근하면 새 항목이 생긴다.
	CharacterStatus& ThiefStatus = Characters[CharacterType::Thief];
	printf("[] 없는 키 접근 : %s", ToString(CharacterType::Thief).c_str());
	PrintStatus(ThiefStatus);

	printf("\n전체 캐릭터 출력\n");
	for (const auto& pair : Characters)
		//for( const std::pair<CharacterType, CharacterStatus>& pair : Characters)
	{
		printf("캐릭터 타입 : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = 키, second = value
	}

	printf("\n도적 삭제\n");
	Characters.erase(CharacterType::Thief);

	printf("\n전체 캐릭터 출력\n");
	for (const auto& pair : Characters)
	{
		printf("캐릭터 타입 : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = 키, second = value
	}

	printf("\n전체 삭제\n");
	Characters.clear();
	printf("\n전체 캐릭터 출력\n");
	for (const auto& pair : Characters)
	{
		printf("캐릭터 타입 : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = 키, second = value
	}

	int i = 0;

}

void D0924::TestUnorderedMap()
{
	std::unordered_map<SortTest, std::string> TestMap;
	SortTest Test1 = { 1, 2.5f };
	SortTest Test2 = { 3, 1.5f };
	TestMap[Test1] = "Hello";
	TestMap[Test2] = "World";
	// 키값은 Hash 함수가 있어야 한다.
	// 키값이 같은지 비교할 수 있도록 == 연산자가 있어야 한다.
	int i = 0;
}
