
#define _CRT_SECURE_NO_WARNINGS // ← 보라색 글씨는 매크로?

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
#include <time.h> // c 스타일 랜덤 시드값 설정할때
#include <random> // c++ 스타일 랜덤 쓸때 

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




//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ




// 25년 09월 03일 (수요일) 


//float number1 = 10.0f; // 10이라는 float 타입의 값을 float인 number2에 넣기
//					   // 실수타입은 f를 보통 넣어준다.
//float number2 = 15.0;  // 15라는 double 타입의 값을 float인 number2에 넣기
//					   // f를 안넣은건 double임
//std::cin >> number1 >> number2;
//printf("number1 : %f\nnumber2 : %f", number1, number2); //정수형은 %d / 실수형은 %f
//														//%f에 %.2f로 치면 소수점 2자리까지 출력됨

//간단 실습 : 원의 반지름을 입력받고 넓이 구하기

//const float number2 = 3.141592f; // 상수를 설정하려면 앞에 "const"를 붙히면 된다.
//float number1 = 0.0f;

//printf("반지름을 입력하시오.\n");
//std::cin >> number1;
//printf("원의 넓이는 :%.2f입니다.\n", number1 * number1 * number2);

//(단축키) ctrl + r + r : 전체 이름바꾸기 



	//비교 연산자


	//float a = 123.0f;
	//float b = 0.0f;

	//std::cin >> b;
	//b = b * 123.0f;

	//bool result = a == b;       // f9 : 브레이크 포인트 설정/ 헤제

	//float 타입을 ==로 비교할 때 반드시 아래와 같이 진행해야함. 

	//float epsilon = 0.001f;     
	//a > (b + epsilon);
	//a < (b + epsilon);              // 이정도의 오차범위는 맞았다고 치자! 라는거


	// 제어문

	// 조건문

	// if : 소괄호 안이 true면 중괄호 안의 코드를 실행하라.
	//		내가 특정 조건을 만족할 때만 어떤 코드를 실행하고 싶을 때 사용.

	//int a = 10;
	//int b = 0;
	//printf("a는 10\nb를 입력하시오 : ");
	//std::cin >> b;

	//if (a > b)
	//{
	//	printf("b가 %d라서 a가 더 크다\n", b);
	//}

	//if (a <= b)
	//{
	//	printf("b가 %d라서 a가 더 작거나 같다\n", b);
	//}


	//// if-else

	//if (a > b)
	//{
	//	printf("a가 b보다 크다.\n");
	//}
	//else
	//{
	//	printf("a가 b보다 크다/\n");
	//}


	//if (b < 60)
	//{
	//	//F
	//}
	//else if (b < 70)
	//{
	//	//D
	//}
	//else if (b < 80)
	//{
	//	//C
	//}
	//else if (b < 90)
	//{
	//	//B
	//}
	//else 
	//{
	//	//A
	//}


	// switch

	//int a = 0;
	//std::cin >> a;
	//switch (a)
	//{
	//case 1 :
	//	printf("1이다.\n");
	//	break;
	//case 3 :
	//	printf("3이다.\n");
	//	break;
	//case 5 :
	//	printf("5이다.\n");
	//	break;
	//default :
	//	printf("1,3,5가 아니다.\n");
	//	break;
	//}


	// 삼항연산자

	//int a = 10;
	//int b = 20;
	//int c = 0;


	//if (a > b)
	//{
	//	c = a * 2 + b;
	//}
	//else
	//{
	//	c = a + b * 2;
	//}
	//c = (a > b) ? (a * 2 + b) : (a + b * 2); // 삼향 연산자 / 위 if-else를 미관상 예쁘게 만드는거




	// 논리 연산자

	//int a = 10;
	//if (a > 5 && !(10 > a))
	//{
	//	// 성공
	//}
	//else
	//{
	//	// 실패
	//}




//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ




