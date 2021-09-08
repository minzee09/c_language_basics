/*	김민지
	디지털미디어학과
	2020111242
	2분반
	4주차 과제 (20/04/9)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// #4
	double num1, num2;
	char ch;
	cout << "#4 계산기" << endl;
	cout << "*************" << endl;
	cout << "+ --- Add" << endl;
	cout << "- --- Subtract" << endl;
	cout << "* --- Multiply" << endl;
	cout << "/ --- Divide" << endl;
	cout << "*************" << endl;
	cout << endl;

	cout << "연산을 선택하시요: ";
	cin >> ch;

	cout << "두 수를 공백으로 분리하여 입력하세요:  ";
	cin >> num1 >> num2;

	//<if문 사용>
	cout << "if문: " << endl;
	//덧셈하는 경우
	if (ch == '+')
		cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
	//뺄셈하는 경우
	else if (ch == '-')
		cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
	//곱셈하는 경우
	else if (ch == '*')
		cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
	//나눗셈하는 경우
	else if (ch == '/')
		//분모가 0인 경우
		if (num2 == 0)
			cout << "분모가 0이여서 나눌 수 없습니다." << endl;
	//분모가 0이 아닌 경우
		else
			cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;
	//연산자 외에 입력한 경우 
	else
		cout << "잘못 입력했습니다." << endl;

	//<switch문 사용>
	cout << "switch문: " << endl;
	switch (ch)
	{
		//덧셈하는 경우
	case '+':
		cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
		break;
		//뺄셈하는 경우
	case '-':
		cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
		break;
		//곱셈하는 경우
	case '*':
		cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
		break;
		//나눗셈하는 경우
	case '/':
		//분모가 0인 경우
		if (num2 == 0)
			cout << "분모가 0이여서 나눌 수 없습니다." << endl;
		//분모가 0이 아닌 경우
		else
			cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;
		break;
		//연산자 외에 입력한 경우
	default:
		cout << "잘못 입력했습니다." << endl;
		break;
	}
	cout << endl;

	// #5
	char rtc;
	double n1, n2;
	cout << "#5 도형의 면적 구하기" << endl;
	cout << "문자를 입력하세요 (R,T,C) : ";
	cin >> rtc;


	//<if문 사용>
	cout << "if문:" << endl;
	// r 또는 R 입력한 경우
	if (rtc == 'r' || rtc == 'R')
	{
		cout << "밑변 길이, 높이를 입력하세요: ";
		cin >> n1 >> n2;
		cout << "사각형의 면적은 : " << n1 * n2 << endl;
	}
	// t 또는 T 입력한 경우
	else if (rtc == 't' || rtc == 'T')
	{
		cout << "밑변, 높이를 입력하세요: ";
		cin >> n1 >> n2;
		cout << "삼각형의 면적은 : " << (n1 * n2) / 2 << endl;
	}
	// c 또는 C 입력한 경우
	else if (rtc == 'c' || rtc == 'C')
	{
		cout << "반지름을 입력하세요: ";
		cin >> n1;
		cout << "원의 면적은 : " << pow(n1, 2) * 3.14 << endl;
	}
	//잘못 입력했을 경우
	else
		cout << "잘못 입력했습니다.(R, T, C)" << endl;
	cout << endl;

	//0으로 초기화
	n1, n2 = 0;

	//<switch문 사용>
	cout << "switch문:" << endl;
	switch (rtc)
	{
		// r 또는 R 입력한 경우
	case'r':
	case'R':
		cout << "밑변 길이, 높이를 입력하세요: ";
		cin >> n1 >> n2;
		cout << "사각형의 면적은 : " << n1 * n2 << endl;
		break;
		// t 또는 T 입력한 경우
	case't':
	case'T':
		cout << "밑변, 높이를 입력하세요: ";
		cin >> n1 >> n2;
		cout << "삼각형의 면적은 : " << (n1 * n2) / 2 << endl;
		break;
		// c 또는 C 입력한 경우
	case'c':
	case'C':
		cout << "반지름을 입력하세요: ";
		cin >> n1;
		cout << "원의 면적은 : " << pow(n1, 2) * 3.14 << endl;
		break;
		//잘못 입력했을 경우
	default:
		cout << "잘못 입력했습니다.(R, T, C)" << endl;
		break;
	}
	cout << endl;

	//#9
	char vc; //vowel consonants
	cout << "#9 모음과 자음을 구분" << endl;
	cout << "하나의 문자를 입력하세요 : ";
	cin >> vc;
	cout << endl;

	//알파벳인지 아닌지 구분
	if (vc <= 64 || (vc >= 91 && vc <= 96) || vc >= 123)//아스키코드 사용
		cout << "알파벳이 아닙니다." << endl;
	else
	{
		//<if문 사용>
		cout << "if문:" << endl;
		if (vc == 65 || vc == 69 || vc == 73 || vc == 79 || vc == 85 || vc == 97 || vc == 101 || vc == 105 || vc == 111 || vc == 117)//모음 (대소문자 포함)
			cout << "입력하신 문자는 모음입니다." << endl;
		else
			cout << "입력하신 문자는 자음입니다." << endl;

		//<switch문 사용>
		cout << "switch문:" << endl;
		switch (vc)
		{
		case 65: case 69: case 73: case 79: case 85: case 97: case 101: case 105: case 111: case 117://모음 (대소문자 포함)
			cout << "입력하신 문자는 모음입니다." << endl;
			break;
		default:
			cout << "입력하신 문자는 자음입니다." << endl;
			break;
		}
	}
	return 0;
}
