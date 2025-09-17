#pragma once


//struct Position
//{
//	int x = 0;
//	int y = 0;
//
//	Position() = default;	// 자동으로 생성되는 기본생성자와 같다.
//
//	Position(int InX, int InY)
//		:x(InX), y(InY)	// 웬만해선 여기에 입력하기
//	{
//		// 추가 계산이 필요한 경우. 이쪽에 새로 대입하기
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
//// 이향연산자는 구조체 밖에 쓰는 것이 일반적이다.
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
//	return !(a == b);	// 위랑 아래랑 같은거지만 아래를 더 선호함.
//}
//