// 25년 9월 4일 (목요일)	


	// 비트연산자

	//// &
	//int flag = 0b1010;    
	//// 0b0001 = 왼쪽 키가 눌려졌다.
	//// 0b0010 = 오른쪽 키가 눌려졌다.
	//// 0b0100 = 위쪽 키가 눌려졌다.
	//// 0b1000 = 아래쪽 키가 눌려졌다.
	//
	//if ((flag & 0b0010) != 0b0000)
	//{
	//	// 오른쪽 키가 눌려져 있다.
	//}
	//else
	//{
	//	// 오른쪽 키가 눌려져 있지 않다.
	//}

	//// |
	////int flag = 0b1010;
	//flag = flag | 0b0001;	// 결과는 flag = 0b1011;

	//// ^
	////int flag =        0b1010;
	//int result = flag ^ 0b0001;    // 결과 = 0b1011;
	//result = 0b1011 ^ 0b0001;      // 결과 = 0b1010;

	//// ~
	////int flag =        0b1010;
	//int test = 0b0001;
	//test = ~test;	// 왼쪽키를 제외한 나머지 모두 세팅

	//// enum : 상수들에게 사람이 알아보기 좋은 이름을 붙여 놓은것
	//enum Key
	//{
	//	Up    = 1 << 0,  // 0b0001
	//	Down  = 1 << 1,  // 0b0010
	//	Left  = 1 << 2,  // 0b0100
	//	Right = 1 << 3   // 0b1000
	//};

	//if ((flag & Up) != 0) 
	//{

	//}

//// 간단실습 : 양수를 하나 입력받고 홀수인지 짝수인지 출력하기(%사용금지)
//
//	int InputNumber = 0;
//	printf("테스트할 수를 입력하시오 : ");
//	std::cin >> InputNumber;
//
//	if ((InputNumber & 0b0001) != 0b0000)   // = if ((InputNumber & 1) != 0) 같은 내용임
//	{
//		printf("입력하신 수는 홀수입니다.\n");
//	}
//	else
//	{
//		printf("입력하신 수는 짝수입니다.\n");
//	}


	//// 반복문
	//// for

	//// 헬로 월드 10번 찍기
	//for (int i = 0; i < 10; i++)    // 복습) ++ = 1씩 더하기   / 2씩 더하고 싶을땐 +=2 라고 쓰면됨
	//{
	//	printf("Hello World : %d\n", i);
	//}


	//// while
	//int Count = 1;
	//while ((Count % 3) != 0)        // while()의 조건이 참이면 코드 블럭 실행 // 3의 배수라는 뜻
	//{
	//	printf("Hello World while : %d\n", Count);
	//	Count++;
	//}


	////do-while

	//int Count = 1;
	//do
	//{
	//	printf("Hello World while : %d\n", Count);
	//	Count++;
	//} while ((Count % 3) != 0);


