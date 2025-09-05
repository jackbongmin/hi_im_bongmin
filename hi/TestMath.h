#pragma once


// 헤더파일에는 선언을 작성한다.
// ctrl + k + o : 같은이름의 cpp와 h를 전환

void PrintHelloWorld();					// 리턴하는 값이 없고(void), 이름은 PrintHelloWorld고 파라메터도 없다.


/// <summary>
/// 두 파라메터를 더하는 함수
/// </summary>
/// <param name="Number1">더해질 첫번째 숫자</param>
/// <param name="Number2">더해질 두번째 숫자</param>
/// <returns>파라메터가 더해진 값</returns>
int Sum(int Number1, int Number2);		// 리턴타입이 int고 이름은 Sum이고 파라메터는 int 2개인 함수를 선언했다.
// int Sum(int, int);					// 선언할때는 함수의 파라메터 이름은 생략해도 된다. / 위와 같은거임

float Sum(float Test1, float Test2);


// 간단 실습 사칙연산용 탬플릿 함수 4개 만들기
// 
// 탬플릿
template <typename T1>
T1 Add(T1 Number1, T1 Number2)
{
	return Number1 + Number2;
}

template <typename T2>
T2 Minus(T2 Number1, T2 Number2)
{
	return Number1 - Number2;
}

template <typename T3>
T3 Multiply(T3 Number1, T3 Number2)
{
	return Number1 * Number2;
}

template <typename T4>
T4 Division(T4 Number1, T4 Number2)
{
	return Number1 / Number2;
}



// 파라메터 두개를 곱해서 돌려주는 함수
int Multiply(int Number1, int Number2 = 2);	// 디폴트 파라메터 사용 예시
											// 해당 파라메터 없이 함수를 호출하면 기본적으로 설정된 값이 대신 들어감.
											// 선언부에만 값을 설정한다.
											// 디폴트 파라메터는 항상 뒤에서부터 있어야 한다.

// 재귀 호출
int TestRecurcive(int Number);

inline int Square(int Number)
{
	return Number * Number;
}
