
#define _CRT_SECURE_NO_WARNINGS // ← 보라색 글씨는 매크로?

//소스파일

#include <iostream> //include : 포함시키다 / iostream을 포함시켜라 / iostream : 인풋 아웃풋 스트림 입출력 관련 정보가 담겨있는거
//#include <cstdio> // iostream이 아니더라도 사용 가능
#include <stdio.h> // stdio.h에 네임스페이스 추가한 래퍼
#include <time.h> // c 스타일 랜덤 시드값 설정할때
#include <random> // c++ 스타일 랜덤 쓸때 
#include "TestMath.h" //헤더를 선언하면 헤더에 있는 내용이 전부 선언됨
#include "Practice.h"


int main() // 앤트리 포인트(코드가 시작되는곳) / main함수는 반드시 하나만 있어야함
{

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 25년 09월 02일 (화요일)

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

// 명령어에 빨간줄이 생기면 잘못됐다는 뜻
// 명령어에 녹색줄이 생기면 지금은 괜찮은데 문제될 수 있어라는 경고

//using namespace std; //std를 자동으로 추가시킨다는 것 / std위치를 알아야하기때문에 교육땐 빼고 쓸예정

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





//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 25년 9월 5일 (금요일)




	
	//// 함수
	//
	//

	//
	//int Number = Sum(1, 7);				// Sum 함수를 호출했다. 파라메터로 1과 7을 넘겼다. 그리고 8을 돌려받았다.

	//Number = Multiply(2, 3);			// 6
	//Number = Multiply(7);				// Number2를 TestMath.h(헤더파일)에서 =2 로 선언했기때문에 7*2로 입력됨


	//// 재귀 호출(Recurcive Call)

	////TestRecurcive(5);

	//// 탬플릿(Template)

	//float Number2 = Add(10.5f, 20.4f);	// 탬플릿을 사용함으로서 float로 인식해서 계산을 해줌

	////인라인

	//int Number3 = Square(3);

//
//// 실습1
//
//	printf("실습1\n특정 범위 안의 랜덤한 수를 리턴하는 함수\n\n");
//	printf("범위를 설정하시오.");
//	int Rage_1 = 0;
//	int Rage_2 = 0;
//	std::cin >> Rage_1;
//	std::cin >> Rage_2;
//
//	int Rage = RandomNumber1(Rage_1, Rage_2);
//	printf("%d와 %d사이 랜덤한 숫자는\n%d입니다.\n\n",Rage_1, Rage_2, Rage);
//
//// 실습2
//
//	printf("실습2\n\n당신의 나이를 입력해주세요 : \n");
//	int Age_2 = 0;
//	std::cin >> Age_2;
//
//	Age(Age_2);
//	
//// 실습3

	//printf("실습3\n원의 넓이 구하기 \n");
	//printf("원의 반지름을 입력하시오 : ");

	//int Radius_1 = 0;
	//std::cin >> Radius_1;

	//printf("원의 넓이는 %f입니다.\n\n", Radius(Radius_1));

//// 실습 4

	//printf("실습4\n짝수 홀수 판단하기 \n");
	//printf("숫자를 입력하시오. \n");

	//int InputNumber4 = 0;
	//std::cin >> InputNumber4;

	//Number4_1(InputNumber4);

//// 실습 5
//	
//	printf("실습5\n점수 측정하기 \n");
//	printf("점수를 입력하시오. \n");
//	
//	int InputNumber5 = 0;
//	std::cin >> InputNumber5;
//
//	Score(InputNumber5);
//
//// 실습 6
//
//int myInventory = 0;
//
//SetItem(myInventory, Sword);
//SetItem(myInventory, Shield);
//
//printf("현재 인벤토리 : %d", myInventory);
//
//ToggleItem(myInventory, Sword);
//printf("소드 토글 후 : %d", myInventory);
//
//UnSetItem(myInventory, Shield);
//printf("쉴드 해제 후 : %d", myInventory);
//
	
	
//// 실습 7
//
//	printf("실습7\n피라미드 만들기 \n");
//	printf("층수를 입력하시오. \n");
//
//	int InputNumber7 = 0;
//	std::cin >> InputNumber7;
//
//	Pyramid(InputNumber7);
	
//
//// 실습 8
//
//	printf("실습8\n작은 수 구하기 \n");
//	printf("두 수를 입력하시오. \n");
//	
//	int InputNumber8_1 = 0;
//	int InputNumber8_2 = 0;
//	std::cin >> InputNumber8_1;
//	std::cin >> InputNumber8_2;
//
//	Min(InputNumber8_1, InputNumber8_2);
//
//// 실습 9
//
//	printf("실습9\n큰 수 구하기 \n");
//	printf("두 수를 입력하시오. \n");
//	
//	int InputNumber9_1 = 0;
//	int InputNumber9_2 = 0;
//	std::cin >> InputNumber9_1;
//	std::cin >> InputNumber9_2;
//
//	Max(InputNumber9_1, InputNumber9_2);
//
//
//// 실습 10
//
//	printf("실습10\nClamp 구하기 \n");
//
//	int InputNumber10_1 = 0;
//	int InputNumber10_2 = 0;
//	int InputNumber10_3 = 0;
//
//	printf("숫자를 입력하시오. \n");
//	std::cin >> InputNumber10_1;
//	
//
//	printf("작은수와 큰수를 순서대로 입력하시오. \n");
//	
//	std::cin >> InputNumber10_2;
//	std::cin >> InputNumber10_3;
//
//	Clamp1(InputNumber10_1, InputNumber10_2, InputNumber10_3);

//// 실습 11
//
//	printf("실습11\n팩토리오 구하기 \n");
//	printf("숫자를 입력하시오\n");
//
//	int InputNumber11 = 0;
//	std::cin >> InputNumber11;
//
//	printf("%d!의 값은 %d 입니다.\n", InputNumber11, Factorial(InputNumber11));


// 주말 실습1
	printf("주말 실습1\n");
	printf("3개의 수 평균 구하기\n\n");

	printf("3개의 수를 입력하시오.\n");
	float InputNumber1_1 = 0;
	float InputNumber1_2 = 0;
	float InputNumber1_3 = 0;
	
	std::cin >> InputNumber1_1 >> InputNumber1_2 >> InputNumber1_3;

	printf(" 3개의 수의 평균은 %.1f입니다.\n\n", Average(InputNumber1_1, InputNumber1_2, InputNumber1_3));

// 주말 실습2
	printf("주말 실습2\n");
	printf("할인가 구하기\n\n");

	float InputNumber2_1 = 0;
	float InputNumber2_2 = 0;
	
	printf("정가를 입력하시오 : ");
	std::cin >> InputNumber2_1;
	printf("할인율을 입력하시오 : ");
	std::cin >> InputNumber2_2;

	printf("해당 상품의 할인가격은 %.2f입니다.\n\n", SalePrice(InputNumber2_1, InputNumber2_2));


// 주말 실습3
	printf("주말 실습3\n");
	printf("주사위 값 구하기\n\n");

	srand(time(0));

	printf("주사위 값 : %d\n\n", Dice(0));


// 주말 실습4

	printf("주말 실습4\n점수 측정하기 \n\n");
	printf("점수를 입력하시오. \n");
	
	int InputNumber4 = 0;
	std::cin >> InputNumber4;

	Score1(InputNumber4);

// 주말 실습5

	printf("주말 실습5\nClamp 측정하기 \n\n");
	
		int InputNumber5_1 = 0;
		int InputNumber5_2 = 0;
		int InputNumber5_3 = 0;
	
		printf("숫자를 입력하시오. \n");
		std::cin >> InputNumber5_1;
		
	
		printf("작은수와 큰수를 순서대로 입력하시오. \n");
		
		std::cin >> InputNumber5_2;
		std::cin >> InputNumber5_3;
	
		Clamp(InputNumber5_1, InputNumber5_2, InputNumber5_3);


// 주말 실습(심화) 1

	printf("주말 실습(심화)1\n");
	printf("자리수별 합 구하기\n\n");

	printf("숫자를 입력하시오 : ");
	int InputNumberOne = 0;
	std::cin >> InputNumberOne;
	printf("자리수별 합은 %d입니다.\n\n", TotalSum(InputNumberOne));



// 주말 실습(심화) 2

	printf("주말 실습(심화)2\n");
	printf("10진수 2진수로 변환하기\n\n");
	printf("10진수를 입력하세요 : ");
	int InputNumberTwo = 0;
	std::cin >> InputNumberTwo;

	printf("입력하신 숫자 %d의 2진수는 ", InputNumberTwo);
	DecToBin(InputNumberTwo);
	printf("입니다.\n\n");

// 주말 실습(심화) 3
	
	printf("주말 실습(심화)3\n");
	printf("슬롯머신 만들기\n\n");
	printf("※보유 금액이 100원이하가 되면 게임 오버입니다※\n");

	srand(time(0));
	int Money = 10000;

	while (Money >= 100)
	{
		printf("현재 금액 : %d입니다.\n", Money);
		printf("베팅할 금액을 입력하시오(최소 100원) : ");
		int Betting = 0;
		std::cin >> Betting;
		if (Betting > Money)
		{
			printf("베팅 금액이 현재 금액보다 많습니다. 다시 입력해주세요.\n\n");
			continue;
		}
		if (Betting < 100)
		{
			printf("최소 베팅 금액은 100원입니다. 다시 입력해주세요.\n\n");
			continue;
		}
		Money -= Betting;
		int SlotNumber1 = rand() % 10;
		int SlotNumber2 = rand() % 10;
		int SlotNumber3 = rand() % 10;

		printf("슬롯머신 결과 : %d %d %d\n", SlotNumber1, SlotNumber2, SlotNumber3);
		const int LuckyNumber = 7;

		if (SlotNumber1 == LuckyNumber && SlotNumber2 == LuckyNumber && SlotNumber3 == LuckyNumber)
		{
			printf("축하합니다! 777입니다!! 베팅 금액의 10,000배를 획득합니다!\n\n");
			Money += Betting * 10000;
			printf("현재 금액 : %d입니다.\n\n", Money);
		}
		else if (SlotNumber1 == SlotNumber2 && SlotNumber2 == SlotNumber3)
		{
			printf("축하합니다! 3개가 모두 일치합니다! 베팅 금액의 50배를 획득합니다!\n");
			Money += Betting * 50;
			printf("현재 금액 : %d입니다.\n\n", Money);
		}
		else
		{
			printf("모두 불일치입니다.\n\n");
		}
	}
	printf("※ 게 임 오 버 ※\n현재 잔액이 100원이하 입니다.\n\n");


	// 주말 실습(심화) 4


	printf("주말 실습(심화)4\n");
	printf("턴제 전투 만들기\n\n");

	srand(time(0));
	int PlayerHP = 100;
	int ComputerHP = 100;

	printf("숲속에서 몬스터를 만났습니다.\n");
	printf("전투를 시작합니다.\n\n");

	while (PlayerHP > 0 && ComputerHP > 0)
	{

		printf("플레이어가 선제 공격합니다.\n\n");
		int Damage1 = PlayerAttack(0);
		printf("%d 데미지!\n", Damage1);
		ComputerHP -= Damage1;
		printf("플레이어 HP : [%d] / 몬스터 HP : [%d]\n\n", PlayerHP, ComputerHP);
		if (ComputerHP <= 0)
		{
			printf("※ 승   리 ※\n몬스터를 처치했습니다!\n\n");
			break;
		}
		printf("몬스터가 반격합니다.\n\n");
		int Damage2 = ComputerAttack(0);
		printf("%d 데미지!\n", Damage2);
		PlayerHP -= Damage2;
		printf("플레이어 HP : [%d] / 몬스터 HP : [%d]\n\n", PlayerHP, ComputerHP);
		if (PlayerHP <= 0)
		{
			printf("※ 게 임 오 버 ※\n플레이어가 사망했습니다.\n\n");
			break;
		}
	}

	/*
	주말 실습(심화)5
	도둑 잡기 만들기
	- 시작 금액 10000
	- 한판에 무조건 최소 100 배팅해야 함. 만약 소지금액이 100 이하일 경우 게임 종료.
	- 딜러는 A~K까지의 트럼프 카드 중 2장을 중복없이 선택하고 조커 카드가 추가된다.
	- 플레이어는 딜러의 카드 중 한장을 선택한다.
	- 만약 플레이어가 조커를 뽑있다면 플레이어의 승리. 배팅 금액의 2배를 받는다.
	- 플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.
*/

	// 주말 실습(심화)5

	printf("주말 실습(심화)4\n");
	printf("도둑 잡기\n\n");
	printf("※보유 금액이 100원이하가 되면 게임 오버입니다※\n");

	srand(time(0));
	int PlayerMoney = 10000;

	while (PlayerMoney >= 100)
	{
		printf("현재 금액 : %d입니다.\n", PlayerMoney);
		printf("베팅할 금액을 입력하시오(최소 100원) : ");
		int Betting = 0;
		std::cin >> Betting;
		if (Betting > PlayerMoney)
		{
			printf("베팅 금액이 현재 금액보다 많습니다. 다시 입력해주세요.\n\n");
			continue;
		}
		if (Betting < 100)
		{
			printf("최소 베팅 금액은 100원입니다. 다시 입력해주세요.\n\n");
			continue;
		}
		PlayerMoney -= Betting;

		int DealerCard1 = rand() % 13; +1;
		int DealerCard2 = rand() % 13; +1;
		do
		{
			DealerCard2 = rand() % 13 + 1;
		} while (DealerCard1 == DealerCard2);

	}
	

			

//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	return 0;
}