//
///*
//간단 실습1
//0을 입력받을때까지 입력을 계속 받고 0이 입력되면 입력받은 숫자의 합을 출력하기
//*/
//
//	printf("실습1. 0을 입력받을때까지 입력을 계속 받고 0이 입력되면 입력받은 숫자의 합을 출력합니다.\n\n");
//	printf("숫자를 입력하시오 : ");
//
//	// while 버전
//
//	int InputNumber1 = -1;           // 0부터 시작할시 바로 끝나버리기 때문에 -1로 선언 시작
//	int Sum = 0;
//
//	while (InputNumber1 != 0)
//	{
//		std::cin >> InputNumber1;
//		Sum += InputNumber1;
//	}
//
//	printf("입력받은 숫자의 합은 : %d입니다.\n\n", Sum);
//
//
//	// do-while 버전
//
//	int InputNumber2 = 0;
//	int Sum1 = 0;
//
//	do
//	{
//		std::cin >> InputNumber2;
//		Sum1 += InputNumber2;
//	} while (InputNumber2 != 0);
//	
//
//	printf("입력받은 숫자의 합은 : %d입니다.", Sum);
//	
///*
//간단 실습2
//입력받은 숫자의 구구단 출력해보기
//*/
//
//	int InputNumber3 = 0;
//
//	printf("실습2. 입력받은 숫자의 구구단을 출력합니다.\n\n");
//	printf("숫자를 입력하시오 : ");
//	std::cin >> InputNumber3;
//
//	for (int X = 1; X < 10; X++)
//	{
//		int Share = InputNumber3 * X;
//		printf("%d", InputNumber3);
//		printf(" X %d = ", X);
//		printf("%d\n\n", Share);	// printf("%d x %d = %d\n", Inputnumber, X, Share) 이렇게 쳐도 됨
//	}
//
//
///*
//간단 실습3
//숫자를 하나 입력 받고 입력받은 수까지 있는 숫자 중 홀수만 출력하기
//*/ 
//
//	int InputNumber4 = 0;
//
//	printf("실습3. 입력받은 숫까지 있는 숫자 중 홀수만 출력합니다.\n\n");
//	printf("숫자를 입력하시오 : ");
//	std::cin >> InputNumber4;
//
//	for (int OddNumber = 1; OddNumber <= InputNumber4; OddNumber++)
//	{
//		if (OddNumber % 2 == 1)
//		{
//			printf("%d\n\n", OddNumber);
//		}
//	}
//
///*
//간단 실습4
//1 ~ 100사이의 숫자 중 7의 배수만 출력하기
//*/ 
//
//	printf("실습4. 1 ~ 100사이의 숫자 중에서 7의 배수만 출력하기.\n\n");
//
//	const int MinNumber = 1;
//	const int MaxNumber = 100;
//	for (int Multiple = MinNumber; Multiple <= MaxNumber; Multiple++)
//	{
//		if ((Multiple % 7) == 0)
//		{
//			printf("%d \n\n", Multiple);
//		}
//	}
//
//
///*
//간단 실습5
//입력받은 숫자 만큼의 층을 가진 피라미드 그리기
//ex) 3 =
//   *
//  ***
// *****
//*/ 
//
//	int InputNumber5 = 0;
//	printf("실습5. 입력받은 숫자 만큼의 층을 가진 피라미드 그리기.\n\n");
//	printf("숫자를 입력하시오 : ");
//	std::cin >> InputNumber5;
//
//	// 줄 : line
//	// 간격 : space
//	// * : star
//	for (int Line = 0; Line <= InputNumber5; Line++)
//	{
//		for (int Space = 0; Space < (InputNumber5 - Line); Space++)
//		{
//			printf(" ");
//		}
//		for (int Star = 0; Star < (2 * Line) - 1; Star++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}


	//// 제어문

	//// continue


	//int InputNumber4 = 0;

	//printf("실습3. 입력받은 숫까지 있는 숫자 중 홀수만 출력합니다.\n\n");
	//printf("숫자를 입력하시오 : ");
	//std::cin >> InputNumber4;

	//for (int OddNumber = 1; OddNumber <= InputNumber4; OddNumber++)
	//{
	//	if (OddNumber % 2 == 0)
	//	{
	//		continue;
	//	}
	//	printf("%d\n\n", OddNumber);
	//}


	//// break

	//printf("실습1. 0을 입력받을때까지 입력을 계속 받고 0이 입력되면 입력받은 숫자의 합을 출력합니다.\n\n");
	//printf("숫자를 입력하시오 : ");


	//int InputNumber1 = -1;           // 0부터 시작할시 바로 끝나버리기 때문에 -1로 선언 시작
	//int Sum = 0;

	//while (true)
	//{
	//	std::cin >> InputNumber1;
	//	Sum += InputNumber1;
	//
	//	if (InputNumber1 == 0)
	//		break;
	//}
	//printf("입력받은 숫자의 합은 : %d입니다.\n\n", Sum);



	//// 랜덤

	//// C 스타일의 랜덤 사용법
	//
	//srand(time(0));		// 시간에 따라 시드값을 설청하는것
	////srand(0);			// 이걸 쓰면 시드값 고정
	//for (int i = 0; i < 3; i++)
	//{
	//	int RandomNumber = rand();
	//	printf("랜덤한 숫자 : %d\n", RandomNumber);
	//}

	//// 0 ~ 5 까지의 숫자를 랜덤으로 구하고 싶다.
	//int RandomNumber1 = rand() % 6;

	//// 1 ~ 6 까지의 숫자를 랜덤으로 구하고 싶다.
	//int RandomNumber1 = rand() % 6 + 1;


	//// C++ 스타일

	//std::random_device RandomDivece;		//랜덤장치를 만듬
	//std::mt19937 Generate(RandomDivece());

	//printf("균등분포 : ");
	//std::uniform_int_distribution<> uniformDis(1, 100);
	//for (int i = 0; i < 10; i++)
	//{
	//	int Number = uniformDis(Generate);
	//	printf("%d", Number);
	//	if (i < 9)
	//	{
	//		printf(", ");
	//	}
	//}
	//printf("\n");

	//
	//printf("정규분포 : ");
	//std::normal_distribution<> nomalDis(80, 10);
	//for (int i = 0; i < 10; i++)
	//{
	//	float fNumber = uniformDis(Generate);
	//	printf("%.2f", fNumber);
	//	if (i < 9)
	//	{
	//		printf(", ");
	//	}
	//}
	//printf("\n");


