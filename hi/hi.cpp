
#define _CRT_SECURE_NO_WARNINGS

//소스파일

// ← 주석(comment) : 프로그램에서 영향을 끼치지 않는 부분(컴파일러가 무시하는 문장)

/* 슬래쉬 별표 사이에 무엇을 얼마나 쓰던지 다 주석이 됨 */
/*
- ctrl + d : 한줄 복제하기
- shift + del : 한줄 삭제하기
- shift + 화살표 : 블럭잡기
- alt + shift + 화살표 : 세로로 블럭잡기 가능
- ctrl + space bar : 자동완성기능(인텔리센트)
- alt + 위아래 화살표 : 해당 줄 위치 바꾸기
- 프로그램 디버그 : <f5> 키 또는 [디버그] -> [디버깅 시작] 메뉴
- ctrl + b + b : 프로젝트 빌드(솔루션 빌드) / f5눌러서 확인하기 오래걸릴때 컴파일이 문제없는지 확인할때 사용
- ctrl + b + r : 프로젝트 리빌드(제대로했는데 실행이 잘 안될때 리빌드 해보는게 좋음)
- ctrl + 화살표 위아래 : 페이지 업다운
- ctrl + 화살표 좌우 : 단어 단위로 움직이기
- ctrl + k + c = 한번에 주석
- ctrl + k + u = 한번에 주석 풀기


- 선언은 보통 헤더파일에서 진행함
*/

/*
- 컴파일러 : 번역기(사람이 써놓은 코드를 기계가 알아듣게 번역해줌)
  -> 목적코드 생성
  -> 링커가 연결해서 실행파일 생성
- 빌드 : 실행파일 생성하기
- 리빌드 : 전체 다시 빌드하기(솔루션정리 + 빌드)
*/

#include <iostream> //include : 포함시키다 / iostream을 포함시켜라 / iostream : 인풋 아웃풋 스트림 입출력 관련 정보가 담겨있는거
//#include <cstdio> // iostream이 아니더라도 사용 가능
#include <stdio.h> // stdio.h에 네임스페이스 추가한 래퍼
#include "header.h" //헤더를 선언하면 헤더에 있는 내용이 전부 선언됨

// 명령어에 빨간줄이 생기면 잘못됐다는 뜻
// 명령어에 녹색줄이 생기면 지금은 괜찮은데 문제될 수 있어라는 경고

//using namespace std; //std를 자동으로 추가시킨다는 것 / std위치를 알아야하기때문에 교육땐 빼고 쓸예정

