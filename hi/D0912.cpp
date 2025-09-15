#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include "fstream"
#include "D0910.h"
#include "D0911.h"
#include "D0912.h"
#include <iostream>
#include <random>
#include "direct.h"


/*
Struct Enemy
{
	std::string Name;
	float Health;
	float AttacjPower;
	int DropGold;
}
Enemy goblin;		// 적 하나에 대한 정보만들기
Enemy goblin[3];	// 적 3마리에 대한 정보만들기


- 구조체 동적할당 하는법

Enemy* pGoblin = new Enemy();	// 새로운 적을 동적할당 받음
delete pGoblin;					// 동적할당 받은 것을 해제
pGoblin = nullptr;				



- 구조체 데이터 접근법
	- 일반적인 경우 점(.) 연산자를 사용

		goblin.Name = "고블린";
		goblin.Health = 20;

	- 포인터 변수인 경우 화살표(->) 연산자를 사용
		
		pGoblin -> AttackPower = 5.0f;
		pGoblin -> DropGold = 100;

*/

void D0912_Struct()
{
	Enemy Goblin;
	printf("이름 : %s\n", Goblin.Name.c_str());
	printf("HP : %.1f\n", Goblin.Health);
	printf("공격력 : %.1f\n", Goblin.AttackPower);
	printf("보상 : %dGold\n", Goblin.DropGold);

	
	// 간단실습 1
	// 고블린 동적할당 받아보기(변수4개도 조절하기)

	
	Enemy* pGoblin = new Enemy();

	pGoblin->Name = "고블린 2호";
	pGoblin->Health = static_cast<float>(rand() % 100 + 50);	// 50 ~ 150 / Health는 float로 선언되어있는데 값은 int로 되어있기때문에 static_cast<>로 변환시킴
	pGoblin->AttackPower = static_cast<float>(rand() % 10 + 5);	// 5~15
	pGoblin->DropGold = static_cast<int>(pGoblin->Health * pGoblin->AttackPower);
	PrintEnemy(pGoblin);

	delete pGoblin;
	pGoblin = nullptr;
	
	// 간단실습 2
	// 다른 구조체 만들어보기(ex: 아이템, 무기, 방어구)

	Weapon Sword;
	Sword.Name = "강철검";
	Sword.Desc = "튼튼하다.";
	Sword.AttackPower = 15.0f;
	Sword.Price = 200;

	// 구조체 배열활용
	Enemy* Goblins = nullptr;
	Goblins = new Enemy[3];
	
	for (int i = 0; i < 3; i++)
	{
		// std::to_string : 문자열이 아닌것을 string으로 변경해주는 함수
		Goblins[i].Name = "고블린" + std::to_string(i + 1) + "호";	
		PrintEnemy(&Goblins[i]);
	}

	delete[] Goblins;
	Goblins = nullptr;

	Enemy NamedGoblin("보스 고블린");
	PrintEnemy(&NamedGoblin);


	/*
	 간단실습
	 float Modifier를 파라메터로 받는 생성자 만들기
	 - Health는 Modifier의 10배로 설정
	 - AttackPower는 Modifier의 5배로 설정
	 - DropGold는 Modifier의 100배로 설정한다.
	*/

	Enemy ModifierGoblin(5.2f);
	PrintEnemy(&ModifierGoblin);

}

void D0912_OperatorOverLoading()
{
	Enemy Goblin1("고블린 1호");
	Enemy Goblin2("고블린 2호");

	Enemy FusionGoblin = Goblin1 + Goblin2;
	PrintEnemy(&FusionGoblin);

	/*
	간단 실습 1
	Enemy -연산자 오버로딩하기
		왼쪽에 있는 것에서 오른쪽의 값 절반을 빼기
	*/

	Enemy NerfFusionGoblin = Goblin1 - Goblin2;
	PrintEnemy(&NerfFusionGoblin);

	/*
	간단 실습 2
	Enemy *연산자 오버로딩하기
		왼쪽은 float타입
		Enemy operator*(float Multiplier) const { return };
	*/

	Enemy EvolutionGoblin = Goblin1 * 5.2f;
	PrintEnemy(&EvolutionGoblin);


}

void PrintEnemy(const Enemy* pEnemy)
{
	printf("이름 : %s\n", pEnemy->Name.c_str());
	printf("HP : %.1f\n", pEnemy->Health);
	printf("공격력 : %.1f\n", pEnemy->AttackPower);
	printf("보상 : %dGold\n", pEnemy->DropGold);
}

void D0912_P1()
{
	Position1 p1(2, 3);
	Position1 p2(5, 1);

	Position1 sum = p1 + p2;
	Position1 diff = p1 - p2;

	printf("p1 = (2, 3)\n");
	printf("p2 = (5, 1)\n");
	printf("Position(p1 + p2) = (%d, %d)\n", sum.x, sum.y);
	printf("Position(p1 - p2) = (%d, %d)\n", diff.x, diff.y);

}

// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

