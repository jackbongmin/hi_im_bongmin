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
Enemy goblin;		// �� �ϳ��� ���� ���������
Enemy goblin[3];	// �� 3������ ���� ���������


- ����ü �����Ҵ� �ϴ¹�

Enemy* pGoblin = new Enemy();	// ���ο� ���� �����Ҵ� ����
delete pGoblin;					// �����Ҵ� ���� ���� ����
pGoblin = nullptr;				



- ����ü ������ ���ٹ�
	- �Ϲ����� ��� ��(.) �����ڸ� ���

		goblin.Name = "���";
		goblin.Health = 20;

	- ������ ������ ��� ȭ��ǥ(->) �����ڸ� ���
		
		pGoblin -> AttackPower = 5.0f;
		pGoblin -> DropGold = 100;

*/

void D0912_Struct()
{
	Enemy Goblin;
	printf("�̸� : %s\n", Goblin.Name.c_str());
	printf("HP : %.1f\n", Goblin.Health);
	printf("���ݷ� : %.1f\n", Goblin.AttackPower);
	printf("���� : %dGold\n", Goblin.DropGold);

	
	// ���ܽǽ� 1
	// ��� �����Ҵ� �޾ƺ���(����4���� �����ϱ�)

	
	Enemy* pGoblin = new Enemy();

	pGoblin->Name = "��� 2ȣ";
	pGoblin->Health = static_cast<float>(rand() % 100 + 50);	// 50 ~ 150 / Health�� float�� ����Ǿ��ִµ� ���� int�� �Ǿ��ֱ⶧���� static_cast<>�� ��ȯ��Ŵ
	pGoblin->AttackPower = static_cast<float>(rand() % 10 + 5);	// 5~15
	pGoblin->DropGold = static_cast<int>(pGoblin->Health * pGoblin->AttackPower);
	PrintEnemy(pGoblin);

	delete pGoblin;
	pGoblin = nullptr;
	
	// ���ܽǽ� 2
	// �ٸ� ����ü ������(ex: ������, ����, ��)

	Weapon Sword;
	Sword.Name = "��ö��";
	Sword.Desc = "ưư�ϴ�.";
	Sword.AttackPower = 15.0f;
	Sword.Price = 200;

	// ����ü �迭Ȱ��
	Enemy* Goblins = nullptr;
	Goblins = new Enemy[3];
	
	for (int i = 0; i < 3; i++)
	{
		// std::to_string : ���ڿ��� �ƴѰ��� string���� �������ִ� �Լ�
		Goblins[i].Name = "���" + std::to_string(i + 1) + "ȣ";	
		PrintEnemy(&Goblins[i]);
	}

	delete[] Goblins;
	Goblins = nullptr;

	Enemy NamedGoblin("���� ���");
	PrintEnemy(&NamedGoblin);


	/*
	 ���ܽǽ�
	 float Modifier�� �Ķ���ͷ� �޴� ������ �����
	 - Health�� Modifier�� 10��� ����
	 - AttackPower�� Modifier�� 5��� ����
	 - DropGold�� Modifier�� 100��� �����Ѵ�.
	*/

	Enemy ModifierGoblin(5.2f);
	PrintEnemy(&ModifierGoblin);

}

void D0912_OperatorOverLoading()
{
	Enemy Goblin1("��� 1ȣ");
	Enemy Goblin2("��� 2ȣ");

	Enemy FusionGoblin = Goblin1 + Goblin2;
	PrintEnemy(&FusionGoblin);

	/*
	���� �ǽ� 1
	Enemy -������ �����ε��ϱ�
		���ʿ� �ִ� �Ϳ��� �������� �� ������ ����
	*/

	Enemy NerfFusionGoblin = Goblin1 - Goblin2;
	PrintEnemy(&NerfFusionGoblin);

	/*
	���� �ǽ� 2
	Enemy *������ �����ε��ϱ�
		������ floatŸ��
		Enemy operator*(float Multiplier) const { return };
	*/

	Enemy EvolutionGoblin = Goblin1 * 5.2f;
	PrintEnemy(&EvolutionGoblin);


}