int main() // 앤트리 포인트(코드가 시작되는곳) / main함수는 반드시 하나만 있어야함
{
	//printf("hi\n"); // c언어 출력방법
	//printf("\"백종민\"\t"); //""안에 \n이 있으면 줄을 바꾸라는 의미(이스케이프 시퀀스)
	//printf("96년생입니다.\n");

/* 
이스케이프 시퀀스 \ : 백슬래시
- \n : 줄바꾸기(개행문자)
- \t : 탭 넣기
- \" : 쌍따옴표 한개
- \\ : \넣기
- \r : 캐리지 리턴(윈도우에서는 중요하지 않음. 리눅수에서는 중요함 / 커서를 다음 줄 맨 앞으로 가게하는것)
*/

//	std::cout << "hi\n"; // c++ 출력 방법 / cout은 iostream에 속해있음 그래서 cout을 쓰려면 iostream을 incloud해야하는거임

	//int number = 0;

	//scanf("%d", &number); // 숫자를 하나 입력받기(c언어)
	//printf("입력한 숫자는 : %d\n", number);

	//std::cin >> number; // 숫자를 하나 입력받기(c++언어)
	//printf("입력한 숫자는(c++) : %d\n", number);

	// 당신의 나이는? (숫자 입력) 당신의 나이는 nn살 입니다. 출력
	//printf("당신의 나이는?\n");
	//std::cin >> number;
	//printf("당신의 나이는 : %d", number);
	//printf("살 입니다.\n");

/*
변수(variable)
 - 변하는 숫자
 - 컴퓨터에 값을 기억시키기 위해 만들고 사용
*/

/*
int number = 0; → number라는 이름을 가진 int(인티저)변수를 선언하고 거기에 0을 대입한다.
=
int number; // 변수 선언
number = 0; // 변수에 값을 대입

int : 정수형(소수점이 없는 숫자 / 소수점 뒤 숫자는 버림)
*/

/*
연산자(operator)
 - 계산을 하기 위한 기호
 - 대입 연산자 : 어디다가 뭘 넣어주는거 / 이거는 이거다
   = : 오른쪽에 있는 값을 왼쪽에 넣어라(a=b; // b에 있는 값을 a에 넣어라라는 뜻)
   == : 양변이 같다. (==랑 =는 다른거) / (a==b; // a는 b이다라는 뜻)
 - 산술 연산자
   +(더하기) -(빼기) *(곱하기) /(나누기) %(나머지 연산)
   ex) a = 5%3; // a = 2
 - 복합 대입연산자
   줄여쓰기용
   a += b; // 아래와 같은 코드
   a = a + b;
 - 증감 연산자
   a++;  // a에다가 1을 더해라
   a--;  // a에다가 1을 빼라
*/
	//int number1 = 0;
	//int number2 = 0;
	// 변수를 지정할땐 반드시 먼저 숫자를 빼먹지 않고 넣어줘라
	
	//printf("숫자1을 입력하시오 : ");
	//std::cin >> number1;
	//printf("숫자2을 입력하시오 : ");
	//std::cin >> number2;

	//int number3 = number1 + number2;
	//printf("두 숫자의 합은 %d입니다.", number3);

/* 
실습1
printf 문을 이용해서 아래와 같은 모양 찍어보기
	  *
	 ***
	*****
*/
	printf("  *\n");
	printf(" ***\n");
	printf("******\n\n");

/*
실습2
특수문자를 이용해서 미로 모양 출력해보기
□□□□□□□□
□  □      □  □
□       □      □
□□□□□□□□
*/
	printf("□□□□□□□□□\n");
	printf("□  □      □  □\n");
	printf("□      □      □\n");
	printf("□□□□□□□□□\n\n");
/*
실습3
두 수를 입력받아 스왑하기
*/
	int number4 = 0;
	int number5 = 0;
	
	printf("첫번째 숫자를 입력하시오 : \n");
	std::cin >> number5;
	printf("두번째 숫자를 입력하시오 : \n");
	std::cin >> number4;
	printf("%d", number4);
	printf("%d\n\n", number5);

/*
실습4
사각형의 가로, 세로를 입력 받아 넓이를 출력하기
*/
	int number1 = 0;
	int number2 = 0;
	
	printf("가로값을 입력하시오 : \n");
	std::cin >> number1;
	printf("세로값을 입력하시오 : \n");
	std::cin >> number2;
	
	int number3 = number1*number2;
	printf("해당 사각형의 넓이는 %d입니다.\n\n", number3);


/*
실습5
두 수를 입력 받아 나머지를 출력하기(%연산자 사용 금지)
*/
	int number6 = 0;
	int number7 = 0;

	printf("첫번째 숫자를 입력하시오 : \n");
	std::cin >> number6;
	printf("두번째 숫자를 입력하시오 : \n");
	std::cin >> number7;

	int number8 = number6 / number7;
	int number9 = number8 * number7;
	int number10 = number6 - number9;

	printf("%d\n\n", number6 - number9);

/*
실습6
시간계산기
- 초를 입력받아 시분초 출력하기
*/
	int number11 = 0;

	printf("초를 입력하시오 : \n");
	std::cin >> number11;

	int number12 = number11 / 720;
	int number13 = number12 % 720 / 60;
	int number14 = number12 % 720 % 60;

	printf("%d 시", number12);
	printf("%d 분", number13);
	printf("%d 초\n\n", number14);

/*
실습7 
동전개수 계산하기
- 금액을 입력받아 500원, 100원, 50원, 10원 동전이 각각 몇개 필요한지 계산하는 프로그램
- 금액이 큰 동전을 최대한 많이 받아야한다.
*/
	int number15 = 0;

	printf("금액을 입력하시오 : \n");
	std::cin >> number15;

	int number16 = number15 / 500;
	int number17 = number15 % 500 / 100;
	int number18 = number15 % 500 % 100 / 50;
	int number19 = number15 % 500 % 100 % 50 / 10;

	printf("500원 : %d개\n", number16);
	printf("100원 : %d개\n", number17);
	printf("50원 : %d개\n", number18);
	printf("10원 : %d개\n\n", number19);

/*
실습8
자리수 분리하기(입력은 항상 세자리라고 가정)
- 수를 입력하고 100의자리, 10의자리, 1의자리를 각각 출력하기
*/
	int number20 = 0;

	printf("세자리 숫자를 입력하시오 : \n");
	std::cin >> number20;
	
	int number21 = number20 / 100;
	int number22 = number20 % 100 / 10;
	int number23 = number20 % 100 % 10;

	printf("100의 자리 숫지 : %d\n", number21);
	printf("10의 자리 숫지 : %d\n", number22);
	printf("1의 자리 숫지 : %d\n", number23);

	return 0;
}
