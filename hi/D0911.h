#pragma once

//
////extern : �ٸ� cpp�� �� ������ �ִٰ� �˷��ִ� �뵵
//extern int MazeHeight;
//extern int MazeWidth;
//extern int** Maze;
//
////const char* DirectoryName = ".\\Data\\";
//
///// <summary>
///// �� ������ �д� �Լ�
///// </summary>
///// <param name="MapFileName">�� ���� �̸�</param>
///// <param name="OutDataString">��¿�. ���Ͽ��� ���� �ؽ�Ʈ�� �����ش�.</param>
///// <returns>������ �дµ� �����ϸ� true, �����ϸ� false</returns>
//bool ReadMapFile(const char* MapFileName, std::string& OutDataString);
//
///// <summary>
///// string�� �޾Ƽ� Maze�� ä��µ� �ʿ��� �����͸� �Ľ��ϴ� �Լ�
///// </summary>
///// <param name="DataString">�ҽ��� ���ڿ�</param>
///// /// <returns>true : �Ľ� ����, false : �� ������(DataString)�� �߸��� ���</returns>
//bool ParseMapData(std::string& DataString);
//
///// <summary>
///// Source���� �߰ߵ� ù���� �����ϴ� �Լ�
///// </summary>
///// <param name="Source">��(\n)�� ã�� ���������� </param>
///// <returns>Source���� ù���� �ּ�</returns>
//char* GetLine(char** InOutSource);
//
///// <summary>
///// ���ڿ� ������ �Ľ��ϴ� �Լ�
///// </summary>
///// <param name="LineData">�Ľ��� ���ڿ�</param>
///// <param name="Size">����� ����� �迭�� ũ��</param>
///// <param name="OutArray">����� ����� �迭</param>
//void ParseLineData(const char* LineData, int ArraySize, int* OutArray);
//
///// <summary>
///// �̷� ������ �ʱ�ȭ �ϴ� �Լ�
///// </summary>
//void InitializeMaze();
//
//
///// <summary>
///// �̷ΰ����� �����ϴ� �Լ�
///// </summary>
//void CleatMaze();
//
//
//void D0911();