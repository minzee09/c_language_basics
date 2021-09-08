/*김민지
디지털미디어학과
2020111242
*/

#include<iostream>

using namespace std;

int main()
{
	//6번

	double kg;
	const double pound = 2.2;//기호상수 선언
	const double ounce = 16;//기호상수 선언
	cout << "#6: 킬로그램 => 파운드와 온스로 단위환산" << endl;
	cout << "무게를 입력하세요(kg): ";
	cin >> kg; //변수 kg에 입력된 값을 저장

	cout << kg << "킬로그램은(kg) " << kg * pound << " 파운드(lb)입니다." << endl;//킬로그램를 파운드로 변환하여 츨력
	cout << kg << "킬로그램은(kg) " << kg * pound * ounce << " 온스(oz)입니다." << endl;//킬로그램를 온스로 변환하여 츨력
	cout << endl;

	//9번

	int n,n1,n10,n100;
	cout << "#9: 10,000보다 작은 정수 => 천의 자리, 백의 자리, 십의 자리, 일의 자리로 분리 출력" << endl;
	cout << "10,000보다 작은 정수를 입력하세요: ";
	cin >> n;
	n1 = n % 10;//나머지 연산을 사용하여 일의 자리를 n1에 저장
	n /= 10;//십의 자리를 구하기 위해 n에 10을 나눠서 저장
	n10 = n % 10;//나머지 연산을 사용하여 십의 자리를 n10에 저장
	n /= 10;//백의 자리를 구하기 위해 n에 10을 나눠서 저장
	n100 = n % 10;//나머지 연산을 사용하여 백의 자리를 n100에 저장
	n /= 10;//천의 자리를 구하기 위해 n에 10을 나눠서 저장
	
	cout << "천의 자리: " << n << endl;
	cout << "백의 자리: " << n100 << endl;
	cout << "십의 자리: " << n10 << endl;
	cout << "일의 자리: " << n1 << endl;
	cout << endl;

	//11번
	double radius,height;
	const double pi = 3.14159;//기호상수 선언
	cout << "#11: 원기둥의 부피 계산" << endl;
	cout << "원기둥 밑면의 반지름을 입력하세요: ";
	cin >> radius;
	cout << "원기둥의 높이를 입력하세요: ";
	cin >> height;
	cout << "원기둥의 부피는 " << radius * radius * height * pi << "입니다." << endl;

	return 0;
}