#include <iostream>
#include <stdio.h>
#include <random>
#include "D0910.h"
#include "direct.h"
#include "fstream"
#include <string>

void D0910_p4()
{
	int PlayerX = 0;
	int PlayerY = 0;
	FindStartPosition(PlayerX, PlayerY);
	
	printf("~~ �̷� Ż�� ���� ~~\n");
	
	while (true)
	{
		PrintMaze(PlayerX, PlayerY);
	
		if (IsEnd(PlayerX, PlayerY))
		{
			printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
			break;
		}
	
		int MoveFlags = PrintAvailableMoves(PlayerX, PlayerY);
		MoveDirection Direction = GetMoveInput(MoveFlags);
		switch (Direction)
		{
		case DirUp:
			PlayerY--;
			break;
		case DirDown:
			PlayerY++;
			break;
		case DirLeft:
			PlayerX--;
			break;
		case DirRight:
			PlayerX++;
			break;
		case DirNone:
		default:
			// ���� �� ����
			break;
		}
	}

}

void PrintMaze(int PlayerX, int PlayerY)
{
	for (int y = 0; y < MazeHeight; y++)
	{
	for (int x = 0; x < MazeWidth; x++)
	{
		if (PlayerX == x && PlayerY == y)
		{
			printf("P ");
		}
		else if (Maze[y][x] == Wall)
		{
			printf("# ");
		}
		else if (Maze[y][x] == Path)
		{
			printf(". ");
		}
		else if (Maze[y][x] == Start)
		{
			printf("S ");
		}
		else if (Maze[y][x] == End)
		{
			printf("E ");
		}
		else
		{
			// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
		}
	}
	printf("\n");
}


}

void FindStartPosition(int& OutStartX, int& OutStartY)
{
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			if (Maze[y][x] == Start)
			{
				OutStartX = x;
				OutStartY = y;
				return;
			}
		}
	}
	OutStartX = 0;
	OutStartY = 0;
}

int PrintAvailableMoves(int PlayerX, int PlayerY)
{
	int MoveFlags = DirNone;
	
	printf("�̵��� �� �ִ� ������ �����ϼ��� (w:�� a:���� s:�Ʒ��� d:������):\n");
	if (!IsWall(PlayerX, PlayerY - 1))
	{
		printf("W(��) ");
		MoveFlags |= DirUp;
	}
	if (!IsWall(PlayerX, PlayerY + 1))
	{
		printf("S(��) ");
		MoveFlags |= DirDown;
	}
	if (!IsWall(PlayerX - 1, PlayerY))
	{
		printf("A(��) ");
		MoveFlags |= DirLeft;
	}
	if (!IsWall(PlayerX + 1, PlayerY))
	{
		printf("D(��) ");
		MoveFlags |= DirRight;
	}
	printf("\n");
	
	return MoveFlags;

}

bool IsWall(int X, int Y)
{
	bool isWall = false;
	if (Y < 0 || Y >= MazeHeight ||
		X < 0 || X >= MazeWidth ||
		Maze[Y][X] == Wall)
		isWall = true;
	return isWall;
}

bool IsEnd(int X, int Y)
{
	return Maze[Y][X] == End;
}

MoveDirection GetMoveInput(int MoveFlags)
{
	char InputChar = 0;
	MoveDirection Direction = DirNone;
	
	while (true)
	{
		printf("������ �Է��ϼ��� : ");
		std::cin >> InputChar;
	
		if ((InputChar == 'w' || InputChar == 'W')
			&& (MoveFlags & DirUp) /*!= 0*/)
		{
			Direction = DirUp;
			break;
		}
		if ((InputChar == 's' || InputChar == 'S')
			&& (MoveFlags & DirDown) /*!= 0*/)
		{
			Direction = DirDown;
			break;
		}
		if ((InputChar == 'a' || InputChar == 'A')
			&& (MoveFlags & DirLeft) /*!= 0*/)
		{
			Direction = DirLeft;
			break;
		}
		if ((InputChar == 'd' || InputChar == 'D')
			&& (MoveFlags & DirRight) /*!= 0*/)
		{
			Direction = DirRight;
			break;
		}
	
		printf("�߸��� �Է��Դϴ�. �̵��� �� �ִ� ���� �߿��� �����ϼ���.\n");
	}
	
	return Direction;
	
}

