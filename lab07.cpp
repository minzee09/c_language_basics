/*
lab7_함수.cpp

lab7 실습 프로그램(함수 적용 버전)
#1 도형의 면적계산(131쪽 programming #5)
   원, 삼각형, 사각형 중 택일하여 면적을 계산한다
#2 3개의 정수를 입력 받아 최대값을 출력한다
#3 문자 변환(대->소, 소->대, 대/소->소/대)
#4 두 수와 연산자를 입력 받아 사칙 연산자 처리(if문, switch문)
#5 1 ~ 100 사이의 소수 출력 (195쪽 programming #2)

학번: 2020111242
이름: 김민지
분반: 02(목56교시)
*/


#include <iostream>
using namespace std;

//#1 함수 - 사각형의 넓이 구하기
double square_area(double w, double h)
{
	return (w*h);
}
//#1 함수 - 원의 넓이 구하기
double circle_area(double r)
{
	return((r * r) * 3.14);
}


//#2 함수 - 최대값 찾기
int findMax(int n1, int n2, int n3)
{
	int max = 0;	//최대값

	if (n1 >= n2)
	{
		if (n1 >= n3)
			max = n1;
		else
			max = n3;
	}
	else
	{
		if (n2 >= n3)
			max = n2;
		else
			max = n3;
	}
	return max;
}
//#2 함수 - 최소값 찾기
int findMin(int n1, int n2, int n3)
{
	int min = 0;	//최소값

	if (n1 <= n2)
	{
		if (n1 <= n3)
			min = n1;
		else
			min = n3;
	}
	else
	{
		if (n2 <= n3)
			min = n2;
		else
			min = n3;
	}
	return min;
}

//#3 함수 - 소문자->대문자
char convertDownUp(char ch)
{
	return (ch - 32);
}
//#3 함수 - 대문자->소문자
char convertUpDown(char ch)
{
	return (ch + 32);
}

//#4 함수 - 사칙연산(if)
double calculateValuesIf(double v1, double v2, char op)
{
	double result=0;
	if (op == '+')
		result = v1 + v2;
	else if (op == '-')
		result = v1 - v2;
	else if (op == '*')
		result = v1 * v2;
	else if (op == '/')
		result = v1 / v2;

	return result;
}
//#4 함수 - 사칙연산(switch)
double calculateValuesSwitch(double v1, double v2, char op)
{
	double result = 0;
	switch (op)
	{
	case '+':
		result = v1 + v2;
		break;
	case '-':
		result = v1 - v2;
		break;
	case '*':
		result = v1 * v2;
		break;
	case '/':
		result = v1 / v2;
		break;
	default:
		break;
	}
	return result;
}

//#5 함수 - 소수 찾기
int isPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)			// 2 ~ n-1 까지 반복 
	{
		if (n % i == 0)				// 1과 자기 자신이 아닌 다른 수로 나누어 떨어지면 소수가 아니다.
			return 0;
	}
	return 1;
}

//*****************************< lab7 #1 >**********************************
// #1 원, 삼각형, 사각형 중 택일하여 면적을 계산한다
//**************************************************************************

