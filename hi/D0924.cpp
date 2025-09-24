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
	//std::sort(Numbers.begin(), Numbers.end());	// �������� ����
	PrintVector(Numbers);

	std::sort(Numbers.begin(), Numbers.end(),
		[](int a, int b)
		{
			return a > b;	// �������� ����
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
	���� �ǽ�
	1. ���ٷ� SortTest�� a, b �������� ���� ���� ������
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
	 2. Ư�� ������ �����ϴ� ù��° ���� ã��
	 [](int n)
	 { return ��/����; }
	*/

	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int Threshold = 5;	// threshold���� ū ù��° ���� ã��
	std::vector<int>::iterator iter = std::find_if(numbers.begin(), numbers.end(), 
		[Threshold](int n)
		{

			return Threshold < n;	// ĸ���� Threshold���� ũ�� true
		}
	);
	if (iter != numbers.end())
	{
		// ã�Ҵ�.
		printf("% d���� ū ù��° ���Ҵ� % d�Դϴ�.\n", Threshold, *iter);
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
	// #include<set> �ʼ�
	std::set<int> TestSet;
	printf("\nset�� �߰�����\n");
	TestSet.insert(30);
	TestSet.insert(10);
	TestSet.insert(50);
	TestSet.insert(20);
	TestSet.insert(30);	// ���õ�
	PrintSet(TestSet);



	printf("set�� ũ��\n");
	printf("size : %d\n", static_cast<int>(TestSet.size()));



	printf("���� ã��\n");
	const int Target = 20;
	std::set<int>::iterator iter = TestSet.find(Target);	// ���� Ȯ�� + ���� Ȯ��
	if (iter != TestSet.end())
	{
		// ã�Ҵ�.
		printf("find : %d�� ã�ҽ��ϴ�.\n", Target);
	}
	else
	{
		// ��ã�Ҵ�.
		printf("find : %d�� ��ã�ҽ��ϴ�.\n", Target);
	}



	bool IsFind = TestSet.contains(Target);					// Target�� �ִ��� ������ Ȯ���ϴ� �Լ�
	if (IsFind)
	{
		// ã�Ҵ�.
		printf("contains : %d�� ã�ҽ��ϴ�.\n", Target);
	}
	else
	{
		// ��ã�Ҵ�.
		printf("contains : %d�� ��ã�ҽ��ϴ�.\n", Target);
	}


	printf("\n�����ϱ�\n");

	TestSet.erase(30);
	PrintSet(TestSet);


	printf("\n���λ����ϱ�\n");
	TestSet.clear();
	PrintSet(TestSet);

	
	printf("\nset�� ������� �Ⱥ������ Ȯ���ϱ�\n");
	if (TestSet.empty())
	{
		// �����.
		printf("����ִ�.");
	}
	else
	{
		// �Ⱥ����.
		printf("�Ⱥ���ִ�.");
	}
}

void D0924::TestSetPractice()
{
	/*
	1. �ߺ� ���� ���� �Է� �� ���
		����ڰ� ���� ���� ������ �Է��ϸ� �ߺ� ���� �����ϰ� ����ϴ� ���α׷��� ��������.
	2. ���� ����(������, ������, ������)
		�� ���� set�� ���� ������, ������, �������� ���ϴ� �ǽ��� �غ�����.
	3. Ư�� ���� ���� ���� Ȯ��
		set�� Ư�� ���� ����ִ��� �˻��ϴ� ���α׷��� ��������.
	4. ��������/�������� ���
		set�� ���Ҹ� �������� �Ǵ� ������������ ����ϴ� �ǽ��� �غ�����.(�ݺ����� ����)
	5. ���ڿ� �ߺ� ����
		���� ���� ���ڿ��� �Է¹޾� �ߺ� ���� �����ϰ� ����ϴ� �ǽ��� �غ�����.
	6. �ִ�, �ּڰ� ã��
		set���� ���� ū ���� ���� ���� ã�� ����ϴ� �ǽ��� �غ�����.
	7. set�� vector�� ��ȯ
		set�� ����� ���� vector�� �Űܼ� Ȱ���ϴ� ���α׷��� ��������.
	*/

	printf("\n1. �ߺ� ���� ���� �Է� �� ���\n");
	std::set<int> TestSet1;
	int i_p1 = 0;
	int ExitNumber_p1 = -1;

	while (i_p1 != ExitNumber_p1)
	{
		printf("���� �Է��Ͻÿ�(-1�� �Է��ϸ� ����) : ");
		std::cin >> i_p1;
		if (i_p1 != ExitNumber_p1)
		{
			TestSet1.insert(i_p1);
		}
	}

	PrintSet(TestSet1);
	printf("\n");
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");

	printf("\n2. ���� ����(������, ������, ������)\n");
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
	printf("������ : ");
	PrintSet(TestSet2Union);

	for (int n : TestSet2_1)
	{
		if (TestSet2_2.contains(n))
		{
			TestSet2Intersection.insert(n);
		}
	}
	printf("������ : ");
	PrintSet(TestSet2Intersection);
	
	TestSet2Difference = TestSet2_2;
	for (int n : TestSet2_1)
	{
		if (TestSet2_2.contains(n))
		{
			TestSet2Difference.erase(n);
		}
	}
	printf("������ : ");
	PrintSet(TestSet2Difference);
	printf("\n");
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");

	printf("\n3. Ư�� ���� ���� ���� Ȯ��\n");
	std::set<int> TestSet3 = { 10,20,30,40,50 };

	const int Test3_Target = 30;
	std::set<int>::iterator iter = TestSet3.find(Test3_Target);
	if (iter != TestSet3.end())
	{
		// ã�Ҵ�.
		printf("find : %d�� ã�ҽ��ϴ�.\n", Test3_Target);
	}
	else
	{
		// ��ã�Ҵ�.
		printf("find : %d�� ��ã�ҽ��ϴ�.\n", Test3_Target);
	}
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");

	printf("\n4. ��������/�������� ���\n");
	std::set<int> TestSet4 = { 10,20,30,40,50 };
	printf("�������� ���: ");
	PrintSet(TestSet4);

	printf("�������� ���: ");
	printf("Set : ");
	for (auto iter = TestSet4.rbegin(); iter != TestSet4.rend(); iter++)
	{
		printf("%d ", *iter);
	}
	printf("\n");


	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("\n5. ���ڿ� �ߺ� ����\n");
	std::set<char> TestSet5;
	char ExitNumber5 = 'x';
	char i_p5 = 0;
	while (i_p5 != ExitNumber5)
	{
		printf("���ڿ��� �Է��Ͻÿ�(x�� �Է��ϸ� ���� : ");
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


	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("\n6. �ִ�, �ּڰ� ã��\n");
	std::set<int> TestSet6 = { 5,7,6,25,8,87,65,2,4,7,52 };
	PrintSet(TestSet6);
	if (!TestSet6.empty())
	{
		printf("�ִ밪 = %d, �ּҰ� = %d\n", *TestSet6.begin(), *TestSet6.rbegin());
	}

	
	
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("\n7. set�� vector�� ��ȯ\n");
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
		return "����";
	case CharacterType::Mage:
		return "������";
	case CharacterType::Archer:
		return "�ü�";
	case CharacterType::Thief:
		return "����";
	default:
		break;
	}
	return "�� �� ����";
}
void PrintStatus(const CharacterStatus& InStatus)
{
	printf(" | ���� : %2d | ü�� : %3d | ���ݷ� : %2d\n", InStatus.Level, InStatus.Health, InStatus.Attack);
}

void D0924::TestMap()
{
	std::map<CharacterType, CharacterStatus> Characters;

	Characters[CharacterType::Warrior] = { 10, 200, 15 };
	Characters[CharacterType::Mage] = { 8, 100, 5 };
	Characters[CharacterType::Archer] = { 12, 150, 20 };

	if (Characters.contains(CharacterType::Mage))	// ���� Ű�� �����ϴ� ���� �����ϱ� ���� �ݵ�� üũ�ؾ� �Ѵ�.
	{
		// �ִ�.
		CharacterStatus& MageStatus = Characters[CharacterType::Mage]; // []�����ڷ� Value�� ����
		printf("\n[] ���ٹ� : %s", ToString(CharacterType::Mage).c_str());
		PrintStatus(MageStatus);
	}
	else
	{
		// ����.
	}

	// ���� �׸� �����ϸ� �� �׸��� �����.
	CharacterStatus& ThiefStatus = Characters[CharacterType::Thief];
	printf("[] ���� Ű ���� : %s", ToString(CharacterType::Thief).c_str());
	PrintStatus(ThiefStatus);

	printf("\n��ü ĳ���� ���\n");
	for (const auto& pair : Characters)
		//for( const std::pair<CharacterType, CharacterStatus>& pair : Characters)
	{
		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = Ű, second = value
	}

	printf("\n���� ����\n");
	Characters.erase(CharacterType::Thief);

	printf("\n��ü ĳ���� ���\n");
	for (const auto& pair : Characters)
	{
		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = Ű, second = value
	}

	printf("\n��ü ����\n");
	Characters.clear();
	printf("\n��ü ĳ���� ���\n");
	for (const auto& pair : Characters)
	{
		printf("ĳ���� Ÿ�� : %6s", ToString(pair.first).c_str());
		PrintStatus(pair.second);	// first = Ű, second = value
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
	// Ű���� Hash �Լ��� �־�� �Ѵ�.
	// Ű���� ������ ���� �� �ֵ��� == �����ڰ� �־�� �Ѵ�.
	int i = 0;
}