void D0912_P2_1()
{
	int PlayerX = 0;
	int PlayerY = 0;
	int PlayerHP = 100;
	
	FindStartPosition1(PlayerX, PlayerY);

	srand(time(0));

	printf("~~ 미로 탈출 게임 ~~\n");

	while (true)
	{		
		PrintMaze1(PlayerX, PlayerY);

		if (IsEnd1(PlayerX, PlayerY))
		{
			printf("축하합니다! 미로를 탈출했습니다!\n");
			break;
		}

		int MoveFlags = PrintAvailableMoves1(PlayerX, PlayerY);
		MoveDirection Direction = GetMoveInput1(MoveFlags);
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

		int DoEvent = rand() % 100;
		if (DoEvent < 20)
		{
			printf("몬스터를 만났습니다.\n\n");
			BattleStart(PlayerHP);
		}
		else if (DoEvent < 30)
		{
			printf("HP가 회복되었습니.\n\n");
			HPHeal(PlayerHP);
		}
		else
		{
			printf("아무일도 일어나지 않았다.\n\n");
		}
		if (PlayerHP <= 0)
		{
			break;
		}
	}
}


// 미로를 출력하는 함수
void PrintMaze1(int PlayerX, int PlayerY)
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

// 플레이어 시작위치를 받아오는 함수
void FindStartPosition1(int& OutStartX, int& OutStartY)
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

// 플레이어의 현재 위치에서 가능한 이동 경로를 출력하고 모든 경로를 합친 비트 플레그를 반환합니다.
int PrintAvailableMoves1(int PlayerX, int PlayerY)
{
	int MoveFlags = DirNone;

	printf("이동할 수 있는 방향을 선택하세요 (w:위 a:왼쪽 s:아래쪽 d:오른쪽):\n");
	if (!IsWall1(PlayerX, PlayerY - 1))
	{
		printf("W(↑) ");
		MoveFlags |= DirUp;
	}
	if (!IsWall1(PlayerX, PlayerY + 1))
	{
		printf("S(↓) ");
		MoveFlags |= DirDown;
	}
	if (!IsWall1(PlayerX - 1, PlayerY))
	{
		printf("A(←) ");
		MoveFlags |= DirLeft;
	}
	if (!IsWall1(PlayerX + 1, PlayerY))
	{
		printf("D(→) ");
		MoveFlags |= DirRight;
	}
	printf("\n");

	return MoveFlags;

}

// 해당위치가 벽인지 확인하는 함수
bool IsWall1(int X, int Y)
{
	bool isWall = false;
	if (Y < 0 || Y >= MazeHeight ||
		X < 0 || X >= MazeWidth ||
		Maze[Y][X] == Wall)
		isWall = true;
	return isWall;
}

// 해당위치가 도착점인지 확인하는 함수
bool IsEnd1(int X, int Y)
{
	return Maze[Y][X] == End;
}

