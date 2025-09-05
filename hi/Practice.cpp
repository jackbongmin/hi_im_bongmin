#include "Practice.h"
#include <iostream>
#include <stdio.h>

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 실습 0905 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

/*
[기본 함수 실습]

1. 특정범위안에 랜덤한 수를 리턴하는 함수
	- int 파라메터 2개
	- int 리턴

2. "당신의 나이를 입력해주세요 : " → "당신은 00살 입니다."
	- int 파라메터 1개

3. 원의 반지름을 입력 받고 넓이를 구하기
	- float 파라메터 1개
	- float 리턴

4. 숫자를 입력받아 홀수인지 짝수인지 판단하는 함수
	- int 파라메터 1개
	- bool 리턴(true면 홀수, false면 짝수)

5. 성적분류 함수 (A ~ F)
	- int 파라메터 1개
	- int 리터(enum 값)

6. 아이템 설정, 아이템 해제, 아이템 토글용 함수 총 3개
	- 비트플래그인벤토리 수정
	- int 파라메터 2개(Inventory, 비트플래그용 enum)
	- 리턴 없음

7. 피라미드 출력 함수
	- int 파라메터 1개

[기본 탬플릿 실습]

8. Min
	- 파라메터 2개
	- 리턴 : 파라메터 중 작은 수 리턴

9. Max
	- 파라메터 2개
	- 리턴 : 파라메터 중 큰 수 리턴

10. Clamp
	- 파라메터 3개(value, min, max)
	- 리턴
		value 값이 min보다 작으면 min
		value 값이 max보다 크면 max
		value 값이 min과 max사이면 value

[기본 재귀함수 실습]

11. 재귀함수를 이용해서 팩토리얼 값을 만드는 함수 만들기(for사용 x)

*/


	int RandomNumber1(int Number1, int Number2)
	{
		return rand() % (Number2 - Number1) + Number1;
	}

	void Age(int Number1)
	{
		printf("당신은 %d살 입니다.\n", Number1);
	}

	float Radius(float Number1)
	{
		const float Pie = 3.141592f;
		return Number1 * Number1 * Pie;
	}

	int Number4(int Number1)
	{
		bool result = Number1 % 2 == 1;
		if (result)
		{
			printf("입력하신 숫자는 홀수 입니다.\n");
		}
		else
		return 0;
	}

	bool Number4_1(int Number1)
	{
		if (Number1 % 2 == 1)
		{
			printf("입력하신 숫자는 홀수 입니다.\n");
			return true;
		}
		else
		{
			printf("입력하신 숫자는 짝수 입니다.\n");
			return false;
		}
	}

	int Score(int Number1)
	{
		enum score
		{
			A,
			B,
			C,
			D,
			F
		};
		if (Number1 >= 90)
		{
			printf("당신의 점수는 A입니다.\n");
			return 0;
		}
		else if (Number1 >= 80)
		{
			printf("당신의 점수는 B입니다.\n");
			return 0;
		}
		else if (Number1 >= 80)
		{
			printf("당신의 점수는 C입니다.\n");
			return 0;
		}
		else if (Number1 >= 80)
		{
			printf("당신의 점수는 D입니다.\n");
			return 0;
		}
		else
		{
			printf("당신의 점수는 F입니다.\n");
			return 0;
		}
	}