void D0910_String()
{
	//char HelloString[14];
	//HelloString[0] = 'H';
	//HelloString[1] = 'e';
	//HelloString[2] = 'l';
	//HelloString[3] = 'l';
	//HelloString[4] = 'o';
	//HelloString[5] = ' ';
	//HelloString[6] = 'W';
	//HelloString[7] = 'o';
	//HelloString[8] = 'r';
	//HelloString[9] = 'l';
	//HelloString[10] = 'd';
	//HelloString[11] = '!';
	//HelloString[12] = '\n';
	//HelloString[13] = '\0';

	 char HelloString[] = "Hello World!\n";
	// == char HelloString[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\n' };
	
	printf("%s", HelloString);	// ���ڿ� ����ϱ�

	HelloString[5] = '\0';
	printf("%s\n", HelloString);	// Hello�� ��µ� / \0�� ���������� �Էµ�

	// ���� �ǽ�
	// 1. HelloString���� e'�� ���°�� �ִ��� ����ϱ�

	for (int i = 0; i < 13; i++)
	{
		if (HelloString[i] == 'W')
		{
			int Number_i = i + 1;
			printf("'W'�� %d��°�� �ֽ��ϴ�.\n\n", Number_i);
			return ;
		}
	}

	//// ������ Ǯ��
	//
	//int Index = 0;
	//char Target = 'e';
	//bool IsFind = false;
	//while (HelloString[Index] != '\0')
	//{
	//	if (HelloString[Index] == Target)
	//	{
	//		break;
	//	}
	//	Index++;
	//}

	//if (IsFind)
	//{
	//	printf("[%c]�� %d�� �ε����� �ֽ��ϴ�.\n", Target, Index);
	//}
	//else
	//{
	//	printf("[%c]�� ã�� �� �����ϴ�.\n", Target);
	//}

	//printf("[%c]�� %d�� �ε����� �ֽ��ϴ�.\n", Target, Index);



	// �Լ��� Ǯ�̽�
	char Target = 'e';
	int Index = FindCharIndex(HelloString, Target);
	if (Index >= 0)
	{
		printf("[%c]�� %d�� �ε����� �ֽ��ϴ�.\n", Target, Index);
	}
	else
	{
		printf("[%c]�� ã�� �� �����ϴ�.\n", Target);
	}

	/*
	 �ǽ�
	 1. ���ڿ��� ���̸� �����ϴ� �Լ� �����
		int MyStringLenth(const char* Target);
	*/

	printf("�ǽ�1\n");
	const char* Target1 = "Hello World!\n";				
	int Index1 = MyStringLenth(Target1);
	printf("Target�� ���ڿ� ���̴� %d�Դϴ�.\n\n", Index1);

	/*
	 �ǽ�
	  2. ���ڿ��� �����ϴ� �Լ� �����
		void MyStringCopy(const char* Source, char* Destination);
	*/

	printf("�ǽ�2\n");
	const char Source[] = "My Name is";
	char Destination[50] = { 0 };
	MyStringCopy(Source, Destination);
	printf("Destination�� �迭���� [%s]\n\n", Destination);


	/*
	 �ǽ�
	 3. ���ڿ��� ��ġ�� �Լ� �����
		Source �ڿ� Destination�� ������ ���̱�
		void MyStingCat(char* Source, const char* Destination);
	*/

	printf("�ǽ�3\n");
	char Source3[50] = "My Name is ";
	const char Destination3[] = "Baek JongMin";
	MyStingCat(Source3, Destination3);
	printf("Source3�� ���ڿ� �Է°��� [%s]�Դϴ�.\n\n", Source3);



	/*
	�ǽ�
	4. ���ڿ� �ΰ��� ���ϴ� �Լ� �����
		���ϰ� : �� ���ڿ��� ������ 0, ù��°�� ������ ����, �ι�°�� ������ ���
		int MyStringCompare(const char* String1, const char* String2);
	*/

	printf("�ǽ�4\n");
	char String1[] = "abc";
	char String2[] = "abcd";
	
	int Compare = MyStringCompare(String1, String2);
	printf("String1 = {a, b, c}\n");
	printf("String2 = {a, b, c, d}\n");
	printf("�� : %d\n\n", Compare);

	/*
	�ǽ�
	5. ���ڿ��� �Է¹޾� ������ �����ϴ� �Լ� �����
		int MyAtoI(const char* Source);
	*/

	printf("�ǽ�5\n");
	char Source5[] = "123456";
	MyAtoI(Source5);
	printf("Source5 : {%s}\n", Source5);
	printf("MyAtoI : %d\n\n", MyAtoI(Source5));

	/*
	�ǽ�
	6. ���ڿ��� �Է¹޾� �Ǽ��� �����ϴ� �Լ� �����
		float MyAtoF(const char* Source);
	*/

	printf("�ǽ�6\n");
	char Source6[] = "123.456";
	MyAtoF(Source6);
	printf("Source6 : {%s}\n", Source6);
	printf("MyAtoF : %d\n\n", MyAtoI(Source6));
	


}