int main()
{
	// 변수선언

	// #1
	double width, height, radius;// 밑변, 높이, 반지름
	char choice, yn;			 // 도형선택 

	// #2
	int n1, n2, n3;				 // 세 정수 

	// #3
	char ch;					// 입력문자

	// #4
	double v1, v2;				// 피연산자,
	char op;					// 연산자 
	bool ok = true;				// 수식의 유효성

	// #5
	int num;					 // 소수?

	//*****************************< lab7 #1 >**********************************
	// #1 원, 삼각형, 사각형 중 택일하여 면적을 계산
	//**************************************************************************

	cout << endl;
	cout << "lab7 #1" << endl << endl;

	do
	{
		// 메뉴 보인후 도형선택
		cout << endl;
		cout << "삼각형: t" << endl;
		cout << "사각형: r" << endl;
		cout << "원:     c" << endl;
		cout << "----------" << endl;
		cout << "도형의 종류를 입력하세요:";
		cin >> choice;

		if (choice == 'r' || choice == 'R')
		{
			cout << "밑변을 입력하세요 :";
			cin >> width;
			cout << "높이를 입력하세요 :";
			cin >> height;
			cout << "사각형의 면적은 : " << square_area(width, height) << "입니다." << endl;
		}
		else if (choice == 't' || choice == 'T')
		{
			cout << "밑변을 입력하세요 :";
			cin >> width;
			cout << "높이를 입력하세요 :";
			cin >> height;
			cout << "삼각형의 면적은 : " << square_area(width, height) / 2.0 << "입니다." << endl;
		}
		else if (choice == 'c' || choice == 'C')
		{
			cout << "반지름을 입력하세요 :";
			cin >> radius;
			cout << "원의 면적은 : " << circle_area(radius) << "입니다." << endl;
		}
		else
			cout << "잘못된 도형입니다." << endl;


		cout << endl;
		cout << "계속하시겠습니까? [y/n] : ";
		cin >> yn;

		// 화면 지우기
		system("cls");

	} while (yn == 'Y' || yn == 'y');


	//*****************************< lab7 #2 >**********************************
	// #2 3개의 정수를 입력 받아 최대, 최소값 계산
	//**************************************************************************

	cout << endl << endl;
	cout << "lab7 #2" << endl << endl;
	do
	{
		cout << endl;
		cout << "세 정수를 공백으로 분리하여 입력하세요 : ";
		cin >> n1 >> n2 >> n3;

		// 최대값
		cout << "가장 큰 값은 " << findMax(n1, n2, n3) << "입니다." << endl;

		// 최소값
		cout << "가장 작은 값은 " << findMin(n1, n2, n3) << "입니다." << endl << endl;

		cout << "계속하시겠습니까? [y/n] : ";
		cin >> yn;

	} while (yn == 'Y' || yn == 'y');

	// 화면 지우기
	system("cls");

	//*****************************< lab7 #3 >**********************************
	// #3 문자 변환(대->소, 소->대, 대/소->소/대)
	//**************************************************************************

	cout << endl;
	cout << "lab7 #3" << endl << endl;

	do {
		cout << endl;
		cout << "#3-1: 소문자 -> 대문자 변환" << endl;
		cout << "소문자를 입력하세요. : ";
		cin >> ch;
		if ((ch >= 'a') && (ch <= 'z'))
		{
			cout << "소문자 : " << ch << " => 대문자 : " << convertDownUp(ch) << endl << endl;
		}
		else
			cout << "소문자를 입력하지 않았습니다." << endl << endl;

		cout << "#3-2: 대문자 -> 소문자 변환" << endl;
		cout << "대문자를 입력하세요. : ";
		cin >> ch;
		if ((ch >= 'A') && (ch <= 'Z'))
		{

			cout << "대문자 : " << ch << " => 소문자 : " << convertUpDown(ch) << endl << endl;
		}
		else
			cout << "대문자를 입력하지 않았습니다." << endl << endl;

		cout << "계속하시겠습니까? [y/n] : ";
		cin >> yn;
	} while (yn == 'Y' || yn == 'y');

	// 화면 지우기
	system("cls");

	//*****************************< lab7 #4 >**********************************
	// #4 두 수와 연산자를 입력 받아 사칙 연산자 처리(if문, switch문)
	//**************************************************************************

	cout << endl << endl;
	cout << "lab7 #4" << endl << endl;

	cout << "수식을 입력하세요(예: 3 * 4) ";
	cin >> v1 >> op >> v2;

	if (op == '/' && v2 == 0)
		cout << "분모가 0이어서 나눌수 없습니다." << endl;
	else
	{
		// if문
			cout << endl;
			cout << "#4 if문" << endl;
			cout << v1 << " " << op << " " << v2 << " = " << calculateValuesIf(v1, v2, op) << endl << endl;

		// switch 문
			cout << endl;
			cout << "#4 switch문" << endl;
			cout << v1 << " " << op << " " << v2 << " = " << calculateValuesSwitch(v1, v2, op) << endl << endl;

		getchar(); getchar();
	}

	// 화면 지우기
	system("cls");

	//*****************************< lab7 #5 >**********************************
		// #5 1 ~100 사이의 모든 소수를 출력
		//**************************************************************************

	cout << endl << endl;
	cout << "lab7 #5" << endl << endl;

	cout << "2 ~ 100 사이의 소수는" << endl;

	// lab7 방법( 2 ~ n-1 사이의 모든 수로 나누어 한번이라도 나누어 떨어지면 소수가 아니다)

	//2 ~ 100까지 반복
	for (num = 2; num <= 100; num++)
	{
		//num이 소수면 출력
		if (isPrime(num) == 1)
		{
			cout << num << endl;
		}
	}

	system("pause");
	return 0;
}
