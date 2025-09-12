
#define _CRT_SECURE_NO_WARNINGS // ← 보라색 글씨는 매크로?
//#define _CRTDBG_MAP_ALLOC
//#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#include <crtdbg.h>
//소스파일

#include <iostream> //include : 포함시키다 / iostream을 포함시켜라 / iostream : 인풋 아웃풋 스트림 입출력 관련 정보가 담겨있는거
//#include <cstdio> // iostream이 아니더라도 사용 가능
#include <stdio.h> // stdio.h에 네임스페이스 추가한 래퍼
#include <time.h> // c 스타일 랜덤 시드값 설정할때
#include <random> // c++ 스타일 랜덤 쓸때 
#include "TestMath.h" //헤더를 선언하면 헤더에 있는 내용이 전부 선언됨
//#include "Practice.h"
#include "D0910.h"
#include "D0911.h"
#include "D0912.h"

int main() // 앤트리 포인트(코드가 시작되는곳) / main함수는 반드시 하나만 있어야함
{
	//D0910_p4();

	//D0910_String();
	//D0910_Parsing();

	//D0911();

	//D0912_Struct();
	//D0912_OperatorOverLoading();

	//D0912_P1();
	D0912_P2_1();
	return 0;
}
