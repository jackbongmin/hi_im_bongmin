#pragma once
#include <string>
#include "Position.h"
#include "PlayerData.h"
#include "MazePlayer.h"
#include "Player.h"


enum class MazeTile
{
    Path = 0,
    Wall = 1,
    Start = 2,
    End = 3
};

enum class MoveDirection
{
    DirNone = 0,
    DirUp = 1 << 0,
    DirDown = 1 << 1,
    DirLeft = 1 << 2,
    DirRight = 1 << 3
};

void MazeEscape_Start();

void InitializeMaze();
void MazeEscapeRun();
void ClearMaze();

bool ReadMapFile(const char* MapFileName, std::string& OutDataString);
bool ParseMapData(std::string& DataString);

int FindCharIndex(const char* TargetString, const char TargetCharacter);
char* GetLine(char** InOutSource);
void ParseLineData(const char* LineData, int ArraySize, int* OutArray);

void PrintMaze(Position& position);
void FindStartPosition(Position& OutPosition);
int PrintAvailableMoves(Position& position);
bool IsWall(int X, int Y);
bool IsEnd(Position& position);
MoveDirection GetMoveInput(int MoveFlags);

void MoveEventProcess(Player& player);
void BattleEvent(Player& Player);
void HealerEvent(Player& player);