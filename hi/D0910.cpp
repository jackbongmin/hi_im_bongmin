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
	
	printf("~~ 미로 탈출 게임 ~~\n");
	
	while (true)
	{
		PrintMaze(PlayerX, PlayerY);
	
		if (IsEnd(PlayerX, PlayerY))
		{
			printf("축하합니다! 미로를 탈출했습니다!\n");
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
			// 있을 수 없음
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
			// 절대 들어오면 안되는 곳 == 맵 데이터가 잘못된 것
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
	
	printf("이동할 수 있는 방향을 선택하세요 (w:위 a:왼쪽 s:아래쪽 d:오른쪽):\n");
	if (!IsWall(PlayerX, PlayerY - 1))
	{
		printf("W(↑) ");
		MoveFlags |= DirUp;
	}
	if (!IsWall(PlayerX, PlayerY + 1))
	{
		printf("S(↓) ");
		MoveFlags |= DirDown;
	}
	if (!IsWall(PlayerX - 1, PlayerY))
	{
		printf("A(←) ");
		MoveFlags |= DirLeft;
	}
	if (!IsWall(PlayerX + 1, PlayerY))
	{
		printf("D(→) ");
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
		printf("방향을 입력하세요 : ");
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
	
		printf("잘못된 입력입니다. 이동할 수 있는 방향 중에서 선택하세요.\n");
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
	
	printf("%s", HelloString);	// 문자열 출력하기

	HelloString[5] = '\0';
	printf("%s\n", HelloString);	// Hello만 출력됨 / \0이 마지막으로 입력됨

	// 간단 실습
	// 1. HelloString에서 e'가 몇번째에 있는지 출력하기

	for (int i = 0; i < 13; i++)
	{
		if (HelloString[i] == 'W')
		{
			int Number_i = i + 1;
			printf("'W'는 %d번째에 있습니다.\n\n", Number_i);
			return ;
		}
	}

	//// 교수님 풀이
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
	//	printf("[%c]는 %d번 인덱스에 있습니다.\n", Target, Index);
	//}
	//else
	//{
	//	printf("[%c]는 찾을 수 없습니다.\n", Target);
	//}

	//printf("[%c]는 %d번 인덱스에 있습니다.\n", Target, Index);



	// 함수로 풀이시
	char Target = 'e';
	int Index = FindCharIndex(HelloString, Target);
	if (Index >= 0)
	{
		printf("[%c]는 %d번 인덱스에 있습니다.\n", Target, Index);
	}
	else
	{
		printf("[%c]는 찾을 수 없습니다.\n", Target);
	}

	/*
	 실습
	 1. 문자열의 길이를 측정하는 함수 만들기
		int MyStringLenth(const char* Target);
	*/

	printf("실습1\n");
	const char* Target1 = "Hello World!\n";				
	int Index1 = MyStringLenth(Target1);
	printf("Target의 문자열 길이는 %d입니다.\n\n", Index1);

	/*
	 실습
	  2. 문자열을 복사하는 함수 만들기
		void MyStringCopy(const char* Source, char* Destination);
	*/

	printf("실습2\n");
	const char Source[] = "My Name is";
	char Destination[50] = { 0 };
	MyStringCopy(Source, Destination);
	printf("Destination의 배열값은 [%s]\n\n", Destination);


	/*
	 실습
	 3. 문자열을 합치는 함수 만들기
		Source 뒤에 Destination의 내용을 붙이기
		void MyStingCat(char* Source, const char* Destination);
	*/

	printf("실습3\n");
	char Source3[50] = "My Name is ";
	const char Destination3[] = "Baek JongMin";
	MyStingCat(Source3, Destination3);
	printf("Source3의 문자열 입력값은 [%s]입니다.\n\n", Source3);



	/*
	실습
	4. 문자열 두개를 비교하는 함수 만들기
		리턴값 : 두 문자열이 같으면 0, 첫번째가 작으면 음수, 두번째가 작으면 양수
		int MyStringCompare(const char* String1, const char* String2);
	*/

	printf("실습4\n");
	char String1[] = "abc";
	char String2[] = "abcd";
	
	int Compare = MyStringCompare(String1, String2);
	printf("String1 = {a, b, c}\n");
	printf("String2 = {a, b, c, d}\n");
	printf("비교 : %d\n\n", Compare);

	/*
	실습
	5. 문자열을 입력받아 정수를 리턴하는 함수 만들기
		int MyAtoI(const char* Source);
	*/

	printf("실습5\n");
	char Source5[] = "123456";
	MyAtoI(Source5);
	printf("Source5 : {%s}\n", Source5);
	printf("MyAtoI : %d\n\n", MyAtoI(Source5));

	/*
	실습
	6. 문자열을 입력받아 실수를 리턴하는 함수 만들기
		float MyAtoF(const char* Source);
	*/

	printf("실습6\n");
	char Source6[] = "123.456";
	MyAtoF(Source6);
	printf("Source6 : {%s}\n", Source6);
	printf("MyAtoF : %d\n\n", MyAtoI(Source6));
	


}


// 함수로 풀이시
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

// 실습1
int MyStringLenth(const char* Target)
{
	int Index = 0;
	
	while (Target[Index] != '\0')
	{
		Index++;
	}
	return Index;
}

// 실습2
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

// 실습3
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

//실습4
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

//실습5
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

//실습6
float MyAtoF(const char* Source6)
{
	float Result = 0.0f;
	int PointPosition = FindCharIndex(Source6, '.');
	if (PointPosition >= 0)
	{
		// 점을 찾았다.
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
		// 점을 못찾았다.
		Result = static_cast<float>(MyAtoI(Source6));
	}

	return Result;
}

void D0910_Parsing()
{
	// 파싱

	const int Size = 32;
	char InputString[32];
	printf("\n\n문장을 입력하세요 : ");
	std::cin.getline(InputString, Size);
	printf("입력된 문장은 [%s]입니다.\n\n", InputString);

	/*
	간단실습
	, 뒤에 있는 영어 알파벳은 모두 대문자이어야 한다.
	입력문장 예시 : "Hello,World!"
	출력문장 예시 : "Hello,WOLRD!"
	*/


	printf("간단실습\n");
	printf("문장을 입력하세요 : ");
	const int Size1 = 32;
	char InputString1[32];
	std::cin.getline(InputString1, Size1);
	SimplerParser(InputString1, ',');
	printf("입력된 문장은 [%s]입니다.\n\n", InputString1);

	// #include <direct.h> 추가
	char Working[256];
	if (_getcwd(Working, 256) != NULL)
	{
		printf("작업 디렉토리 : %s\n", Working);
	}

	//파일 읽기
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
	if (!InputFile.is_open())	//파일이 열렸는지 확인하는 함수
	{
		printf("파일을 열 수 없습니다.\n");
		printf("[%s] 경로를 확인하세요..\n", FilePath);
		return;
	}

	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());	// InputFile에 있는 글자들을 모두 읽어서 FileContents에 저장하기

	printf("파일 내용은 다음과 같습니다.\n");
	printf("%s\n", FileContents.c_str());	// FileContents안에 있는 문자열을 const char*로 돌려주는 함수
}


// ↓ 이런것들도 된다~ 
void TestString()
{
	// #include <string>
	std::string str1 = "Hello";
	std::string str2("World");	// str1보다 str2가 더 바람직하다.

	const char* Temp1 = "Hello";
	char Temp2[32] = { 0 };
	//Temp2 = Temp1;			// 안됨
	//char* Temp3 = Temp1;		// 안됨

	std::string str3 = str1;		// 복사
	size_t Length = str3.length();	// 길이 확인
	//int Size = Length;	// 크기가 안맞아서 짤릴 수 있다.
	Length = str3.size();

	std::string str4 = str1 + " " = str2;	// str4 = "Hello World", + 방식은 성능에 문제가 있을 수 있다.

	if (str1 == str2)	// 문자열이 같다
	{

	}
	if (str1 != str2)	// 다르다
	{

	}
	if (str1 > str2)	// 사전 순서대로 비교
	{

	}

	size_t Position = str1.find('e');	// 첫번쨰 'e'찾기
	// 발견 못했으면 std::string::npos 리턴
	Position = str1.find('e', Position + 1); // 두번째 e를 찾을때(첫번째 e가 발견되었다는 전제하에)

	str1[1] = 'E';	// 특정 위치의 글자에 접근하기. 인덱스 범위 확인을 안함. 런타임 에러가 뜰 수 있음
	//str1[10] = 'E';	// 터짐
	//str1.at(1);		 // 안전하게 접근하는 방식

	//str1.c_str();	// c스타일 문자열 접근하기

}

void D0910_P2()
{

}