//
//
///*
//실습1
//주사위를 100만번 돌려서 6이 몇번 나왔는지 카운팅해서 출력하기
//*/
//
//	printf("실습1 주사위를 100만번 돌려서 6이 몇번 나왔는지 카운팅해서 출력하시오. \n\n");
//
//	int count6 = 0;
//
//	srand(time(0));
//	for (int i = 0; i < 1000000; i++)
//	{
//		int RandomNumber = rand() % 6 + 1;
//		if (RandomNumber == 6)
//		{
//			count6++;
//		}
//
//	}
//	printf("6은 총 %d번 나왔습니다.\n\n", count6);
//
//
///*
//실습2
//가위, 바위, 보 게임 만들기
//- 3선 승제
//- enum 활용
//*/
//
//
//	printf("실습2 가위바위보 게임 만들기 / 3선승제. \n\n");
//
//	int RPS = 0;
//	int Score1 = 0;
//	int Score2 = 0;
//
//	
//	enum RPS
//	{
//		Scissor = 0,
//		Rock = 1,
//		Paper = 2,
//	};
//
//	while ((Score1 <3 ) && (Score2 < 3))
//	{
//		printf("가위 바위 보 중 선택하시오.\n");
//		printf("(가위 : 0, 바위 : 1, 보 : 2)\n");
//
//		std::cin >> RPS;
//
//		srand(time(0));
//
//		int RandomNumber1 = rand() & 3;
//
//
//		if (RPS == 0)
//		{
//			if (RandomNumber1 == 2)
//			{
//				printf("승리하였습니다.\n\n");
//				Score1++;
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//			else if (RandomNumber1 == 1)
//			{
//				printf("패배하였습니다.\n\n");
//				Score2++;
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//			else
//			{
//				printf("비겼습니다.\n\n");
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//		}
//
//		if (RPS == 1)
//		{
//			if (RandomNumber1 == 0)
//			{
//				printf("승리하였습니다.\n\n");
//				Score1++;
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//			else if (RandomNumber1 == 2)
//			{
//				printf("패배하였습니다.\n\n");
//				Score2++;
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//			else
//			{
//				printf("비겼습니다.\n\n");
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//		}
//
//		if (RPS == 2)
//		{
//			if (RandomNumber1 == 1)
//			{
//				printf("승리하였습니다.\n\n");
//				Score1++;
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//			else if (RandomNumber1 == 0)
//			{
//				printf("패배하였습니다.\n\n");
//				Score2++;
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//			else
//			{
//				printf("비겼습니다.\n\n");
//				printf("나 : 컴퓨터 -> %d : %d\n", Score1, Score2);
//			}
//		}
//	}
//	
//	
//
//	/*
//	실습3
//	하이 로우
//	- 컴퓨터가 1~100 사이의 임의의 숫자를 선택하고, 사용자가 맞출 때까지 입력을 받아 "더 높게", "더 낮게"등의 힌트를 제공하는 게임
//	- 5번안에 맞춰야 승리
//	*/
//
//	printf("실습3 하이로우. \n\n");
//	printf("1 ~ 100 사이의 숫자를 맞추시오. \n");
//
//	int InputNumber3 = 0;
//	int Count3 = 0;
//
//	srand(time(0));
//	int RandomNumber3 = rand() % 100 +1;
//	
//	while (InputNumber3 != RandomNumber3)
//	{
//		printf("숫자를 입력하시오 :");
//		std::cin >> InputNumber3;
//		if (InputNumber3 > RandomNumber3)
//		{
//			printf("DOWN\n\n");
//			Count3++;
//		}
//		else if (InputNumber3 < RandomNumber3)
//		{
//			printf("UP\n\n");
//			Count3++;
//		}
//		else
//		{
//			printf("정답입니다.\n\n");
//		}
//	}
//	
//	if (Count3 <= 5)
//	{
//		printf("승리하였습니다.\n\n");
//	}
//	else
//	{
//		printf("승리하지 못했습니다.\n\n");
//	}
//
//	/*
//	실습4
//	공포게임의 인벤토리를 비트플래그로 표현하기
//	- 아이템 종류를 나타내는 enum을 만들고
//	- 특정 아이템을 추가하고 삭제하는 예시보여주기
//	*/
//
//	printf("실습4 공포게임의 인벤토리를 비트플래그로 표현하기. \n\n");
//
//
//	int Select = 0;
//	int Item = 0;
//	
//
//	printf("ㅡㅡㅡㅡ인벤토리ㅡㅡㅡㅡ\n");
//	printf("- 손전등\n");
//	printf("- 열쇠\n");
//	printf("- 몽둥이\n\n");
//	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//
//
//	enum Select
//	{
//		추가 = 0b0001,
//		삭제 = 0b0010,
//		종료 = 0b0011
//	};
//
//	enum Item
//	{
//		손전등 = 0b0001,
//		열쇠 = 0b0010,
//		몽둥이 = 0b0011,
//	};
//	
//	
//	while (Select < 3)
//	{
//		printf("아이템을 추가하시겠습니까? 삭제하시겠습니까?\n");
//
//		printf("추가 : 1\n삭제 : 2\n종료 : 3\n\n");
//		std::cin >> Select;
//		printf("\n");
//		if (Select == 1)
//		{
//			printf("무엇을 추가하시겠습니까?\n");
//			printf("손전등 : 1\n열쇠 : 2\n몽둥이 : 3\n\n");
//			std::cin >> Item;
//			printf("\n");
//			if (Item == 1)
//			{
//				printf("ㅡㅡㅡㅡ인벤토리ㅡㅡㅡㅡ\n");
//				printf("- 손전등\n");
//				printf("- 열쇠\n");
//				printf("- 몽둥이\n");
//				printf("- 손전등\n\n");
//				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//			}
//			else if (Item == 2)
//			{
//				printf("ㅡㅡㅡㅡ인벤토리ㅡㅡㅡㅡ\n");
//				printf("- 손전등\n");
//				printf("- 열쇠\n");
//				printf("- 몽둥이\n");
//				printf("- 열쇠\n\n");
//				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//			}
//			else
//			{
//				printf("ㅡㅡㅡㅡ인벤토리ㅡㅡㅡㅡ\n");
//				printf("- 손전등\n");
//				printf("- 열쇠\n");
//				printf("- 몽둥이\n");
//				printf("- 몽둥이\n\n");
//				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//			}
//		}
//		else if(Select == 2)
//		{
//			printf("무엇을 삭제하시겠습니까?\n");
//			printf("손전등 : 1\n열쇠 : 2\n몽둥이 : 3\n\n");
//			std::cin >> Item;
//			printf("\n");
//			if (Item == 1)
//			{
//				printf("ㅡㅡㅡㅡ인벤토리ㅡㅡㅡㅡ\n");
//				printf("- 열쇠\n");
//				printf("- 몽둥이\n");
//				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//			}
//			else if (Item == 2)
//			{
//				printf("ㅡㅡㅡㅡ인벤토리ㅡㅡㅡㅡ\n");
//				printf("- 손전등\n");
//				printf("- 몽둥이\n");
//				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//			}
//			else
//			{
//				printf("ㅡㅡㅡㅡ인벤토리ㅡㅡㅡㅡ\n");
//				printf("- 손전등\n");
//				printf("- 열쇠\n");
//				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//			}
//		}
//		else
//		{
//			printf("종료합니다.\n");
//			break;
//
//		}
//	}





