﻿#define _CRT_SECURE_NO_WARNINGS
//#define TEST_MODE


#include <iostream>
#include <fstream>
#include "MazeEscape.h"
#include "PlayerData.h"
#include "EnemyData.h"
#include "Monster.h"
#include "Player.h"
#include "Test.h"

//int main()
//{
////#ifdef TEST_MODE
////	Test test;
////	test.TestBattle();
////#endif // TEST_MODE
//
////#ifndef TEST_MODE
//	InitializeMaze();	// 미로 초기화(파일에서 불러오기)
//	MazeEscapeRun();	// 게임 시작
//	ClearMaze();		// 미로 초기화하면서 동적할당 했던 메모리 정리
////#endif // !TEST_MODE    
//
//	return 0;
//}

void MazeEscape_Start()
{
	InitializeMaze();	// 미로 초기화(파일에서 불러오기)
	MazeEscapeRun();	// 게임 시작
	ClearMaze();		// 미로 초기화하면서 동적할당 했던 메모리 정리
}

const char* DirectoryName = ".\\Data\\";
int MazeWidth = 20;
int MazeHeight = 10;
int** Maze = nullptr;


void InitializeMaze()
{
	std::string Data;
	ReadMapFile("MapData.txt", Data);
	ParseMapData(Data);
}

void MazeEscapeRun()
{
	Player player;

	FindStartPosition(player.CurrentPosition);

	printf("~~ Maze Escape ~~\n");

	while (player.GetHealth() > 0)
	{
		PrintMaze(player.CurrentPosition);

		if (IsEnd(player.CurrentPosition))
		{
			printf("Congratulations! You have escaped the maze!\n");
			break;
		}

		int MoveFlags = PrintAvailableMoves(player.CurrentPosition);
		MoveDirection Direction = GetMoveInput(MoveFlags);
		switch (Direction)
		{
		case (MoveDirection::DirUp):
			player.CurrentPosition.y--;
			break;
		case (MoveDirection::DirDown):
			player.CurrentPosition.y++;
			break;
		case (MoveDirection::DirLeft):
			player.CurrentPosition.x--;
			break;
		case (MoveDirection::DirRight):
			player.CurrentPosition.x++;
			break;
		case (MoveDirection::DirNone):
		default:
			// Critical Error
			break;
		}

		MoveEventProcess(player);
	}

	if (player.GetHealth() >= 0)
	{
		// 게임 클리어!
	}
	else
	{
		// 게임 오버
	}
}

void ClearMaze()
{
	if (Maze != nullptr)
	{
		for (int i = 0; i < MazeHeight; i++)
		{
			delete[] Maze[i];
			Maze[i] = nullptr;
		}
		delete[] Maze;
		Maze = nullptr;
	}
}

bool ReadMapFile(const char* MapFileName, std::string& OutDataString)
{
	char FilePath[256];
	strcpy(FilePath, DirectoryName);
	strcat(FilePath, MapFileName);

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open())
	{
		printf("File open FAIL!\n");
		printf("[%s] Check file path.\n", FilePath);
		return false;
	}

	OutDataString = std::string((std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());

	return true;
}

bool ParseMapData(std::string& DataString)
{
	char Source[512];
	char* Current = Source;
	strcpy(Source, DataString.c_str());

	char* LinePtr = GetLine(&Current);

	int SizeNumbers[2] = { 0 };
	ParseLineData(LinePtr, 2, SizeNumbers);

	MazeWidth = SizeNumbers[0];
	MazeHeight = SizeNumbers[1];

	Maze = new int* [MazeHeight];
	for (int y = 0; y < MazeHeight; y++)
	{
		Maze[y] = new int[MazeWidth];
	}

	int HeightIndex = 0;
	while ((*Current) != '\0')
	{
		LinePtr = GetLine(&Current);
		ParseLineData(LinePtr, MazeWidth, Maze[HeightIndex]);
		HeightIndex++;

		if (HeightIndex >= MazeHeight)
			break;
	}

	return true;
}

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

char* GetLine(char** InOutSource)
{
	char* Result = (*InOutSource);
	int Index = FindCharIndex((*InOutSource), '\n');
	if (Index == -1)
	{
		(*InOutSource) = (*InOutSource) + FindCharIndex((*InOutSource), '\0');
	}
	else
	{
		*((*InOutSource) + Index) = '\0';
		(*InOutSource) = (*InOutSource) + Index + 1;
	}

	return Result;
}

void ParseLineData(const char* LineData, int ArraySize, int* OutArray)
{
	const char* LinePointer = LineData;
	int SizeIndex = 0;
	while ((*LinePointer) != '\0')
	{
		int Result = 0;
		while ((*LinePointer) != ',' && (*LinePointer) != '\0')
		{
			Result = Result * 10 + (*LinePointer) - '0';
			LinePointer++;
		}
		OutArray[SizeIndex] = Result;
		SizeIndex++;

		if (ArraySize <= SizeIndex)	
			break;

		if (*LinePointer < '0' || *LinePointer > '9')
			LinePointer++;
	}
}

