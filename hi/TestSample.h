#pragma once
#include<stdio.h>


class Parent
{
public:
	Parent()
	{
		printf("�θ� ������\n");
	}
	virtual ~Parent()
	{
		printf("�θ� �Ҹ���\n");
	}
};

class Child : public Parent
{
public:
	Child()
	{
		Data = new int[100];
		printf("�ڽ� ������. �޸� �Ҵ����.\n");
	}
	virtual ~Child()
	{
		delete[] Data;
		Data = nullptr;
		printf("�ڽ� �Ҹ���. �޸� ����.\n");
	}
private:
	int* Data = nullptr;
};