// 실습 풀이 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ(09.05)

//
//
///*
//실습1
//주사위(1 ~ 6)를 100만번 돌려서 6이 몇번 나왔는지 카운팅해서 출력하기
//*/
//	const int TestCount = 1000000;
//	int HitCount = 0;
//	for (int i = 0; i < TestCount; i++)		// 100만번 돌려서
//	{
//		int dice = rand() % 6 + 1;  			 // 주사위 결과 ( 1 ~ 6 )를
//		if (dice == 6)							// 6이 몇번 나왔는지
//		{
//			HitCount++;							// 카운팅해서
//		}
//
//	}
//	printf("6이 나온 회수 = %d\n", HitCount);	// 출력하기
//
//
//	/*
//	실습2
//	가위, 바위, 보 게임 만들기
//	- 3선 승제
//	- enum 활용
//	*/
//
//	enum RockPaperScissors
//	{
//		Scissors,
//		Rock,
//		Paper,
//		NumOfRPS
//	};
//
//	const int WinGoal = 3;
//	int PlayerWinCount = 0;
//	int ComWinCount = 0;
//
//	while (PlayerWinCount < WinGoal && ComWinCount < WinGoal)
//	{
//		int PlayerSelect = -1;
//
//		while (true)
//		{
//			printf("선택하세요. [0:가위, 1:바위, 2:보] :");		// 플레이어가 제대로된 값을 작성할때까지 계속 뜨게 하기
//			std::cin >> PlayerSelect;
//
//			if (PlayerSelect == Scissors
//				|| PlayerSelect == Rock
//				|| PlayerSelect == Paper)
//			{
//				break;
//			}
//			printf("잘못된 입력입니다. 다시 입력하세요\n");
//		}
//		int ComSelect = rand() % NumOfRPS;		// 컴퓨터 선택
//		// 3대신 NumOfRPS를 쓴이유는 나중에 저기에 숫자를 추가하게 될 경우 편하게 적용되기때문
//
//		switch (PlayerSelect)					// 승패 결정
//		{
//		case Scissors:
//			if (ComSelect == Scissors)
//			{
//				printf("당신은 [가위]를 선택했고 컴퓨터는 [가위]를 선택했습니다.\n");
//				printf("비겼습니다.\n");
//			}
//			else if (ComSelect == Rock)
//			{
//				printf("당신은 [가위]를 선택했고 컴퓨터는 [바위]를 선택했습니다.\n");
//				printf("패배했습니다.\n");
//				ComWinCount++;
//			}
//			else if (ComSelect == Paper)
//			{
//				printf("당신은 [가위]를 선택했고 컴퓨터는 [보]를 선택했습니다.\n");
//				printf("승리했습니다.\n");
//				PlayerWinCount++;
//			}
//			else
//			{
//				printf("ERROR!!!!!\n");
//			}
//			break;
//		case Rock:
//			if (ComSelect == Scissors)
//			{
//				printf("당신은 [바위]를 선택했고 컴퓨터는 [가위]를 선택했습니다.\n");
//				printf("승리했습니다.\n");
//				PlayerWinCount++;
//			}
//			else if (ComSelect == Rock)
//			{
//				printf("당신은 [바위]를 선택했고 컴퓨터는 [바위]를 선택했습니다.\n");
//				printf("비겼습니다.\n");
//			}
//			else if (ComSelect == Paper)
//			{
//				printf("당신은 [바위]를 선택했고 컴퓨터는 [보]를 선택했습니다.\n");
//				printf("패배했습니다.\n");
//				ComWinCount++;
//			}
//			else
//			{
//				printf("ERROR!!!!!\n");
//			}
//			break;
//		case Paper:
//			if (ComSelect == Scissors)
//			{
//				printf("당신은 [보]를 선택했고 컴퓨터는 [가위]를 선택했습니다.\n");
//				printf("패배했습니다.\n");
//				ComWinCount++;
//			}
//			else if (ComSelect == Rock)
//			{
//				printf("당신은 [보]를 선택했고 컴퓨터는 [바위]를 선택했습니다.\n");
//				printf("승리했습니다.\n");
//				PlayerWinCount++;
//			}
//			else if (ComSelect == Paper)
//			{
//				printf("당신은 [보]를 선택했고 컴퓨터는 [보]를 선택했습니다.\n");
//				printf("비겼습니다.\n");
//			}
//			else
//			{
//				printf("ERROR!!!!!\n");
//			}
//			break;
//		default:								// 예상외의 사건이 발생함 / 내가 잘못 짰다는 뜻
//			printf("ERROR!!!!!\n");
//			break;
//		}
//
//		printf("Player = [%d], Com : [%d]\n", PlayerWinCount, ComWinCount);
//	}
//
//	if (PlayerWinCount >= WinGoal)
//	{
//		printf("당신이 컴퓨터를 이겼습니다!\n");
//	}
//	else
//	{
//		printf("당신이 컴퓨터에게 졌습니다.\n");
//	}
//
//
///*
//실습3
//하이 로우
//- 컴퓨터가 1~100 사이의 임의의 숫자를 선택하고, 사용자가 맞출 때까지 입력을 받아 "더 높게", "더 낮게"등의 힌트를 제공하는 게임
//- 5번안에 맞춰야 승리
//*/
//
//	int RandomNumber = rand() % 100 +1;
//	int PlayerNumber = 0;
//	int CountDown = 5;
//	
//
//	while (CountDown > 0)
//	{
//		printf("1 ~ 100 사이의 숫자를 예상해 보세요 : ");
//		std::cin >> PlayerNumber;
//
//		if (PlayerNumber < RandomNumber)
//		{
//			printf("더 큰 수를 찍어보세요.\n");
//		}
//		else if (PlayerNumber > RandomNumber)
//		{
//			printf("더 작은 수를 찍어보세요.\n");
//		}
//		else
//		{
//			printf("정답입니다.\n찾는 수는 %d였습니다.\n", RandomNumber);
//			break;
//		}
//		CountDown--;
//		printf("남은 횟수는 %d번 입니다.\n", CountDown);
//	}
//	if (CountDown <= 0)
//	{
//		printf("패배하였습니다.");
//	}
//	else
//	{
//		printf("승리하였습니다.");
//	}
//


	/*
	실습4
	공포게임의 인벤토리를 비트플래그로 표현하기
	- 아이템 종류를 나타내는 enum을 만들고
	- 특정 아이템을 추가하고 삭제하는 예시보여주기
	*/

	enum
	{
		Key  = 1 << 0,
		Fuse = 1 << 1,
		Book = 1 << 2,
		Note = 1 << 3,
	};

	const int ItemCount = 4;
	int Inventory = 0;

	Inventory = 0b1111;					// 테스트 코드

	int PlayerSelect = -1;

	while (PlayerSelect != 3)
	{

		printf("어떤 일을 할까요 [ 1 : 아이템추가, 2 : 아이템삭제, 3 : 종료 ]");
		std::cin >> PlayerSelect;

		switch (PlayerSelect)
		{
			case 1:
			{
				printf("어떤 아이템을 추가할까요?\n [0:열쇠, 1:퓨즈, 2:책, 3:쪽지] : ");
				int AddItem = 0;
				std::cin >> AddItem;
				Inventory |= (1 << AddItem);
			}
			break;
			case 2:
			{
				printf("어떤 아이템을 제거할까요?\n [0:열쇠, 1:퓨즈, 2:책, 3:쪽지] : ");
				int RemoveItem = 0;
				std::cin >> RemoveItem;
				Inventory &= (~(1 << RemoveItem));
			}
			break;

			case 3:
			{
				continue;
			}

		}

			printf("인벤토리 : ");
			if ((Inventory & Key) != 0)			// 인벤토리 출력 코드
			{
				printf("열쇠 \n");
			}
			if ((Inventory & Fuse) != 0)
			{
				printf("퓨즈 \n");
			}
			if ((Inventory & Book) != 0)
			{
				printf("책 \n");
			}
			if ((Inventory & Note) != 0)
			{
				printf("노트 \n");
			}
	}


	/*
	실습5
	주사위 게임 만들기
	1. 초기 세팅
	   플레이어와 컴퓨터 모두 일정 금액(예: 10000원)으로 시작한다.
	2. 1차 주사위 굴리기
	   게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
	   각자 주사위 결과를 공개한다.
	3. 배팅
	   이전 판에서 진 쪽이 배팅 금액을 제시한다.
	   제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
	   배팅 금액은 두 사람 모두에게서 차감된다.
	4. 2차 주사위 굴리기
	   다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
	5. (1차+2차) 주사위의 합을 계산한다.
	   승패 판정 및 금액 증감
	   합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
	   동점일 경우 배팅 금액은 그대로 반환한다.
	6. 다음 판 진행
	   소지금이 0 이하인 쪽이 나오면 게임 종료.
	*/
	

	/*
	실습6
	홀짝 게임
	1. 초기 금액 및 배팅
	   플레이어는 기본금 100원으로 베팅을 시작한다.
	2. 홀짝 선택
	   플레이어가 1(홀) 또는 2(짝)을 선택한다.
	3. 결과 결정
	   컴퓨터가 랜덤으로 1(홀) 또는 2(짝)을 선택한다.
	   플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
	4. 연속 배팅 선택
	   승리 시 플레이어는 두 가지 중 하나를 선택:
	   (A) 이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)
	   (B) 이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
	5. 게임 종료 조건
	   플레이어가 소지금이 100원 미만일 경우 게임 종료.
	*/



	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	return 0;
}