void PrintEnemy(const Enemy* pEnemy)
{
	printf("�̸� : %s\n", pEnemy->Name.c_str());
	printf("HP : %.1f\n", pEnemy->Health);
	printf("���ݷ� : %.1f\n", pEnemy->AttackPower);
	printf("���� : %dGold\n", pEnemy->DropGold);
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

// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

void D0912_P2_1()
{
	int PlayerX = 0;
	int PlayerY = 0;
	int PlayerHP = 100;
	
	FindStartPosition1(PlayerX, PlayerY);

	srand(time(0));

	printf("~~ �̷� Ż�� ���� ~~\n");

	while (true)
	{		
		PrintMaze1(PlayerX, PlayerY);

		if (IsEnd1(PlayerX, PlayerY))
		{
			printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
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
			// ���� �� ����
			break;
		}

		int DoEvent = rand() % 100;
		if (DoEvent < 20)
		{
			printf("���͸� �������ϴ�.\n\n");
			BattleStart(PlayerHP);
		}
		else if (DoEvent < 30)
		{
			printf("HP�� ȸ���Ǿ�����.\n\n");
			HPHeal(PlayerHP);
		}
		else
		{
			printf("�ƹ��ϵ� �Ͼ�� �ʾҴ�.\n\n");
		}
		if (PlayerHP <= 0)
		{
			break;
		}
	}
}


// �̷θ� ����ϴ� �Լ�
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
				// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
			}
		}
		printf("\n");
	}


}

// �÷��̾� ������ġ�� �޾ƿ��� �Լ�
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

// �÷��̾��� ���� ��ġ���� ������ �̵� ��θ� ����ϰ� ��� ��θ� ��ģ ��Ʈ �÷��׸� ��ȯ�մϴ�.
int PrintAvailableMoves1(int PlayerX, int PlayerY)
{
	int MoveFlags = DirNone;

	printf("�̵��� �� �ִ� ������ �����ϼ��� (w:�� a:���� s:�Ʒ��� d:������):\n");
	if (!IsWall1(PlayerX, PlayerY - 1))
	{
		printf("W(��) ");
		MoveFlags |= DirUp;
	}
	if (!IsWall1(PlayerX, PlayerY + 1))
	{
		printf("S(��) ");
		MoveFlags |= DirDown;
	}
	if (!IsWall1(PlayerX - 1, PlayerY))
	{
		printf("A(��) ");
		MoveFlags |= DirLeft;
	}
	if (!IsWall1(PlayerX + 1, PlayerY))
	{
		printf("D(��) ");
		MoveFlags |= DirRight;
	}
	printf("\n");

	return MoveFlags;

}

// �ش���ġ�� ������ Ȯ���ϴ� �Լ�
bool IsWall1(int X, int Y)
{
	bool isWall = false;
	if (Y < 0 || Y >= MazeHeight ||
		X < 0 || X >= MazeWidth ||
		Maze[Y][X] == Wall)
		isWall = true;
	return isWall;
}

// �ش���ġ�� ���������� Ȯ���ϴ� �Լ�
bool IsEnd1(int X, int Y)
{
	return Maze[Y][X] == End;
}

// �Է�ó���� �ϴ� �Լ�, ���������� ������ �̵� ���� ����
MoveDirection GetMoveInput1(int MoveFlags)
{
	char InputChar = 0;
	MoveDirection Direction = DirNone;

	while (true)
	{
		printf("������ �Է��ϼ��� : ");
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

		printf("�߸��� �Է��Դϴ�. �̵��� �� �ִ� ���� �߿��� �����ϼ���.\n");
	}

	return Direction;

}

void BattleStart(int& PlayerHP)
{
	int ComputerHP = 50;
	printf("������ �����մϴ�.\n\n");

	while (PlayerHP > 0 && ComputerHP > 0)
	{
		printf("�÷��̾ ���� �����մϴ�.\n\n");
		int Damage1 = PlayerAttack();
		printf("%d ������!\n", Damage1);
		ComputerHP -= Damage1;

		printf("�÷��̾� HP : [%d] / ���� HP : [%d]\n\n", PlayerHP, ComputerHP);

		if (ComputerHP <= 0)
		{
			printf("�� ��   �� ��\n���͸� óġ�߽��ϴ�!\n\n");
			break;
		}

		printf("���Ͱ� �ݰ��մϴ�.\n\n");
		int Damage2 = ComputerAttack();
		printf("%d ������!\n", Damage2);
		PlayerHP -= Damage2;

		printf("�÷��̾� HP : [%d] / ���� HP : [%d]\n\n", PlayerHP, ComputerHP);

		if (PlayerHP <= 0)
		{
			printf("�� �� �� �� �� ��\n�÷��̾ ����߽��ϴ�.\n\n");
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
		printf("ũ��Ƽ�� ��Ʈ!\n");
	}
		return Damage;
}

int ComputerAttack()
{
	int Damage = rand() % 11 + 5;
	if (rand() % 10 == 0)
	{
		Damage *= 2;
		printf("ũ��Ƽ�� ��Ʈ!\n");
	}
		return Damage;
}

void HPHeal(int& PlayerHP)
{
	PlayerHP = 100;
}



//�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�



void D0912_P2_2()
{
	int StartX = 0;
	int StartY = 0;

	FindStartPosition2(StartX, StartY);
	Player Jongmin(StartX, StartY, 100);

	srand(time(0));

	printf("~~ �̷� Ż�� ���� ~~\n");

	while (true)
	{
		PrintMaze2(Jongmin.pos.x, Jongmin.pos.y);

		if (IsEnd2(Jongmin.pos.x, Jongmin.pos.y))
		{
			printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
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
			// ���� �� ����
			break;
		}

		int DoEvent = rand() % 100;
		if (DoEvent < 20)
		{
			printf("���͸� �������ϴ�.\n\n");
			BattleStart2(Jongmin);
		}
		else if (DoEvent < 30)
		{
			printf("HP�� ȸ���Ǿ����ϴ�.\n\n");
			HPHeal2(Jongmin.HP);
		}
		else
		{
			printf("�ƹ��ϵ� �Ͼ�� �ʾҴ�.\n\n");
		}
		if (Jongmin.HP <= 0)
		{
			break;
		}
	}

}

// �̷θ� ����ϴ� �Լ�
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
				// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
			}
		}
		printf("\n");
	}


}

