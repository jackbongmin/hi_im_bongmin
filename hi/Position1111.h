#pragma once


//struct Position
//{
//	int x = 0;
//	int y = 0;
//
//	Position() = default;	// �ڵ����� �����Ǵ� �⺻�����ڿ� ����.
//
//	Position(int InX, int InY)
//		:x(InX), y(InY)	// �����ؼ� ���⿡ �Է��ϱ�
//	{
//		// �߰� ����� �ʿ��� ���. ���ʿ� ���� �����ϱ�
//	}
//
//	Position& operator+=(const Position& other)
//	{
//		x += other.x;
//		y += other.y;
//		return *this;
//	}
//	Position& operator-=(const Position& other)
//	{
//		x -= other.x;
//		y -= other.y;
//		return *this;
//	}
//};
//
//// ���⿬���ڴ� ����ü �ۿ� ���� ���� �Ϲ����̴�.
//Position operator+(const Position& a, const Position& b)
//{
//	return Position(a.x + b.x, a.y + b.y);
//}
//
//Position operator-(const Position& a, const Position& b)
//{
//	return Position(a.x - b.x, a.y - b.y);
//}
//
//bool operator==(const Position& a, const Position& b)
//{
//	return (a.x == b.x) && (a.y == b.y);
//}
//
//bool operator!=(const Position& a, const Position& b)
//{
//	// return (a.x != b.x) || (a.y != b.y);
//	return !(a == b);	// ���� �Ʒ��� ���������� �Ʒ��� �� ��ȣ��.
//}
//