void PrintMaze(Position& position)
{
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			if (position.x == x && position.y == y)
			{
				printf("P ");
			}
			else if (Maze[y][x] == static_cast<int>(MazeTile::Wall))
			{
				printf("# ");
			}
			else if (Maze[y][x] == static_cast<int>(MazeTile::Path))
			{
				printf(". ");
			}
			else if (Maze[y][x] == static_cast<int>(MazeTile::Start))
			{
				printf("S ");
			}
			else if (Maze[y][x] == static_cast<int>(MazeTile::End))
			{
				printf("E ");
			}
			else
			{
				// Critical Error. Map Data is Wrong.
			}
		}
		printf("\n");
	}
}

void FindStartPosition(Position& OutPosition)
{
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			if (Maze[y][x] == static_cast<int>(MazeTile::Start))
			{
				OutPosition.x = x;
				OutPosition.y = y;
				return;
			}
		}
	}
	OutPosition.x = 0;
	OutPosition.y = 0;
}

int PrintAvailableMoves(Position& position)
{
	int MoveFlags = static_cast<int>(MoveDirection::DirNone);

	printf("Select movable direction (w:Up a:Left s:Down d:Right):\n");
	if (!IsWall(position.x, position.y - 1))
	{
		printf("W(↑) ");
		MoveFlags |= static_cast<int>(MoveDirection::DirUp);
	}
	if (!IsWall(position.x, position.y + 1))
	{
		printf("S(↓) ");
		MoveFlags |= static_cast<int>(MoveDirection::DirDown);
	}
	if (!IsWall(position.x - 1, position.y))
	{
		printf("A(←) ");
		MoveFlags |= static_cast<int>(MoveDirection::DirLeft);
	}
	if (!IsWall(position.x + 1, position.y))
	{
		printf("D(→) ");
		MoveFlags |= static_cast<int>(MoveDirection::DirRight);
	}
	printf("\n");

	return MoveFlags;
}

bool IsWall(int X, int Y)
{
	bool isWall = false;
	if (Y < 0 || Y >= MazeHeight ||
		X < 0 || X >= MazeWidth ||
		Maze[Y][X] == static_cast<int>(MazeTile::Wall))
		isWall = true;
	return isWall;
}

bool IsEnd(Position& position)
{
	return Maze[position.y][position.x] == static_cast<int>(MazeTile::End);
}

MoveDirection GetMoveInput(int MoveFlags)
{
	char InputChar = 0;
	MoveDirection Direction = MoveDirection::DirNone;

	while (true)
	{
		printf("Input direction : ");
		std::cin >> InputChar;

		if ((InputChar == 'w' || InputChar == 'W')
			&& (MoveFlags & static_cast<int>(MoveDirection::DirUp)) /*!= 0*/)
		{
			Direction = (MoveDirection::DirUp);
			break;
		}
		if ((InputChar == 's' || InputChar == 'S')
			&& (MoveFlags & static_cast<int>(MoveDirection::DirDown)) /*!= 0*/)
		{
			Direction = (MoveDirection::DirDown);
			break;
		}
		if ((InputChar == 'a' || InputChar == 'A')
			&& (MoveFlags & static_cast<int>(MoveDirection::DirLeft)) /*!= 0*/)
		{
			Direction = (MoveDirection::DirLeft);
			break;
		}
		if ((InputChar == 'd' || InputChar == 'D')
			&& (MoveFlags & static_cast<int>(MoveDirection::DirRight)) /*!= 0*/)
		{
			Direction = (MoveDirection::DirRight);
			break;
		}

		printf("Wrong input. Select movable direction.\n");
	}

	return Direction;
}

void MoveEventProcess(Player& player)
{
	float RandomValue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // 0.0f ~ 1.0f
	//printf("Random Value = %.2f\n", RandomValue);
	if (RandomValue < 0.2f)
	{
		printf("An enemy appeared! You fought bravely and defeated it!\n");
		BattleEvent(player);
	}
	else if (RandomValue < 0.4f)
	{
		printf("You found a Healer!\n");
		HealerEvent(player);
	}
	else
	{
		printf("Nothing happened.\n");
	}
}

void BattleEvent(Player& player)
{
    Monster enemy;
    printf("Battle Start!\n");

    while (player.IsAlive() && enemy.IsAlive())
    {
        // Player attacks Enemy
		player.ApplyAttack(&enemy);
        if (!enemy.IsAlive())
        {
            printf("Enemy defeated!\n");
			player.AddGold(enemy.GetDropGold());
			printf("You gained %d gold.\n", enemy.GetDropGold());
            break;
        }

        // Enemy attacks Player
		enemy.ApplyAttack(&player);
        if (!player.IsAlive())
        {
            printf("Player defeated!\n");
        }
    }
}

void HealerEvent(Player& player)
{
    printf("Healer: How much gold will you pay for healing?\n(Current Health: %.1f, Current Gold: %d)\n", player.GetHealth(), player.GetGold());
    int payGold = -1;
	while (payGold < 0 || payGold > player.GetGold())
    {
        printf("Enter gold to pay: ");
        std::cin >> payGold;
        if (payGold <= 0)
        {
            printf("Don’t you want a heal? OK.\n");
        }
        if (payGold > player.GetGold())
        {
            printf("You don't have enough gold.\n");
        }
    }
	if (payGold > 0)
	{
		player.Heal(static_cast<float>(payGold));
		player.PayGold(payGold);
		printf("Healed!");
	}
	printf("Current Health: %.1f, Remaining Gold: %d\n", player.GetHealth(), player.GetGold());
}