// 입력처리를 하는 함수, 최종적으로 결정된 이동 방향 리턴
MoveDirection GetMoveInput1(int MoveFlags)
{
	char InputChar = 0;
	MoveDirection Direction = DirNone;

	while (true)
	{
		printf("방향을 입력하세요 : ");
		std::cin >> InputChar;
		printf("\n");

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

void BattleStart(int& PlayerHP)
{
	int ComputerHP = 50;
	printf("전투를 시작합니다.\n\n");

	while (PlayerHP > 0 && ComputerHP > 0)
	{
		printf("플레이어가 선제 공격합니다.\n\n");
		int Damage1 = PlayerAttack();
		printf("%d 데미지!\n", Damage1);
		ComputerHP -= Damage1;

		printf("플레이어 HP : [%d] / 몬스터 HP : [%d]\n\n", PlayerHP, ComputerHP);

		if (ComputerHP <= 0)
		{
			printf("※ 승   리 ※\n몬스터를 처치했습니다!\n\n");
			break;
		}

		printf("몬스터가 반격합니다.\n\n");
		int Damage2 = ComputerAttack();
		printf("%d 데미지!\n", Damage2);
		PlayerHP -= Damage2;

		printf("플레이어 HP : [%d] / 몬스터 HP : [%d]\n\n", PlayerHP, ComputerHP);

		if (PlayerHP <= 0)
		{
			printf("※ 게 임 오 버 ※\n플레이어가 사망했습니다.\n\n");
			break;
		}
	}
}

int PlayerAttack()
{
	int Damage = rand() % 11 + 5;
	if (rand() % 10 == 0)
	{
		Damage *= 2;
		printf("크리티컬 히트!\n");
	}
		return Damage;
}

int ComputerAttack()
{
	int Damage = rand() % 11 + 5;
	if (rand() % 10 == 0)
	{
		Damage *= 2;
		printf("크리티컬 히트!\n");
	}
		return Damage;
}

void HPHeal(int& PlayerHP)
{
	PlayerHP = 100;
}



//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ



void D0912_P2_2()
{
	int StartX = 0;
	int StartY = 0;

	FindStartPosition2(StartX, StartY);
	Player Jongmin(StartX, StartY, 100);

	srand(time(0));

	printf("~~ 미로 탈출 게임 ~~\n");

	while (true)
	{
		PrintMaze2(Jongmin.pos.x, Jongmin.pos.y);

		if (IsEnd2(Jongmin.pos.x, Jongmin.pos.y))
		{
			printf("축하합니다! 미로를 탈출했습니다!\n");
			break;
		}

		int MoveFlags = PrintAvailableMoves2(Jongmin.pos.x, Jongmin.pos.y);
		MoveDirection Direction = GetMoveInput2(MoveFlags);
		switch (Direction)
		{
		case DirUp:
			Jongmin.pos.y--;
			break;
		case DirDown:
			Jongmin.pos.y++;
			break;
		case DirLeft:
			Jongmin.pos.x--;
			break;
		case DirRight:
			Jongmin.pos.x++;
			break;
		case DirNone:
		default:
			// 있을 수 없음
			break;
		}

		int DoEvent = rand() % 100;
		if (DoEvent < 20)
		{
			printf("몬스터를 만났습니다.\n\n");
			BattleStart2(Jongmin);
		}
		else if (DoEvent < 30)
		{
			printf("HP가 회복되었습니다.\n\n");
			HPHeal2(Jongmin.HP);
		}
		else
		{
			printf("아무일도 일어나지 않았다.\n\n");
		}
		if (Jongmin.HP <= 0)
		{
			break;
		}
	}

}

// 미로를 출력하는 함수
void PrintMaze2(int PlayerX, int PlayerY)
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

// 플레이어 시작위치를 받아오는 함수
void FindStartPosition2(int& OutStartX, int& OutStartY)
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

// 플레이어의 현재 위치에서 가능한 이동 경로를 출력하고 모든 경로를 합친 비트 플레그를 반환합니다.
int PrintAvailableMoves2(int PlayerX, int PlayerY)
{
	int MoveFlags = DirNone;

	printf("이동할 수 있는 방향을 선택하세요 (w:위 a:왼쪽 s:아래쪽 d:오른쪽):\n");
	if (!IsWall2(PlayerX, PlayerY - 1))
	{
		printf("W(↑) ");
		MoveFlags |= DirUp;
	}
	if (!IsWall2(PlayerX, PlayerY + 1))
	{
		printf("S(↓) ");
		MoveFlags |= DirDown;
	}
	if (!IsWall2(PlayerX - 1, PlayerY))
	{
		printf("A(←) ");
		MoveFlags |= DirLeft;
	}
	if (!IsWall2(PlayerX + 1, PlayerY))
	{
		printf("D(→) ");
		MoveFlags |= DirRight;
	}
	printf("\n");

	return MoveFlags;

}

// 해당위치가 벽인지 확인하는 함수
bool IsWall2(int X, int Y)
{
	bool isWall = false;
	if (Y < 0 || Y >= MazeHeight ||
		X < 0 || X >= MazeWidth ||
		Maze[Y][X] == Wall)
		isWall = true;
	return isWall;
}

// 해당위치가 도착점인지 확인하는 함수
bool IsEnd2(int X, int Y)
{
	return Maze[Y][X] == End;
}

// 입력처리를 하는 함수, 최종적으로 결정된 이동 방향 리턴
MoveDirection GetMoveInput2(int MoveFlags)
{
	char InputChar = 0;
	MoveDirection Direction = DirNone;

	while (true)
	{
		printf("방향을 입력하세요 : ");
		std::cin >> InputChar;
		printf("\n");

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

void BattleStart2(Player& Jongmin)
{
	int ComputerHP = 50;
	printf("전투를 시작합니다.\n\n");

	while (Jongmin.HP > 0 && ComputerHP > 0)
	{
		printf("플레이어가 선제 공격합니다.\n\n");
		int Damage1 = PlayerAttack2();
		printf("%d 데미지!\n", Damage1);
		ComputerHP -= Damage1;

		printf("플레이어 HP : [%d] / 몬스터 HP : [%d]\n\n", Jongmin.HP, ComputerHP);

		if (ComputerHP <= 0)
		{
			printf("※ 승   리 ※\n몬스터를 처치했습니다!\n\n");
			break;
		}

		printf("몬스터가 반격합니다.\n\n");
		int Damage2 = ComputerAttack2();
		printf("%d 데미지!\n", Damage2);
		Jongmin.HP -= Damage2;

		printf("플레이어 HP : [%d] / 몬스터 HP : [%d]\n\n", Jongmin.HP, ComputerHP);

		if (Jongmin.HP <= 0)
		{
			printf("※ 게 임 오 버 ※\n플레이어가 사망했습니다.\n\n");
			break;
		}
	}
}

int PlayerAttack2()
{
	int Damage = rand() % 11 + 5;
	if (rand() % 10 == 0)
	{
		Damage *= 2;
		printf("크리티컬 히트!\n");
	}
	return Damage;
}

int ComputerAttack2()
{
	int Damage = rand() % 11 + 5;

	if (rand() % 10 == 0)
	{
		Damage *= 2;
		printf("크리티컬 히트!\n");
	}
	return Damage;
}

void HPHeal2(int& PlayerHP)
{
	PlayerHP = 100;
}
