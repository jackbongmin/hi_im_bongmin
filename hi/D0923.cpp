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
	// #include <vector> �ʼ�
	std::vector<int> Scores;	// int�迭 scores�� ����
	Scores.reserve(5);			// ���� ����� ������ ����Ǵ� �ִ� ũ�⸦ ���� ���� ����

	Scores.push_back(10);		// vector�� �ڿ� �߰�
	Scores.push_back(20);
	Scores.push_back(30);

	// Ư�� ������ �ʱ�ȭ�� vector�� ����� ������(3���� "����"���� �ʱ�ȭ�� vector)
	std::vector<std::string> Name(3, "����");

	printf("ù��° ���� : %d\n", Scores[0]);		// �迭 ����ϵ��� ���. �ٸ� ������ ����� ������
	//printf("�׹�° ���� : %d\n", Scores[3]);		// ����
	printf("�ι�° ���� : %d\n", Scores.at(1));		// �ι�° ��ҿ� ����
	//printf("�׹�° ���� : %d\n", Scores.at(3));	// �׹�° ��ҿ� ����(=���ܸ� �߻�)
	printf("����° ���� : %d\n", Scores.back());	// ������ ��ҿ� ����
	printf("ù��° ���� : %d\n", Scores.front());	// ù��° ��ҿ� ����



// �Ϲ����� ��ȸ ���
printf("��� ���� : ");
for (int i = 0; i < Scores.size(); i++)
{
	printf("%d ", Scores[i]);
}
printf("\n");

// �ݺ��ڸ� ���� ��ȸ ���
printf("��� ���� : ");
for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
{
	printf("%d ", *iter);	// ���� iter��ġ�� �ִ� ���� ���
}
printf("\n");


// �뷮 Ȯ��(Size, Capacity)
// Size : ���� vector���� ���� ���Ǵ� ���� ����ִ� ����
// Capacity : ���� vector�� �Ҵ�� �޸� ����(���� ������� ���� �͵� ����)

printf("���� ���� ����(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
printf("�Ҵ�� �޸�(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));


// �����ϱ� : �ڿ��� �����ϴ� ���� ����.
Scores.pop_back(); // ������ ���� �ϳ� ����
printf("��� ���� : ");
for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
{
	printf("%d ", *iter);
}
printf("\n");

Scores.clear();	// ��� ���� ����(Size�� 0, Capacity�� �״��)
printf("��� ���� : ");
for (auto iter = Scores.begin(); iter != Scores.end(); iter++)
{
	printf("%d ", *iter);
}
printf("\n");
printf("���� ���� ����(Size) : %u\n", static_cast<unsigned int>(Scores.size()));
printf("�Ҵ�� �޸�(Capacity) : %u\n", static_cast<unsigned int>(Scores.capacity()));

if (Scores.empty())
{
	printf("Scores�� �����.\n");
}

// �߰��� �߰� �����ϴ� �Լ�.(�������ϸ� ���� ����)
//Scores.insert();
//Scores.erase();


// ���� �� ��
std::vector<int> Numbers = { 10,20,30,40,50 };
int DeleteNumber = 20;

std::vector<int>::iterator FindIter = std::find(Numbers.begin(), Numbers.end(), DeleteNumber);
if (FindIter != Numbers.end())
{
	// ã�Ҵ�.
	*FindIter = Numbers.back();		// ã�� ��ġ�� ������ ���� �־��.
	Numbers.pop_back();				// ������ ��� ����

}
else
{
	// ����.
}

int i = 0;
}

void D0923::TestVectorPractice()
{
	/*
	�ǽ�
	1. ���� �Է¹ް� ����ϱ�
	2. �ִ�, �ּ� ���ϱ�
	3. �����ϱ�
	4. Ư�� �� ã��.
	5. �ߺ� �����ϱ�
	6. ���� ��ġ��
	7. ���ڿ� ������
	8. ��� ��� ���ϱ�
	*/

	// 1. ���� �Է¹ް� ����ϱ�
	printf("1. ���� �Է¹ް� ����ϱ�\n\n");
	std::vector<int> Practice1;
	Practice1.reserve(10);
	
	constexpr int ExitNumber = -1;
	int i = 0;

	while (i != ExitNumber)
	{
		printf("���ڸ� �Է��ϼ���(-1�̸� ����) : ");
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

	// 2. �ִ� �ּ� ���ϱ�
	printf("2. �ִ� �ּ� ���ϱ�\n\n");

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
	printf("�ִ밪 : %d, �ּҰ� : %d\n", MaxNumber_0923, MinNumber_0923);
	printf("\n");


	// 3. �����ϱ�
	printf("3. �����ϱ�\n\n");

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



	// 4. Ư�� �� ã��
	printf("4. Ư�� �� ã��\n\n");

	std::vector<int> Practice4 = { 1,2,3,4,5 };
	Practice4.reserve(5);

	printf("ã�� ���� �Է��Ͻÿ� : ");
	int SearchNumber_0923 = 0;
	std::cin >> SearchNumber_0923;

	int index_0923 = 0;
	bool Found_0923 = false;
	for (auto iter = Practice4.begin(); iter != Practice4.end(); iter++, index_0923++)
	{
		if (SearchNumber_0923 == *iter)
		{
			printf("ã�� ���� %d��°�� �ֽ��ϴ�.\n", index_0923+1);
			Found_0923 = true;
			break;
		}
	}
	if(!Found_0923)
	{
		printf("�Է��Ͻ� ���� �����ϴ�.");
		return;
	}

	// 5. �ߺ��� ����
	printf("5. �ߺ��� �����ϱ�\n\n");

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
	std::sort(Practice5.begin(), Practice5.end());					// unique�� ���� ���ؼ��� ���ĵǾ� �־�� �Ѵ�.
	auto last = std::unique(Practice5.begin(), Practice5.end());	// �ߺ��Ǵ� ������ �ڷ� ������ �ߺ��Ǳ� �� �������� ����
	Practice5.erase(last, Practice5.end());							// �ߺ��Ǵ� �κе��� ������ ����

	printf("�ߺ����� ��� : ");
	for (int n : Practice5)
	{
		printf("$d", n);
	}
	printf("\n\n");


	// 6. ���� ��ġ��
	printf("6. ���� ��ġ��\n\n");

	std::vector<int> Practice6_1 = { 10,20,30 };
	std::vector<int> Practice6_2 = { 100,200,300 };
	std::vector<int> Result6(Practice6_1);

	for (int n : Practice6_2)
	{
		Result6.push_back(n);
	}



	// 7. ���ڿ� ������
	printf("7. ���ڿ� ������\n\n");

	printf("���ڿ��� �Է��ϼ��� : ");
	std::string InputWord;
	std::cin >> InputWord;
	std::vector<char> chars(InputWord.begin(), InputWord.end());
	printf("������ ��� : ");
	for (auto rIter = chars.rbegin(); rIter != chars.rend(); rIter++)
	{
		printf("%c", *rIter);
	}
	printf("\n\n");

	//std::reverse(chars.begin(), chars.end());

	// 8. ��� ��� ���ϱ�
	printf("8. ��� ��� ���ϱ��\n\n");

	std::vector<int> Practice8;
	Practice8.reserve(5);



	
}	