// �÷��̾� ������ġ�� �޾ƿ��� �Լ�
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

// �÷��̾��� ���� ��ġ���� ������ �̵� ��θ� ����ϰ� ��� ��θ� ��ģ ��Ʈ �÷��׸� ��ȯ�մϴ�.
int PrintAvailableMoves2(int PlayerX, int PlayerY)
{
	int MoveFlags = DirNone;

	printf("�̵��� �� �ִ� ������ �����ϼ��� (w:�� a:���� s:�Ʒ��� d:������):\n");
	if (!IsWall2(PlayerX, PlayerY - 1))
	{
		printf("W(��) ");
		MoveFlags |= DirUp;
	}
	if (!IsWall2(PlayerX, PlayerY + 1))
	{
		printf("S(��) ");
		MoveFlags |= DirDown;
	}
	if (!IsWall2(PlayerX - 1, PlayerY))
	{
		printf("A(��) ");
		MoveFlags |= DirLeft;
	}
	if (!IsWall2(PlayerX + 1, PlayerY))
	{
		printf("D(��) ");
		MoveFlags |= DirRight;
	}
	printf("\n");

	return MoveFlags;

}

// �ش���ġ�� ������ Ȯ���ϴ� �Լ�
bool IsWall2(int X, int Y)
{
	bool isWall = false;
	if (Y < 0 || Y >= MazeHeight ||
		X < 0 || X >= MazeWidth ||
		Maze[Y][X] == Wall)
		isWall = true;
	return isWall;
}

// �ش���ġ�� ���������� Ȯ���ϴ� �Լ�
bool IsEnd2(int X, int Y)
{
	return Maze[Y][X] == End;
}

// �Է�ó���� �ϴ� �Լ�, ���������� ������ �̵� ���� ����
MoveDirection GetMoveInput2(int MoveFlags)
{
	char InputChar = 0;
	MoveDirection Direction = DirNone;

	while (true)
	{
		printf("������ �Է��ϼ��� : ");
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

		printf("�߸��� �Է��Դϴ�. �̵��� �� �ִ� ���� �߿��� �����ϼ���.\n");
	}

	return Direction;

}

void BattleStart2(Player& Jongmin)
{
	int ComputerHP = 50;
	printf("������ �����մϴ�.\n\n");

	while (Jongmin.HP > 0 && ComputerHP > 0)
	{
		printf("�÷��̾ ���� �����մϴ�.\n\n");
		int Damage1 = PlayerAttack2();
		printf("%d ������!\n", Damage1);
		ComputerHP -= Damage1;

		printf("�÷��̾� HP : [%d] / ���� HP : [%d]\n\n", Jongmin.HP, ComputerHP);

		if (ComputerHP <= 0)
		{
			printf("�� ��   �� ��\n���͸� óġ�߽��ϴ�!\n\n");
			break;
		}

		printf("���Ͱ� �ݰ��մϴ�.\n\n");
		int Damage2 = ComputerAttack2();
		printf("%d ������!\n", Damage2);
		Jongmin.HP -= Damage2;

		printf("�÷��̾� HP : [%d] / ���� HP : [%d]\n\n", Jongmin.HP, ComputerHP);

		if (Jongmin.HP <= 0)
		{
			printf("�� �� �� �� �� ��\n�÷��̾ ����߽��ϴ�.\n\n");
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
		printf("ũ��Ƽ�� ��Ʈ!\n");
	}
	return Damage;
}

int ComputerAttack2()
{
	int Damage = rand() % 11 + 5;

	if (rand() % 10 == 0)
	{
		Damage *= 2;
		printf("ũ��Ƽ�� ��Ʈ!\n");
	}
	return Damage;
}

void HPHeal2(int& PlayerHP)
{
	PlayerHP = 100;
}
