#include "PlayerMap.h"

void PlayerMap::PrintMap() const
{
	// ��� ���
	printf("   ");
	for (int i = 0; i < Map::MapSize; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");

	// ���� ��ǥ + ���� ���� ���
	for (int y = 0; y < Map::MapSize; y++)
	{
		printf("%2d ", y);	// ���� ��ǥ
		for (int x = 0; x < Map::MapSize; x++)
		{
			switch (Cells[y][x])
			{
			case CellType::Hit:
				printf(" X ");
				break;
			case CellType::Miss:
				printf(" O ");
				break;
			default: // Empty
				printf(" . ");
				break;
			}
		}
		printf("\n");
	}
}