// �Լ��� Ǯ�̽�
int FindCharIndex(const char* TargetString, const char TargetCharacter)
{
	int Index = 0;
	bool IsFind = false;
	while (TargetString[Index] != '\0')
	{
		if (TargetString[Index] == TargetCharacter)
		{
			IsFind = true;
			break;
		}
		Index++;
	}

	if (!IsFind)
	{
		Index = -1;
	}
	return Index;
}

// �ǽ�1
int MyStringLenth(const char* Target)
{
	int Index = 0;
	
	while (Target[Index] != '\0')
	{
		Index++;
	}
	return Index;
}

// �ǽ�2
void MyStringCopy(const char* Source, char* Destination)
{
	int Index = 0;

	while (Source[Index] != '\0')
	{
		Destination[Index] = Source[Index];
		Index++;
	}
	Destination[Index] = '\0';
}

// �ǽ�3
void MyStingCat(char* Source3, const char* Destination3)
{
	int i = 0;
	int j = 0;

	while (Source3[i] != '\0')
	{
		i++;
	}
	while (Destination3[j] != '\0')
	{
		Source3[i] = Destination3[j];
		i++;
		j++;
	}
	Source3[i] = '\0';
}

//�ǽ�4
int MyStringCompare(const char* String1, const char* String2)
{
	int i = 0;

	while (String1[i] != '\0' && String2[i] != '\0')
	{
		if (String1[i] != String2[i])
		{
			return String1[i] - String2[i];
		}
		i++;
	}
	return String1[i] - String2[i];
}

//�ǽ�5
int MyAtoI(const char* Source5)
{
	int i = 0;
	int Result = 0;
	int Sign = 1;
	if (Source5[0] == '-')
	{
		Sign = -1;
		i++;
	}
	while (Source5[i] != '\0')
	{
		if (Source5[i] >= '0' && Source5[i] <= '9')
		{
			Result = Result * 10 + (Source5[i]-'0');
		}
		else
		{
			break;
		}
		i++;
	}
	return Sign * Result;
}

//�ǽ�6
float MyAtoF(const char* Source6)
{
	float Result = 0.0f;
	int PointPosition = FindCharIndex(Source6, '.');
	if (PointPosition >= 0)
	{
		// ���� ã�Ҵ�.
		char Integral[32];
		MyStringCopy(Source6, Integral);
		Integral[PointPosition] = '\0';
		Result = static_cast<float>(MyAtoI(Integral));

		char Fractional[32];
		float frac = 0.1f;
		MyStringCopy(Source6 + PointPosition + 1, Fractional);
		int Index = 0;
		while (Fractional[Index] != '\0')
		{
			Result += (Fractional[Index] - '0') * frac;
			Index++;
			frac *= 0.1f;
		}
	}
	else
	{
		// ���� ��ã�Ҵ�.
		Result = static_cast<float>(MyAtoI(Source6));
	}

	return Result;
}

void D0910_Parsing()
{
	// �Ľ�

	const int Size = 32;
	char InputString[32];
	printf("\n\n������ �Է��ϼ��� : ");
	std::cin.getline(InputString, Size);
	printf("�Էµ� ������ [%s]�Դϴ�.\n\n", InputString);

	/*
	���ܽǽ�
	, �ڿ� �ִ� ���� ���ĺ��� ��� �빮���̾�� �Ѵ�.
	�Է¹��� ���� : "Hello,World!"
	��¹��� ���� : "Hello,WOLRD!"
	*/


	printf("���ܽǽ�\n");
	printf("������ �Է��ϼ��� : ");
	const int Size1 = 32;
	char InputString1[32];
	std::cin.getline(InputString1, Size1);
	SimplerParser(InputString1, ',');
	printf("�Էµ� ������ [%s]�Դϴ�.\n\n", InputString1);

	// #include <direct.h> �߰�
	char Working[256];
	if (_getcwd(Working, 256) != NULL)
	{
		printf("�۾� ���丮 : %s\n", Working);
	}

	//���� �б�
	ReadFile();

}

void SimplerParser(char* Source, const char Delimiter)
{
	int CommaIndex = FindCharIndex(Source, Delimiter);
	char* AfterComma = Source + CommaIndex + 1;
	int ToUpper = 'a' - 'A';
	while (*(AfterComma) != '\0')
	{
		if (*(AfterComma) >= 'a' && *(AfterComma) <= 'z')
		{
			*(AfterComma) -= ToUpper;
		}
		AfterComma++;
	}
}

void ReadFile()
{
	// #include "fstream"
	// #include <string>
	const char* FilePath = ".\\Data\\TestData.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())	//������ ���ȴ��� Ȯ���ϴ� �Լ�
	{
		printf("������ �� �� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���..\n", FilePath);
		return;
	}

	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	// InputFile�� �ִ� ���ڵ��� ��� �о FileContents�� �����ϱ�

	printf("���� ������ ������ �����ϴ�.\n");
	printf("%s\n", FileContents.c_str());	// FileContents�ȿ� �ִ� ���ڿ��� const char*�� �����ִ� �Լ�
}


// �� �̷��͵鵵 �ȴ�~ 
void TestString()
{
	// #include <string>
	std::string str1 = "Hello";
	std::string str2("World");	// str1���� str2�� �� �ٶ����ϴ�.

	const char* Temp1 = "Hello";
	char Temp2[32] = { 0 };
	//Temp2 = Temp1;			// �ȵ�
	//char* Temp3 = Temp1;		// �ȵ�

	std::string str3 = str1;		// ����
	size_t Length = str3.length();	// ���� Ȯ��
	//int Size = Length;	// ũ�Ⱑ �ȸ¾Ƽ� ©�� �� �ִ�.
	Length = str3.size();

	std::string str4 = str1 + " " = str2;	// str4 = "Hello World", + ����� ���ɿ� ������ ���� �� �ִ�.

	if (str1 == str2)	// ���ڿ��� ����
	{

	}
	if (str1 != str2)	// �ٸ���
	{

	}
	if (str1 > str2)	// ���� ������� ��
	{

	}

	size_t Position = str1.find('e');	// ù���� 'e'ã��
	// �߰� �������� std::string::npos ����
	Position = str1.find('e', Position + 1); // �ι�° e�� ã����(ù��° e�� �߰ߵǾ��ٴ� �����Ͽ�)

	str1[1] = 'E';	// Ư�� ��ġ�� ���ڿ� �����ϱ�. �ε��� ���� Ȯ���� ����. ��Ÿ�� ������ �� �� ����
	//str1[10] = 'E';	// ����
	//str1.at(1);		 // �����ϰ� �����ϴ� ���

	//str1.c_str();	// c��Ÿ�� ���ڿ� �����ϱ�

}

void D0910_P2()
{

}

