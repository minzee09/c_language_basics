//이름:김민지
//학번:2020111242
//학과:디지털미디어

#include <iostream>
using namespace std;

int main()
{
	cout << "***<lab2 #1>***" << endl;
	cout << endl;

	short s1 = SHRT_MAX;//short의 최댓값을 s1에 대입
	short s2 = SHRT_MIN;//short의 최솟값을 s1에 대입

	cout << "s1 = "<< s1 << endl; //short의 최댓값을 출력
	s1 = s1 + 1;//오버플로우 발생
	cout << "s1 + 1 = " << s1 << endl; //오버플로우 값을 출력
	cout << endl;
	cout << "s2 = " << s2 << endl; //short의 최솟값을 출력
	s2 = s2 - 1;//언더플로우 발생
	cout << "s2 - 1 = " << s2 << endl; //언더플로우 값을 출력
	cout << endl;

	cout << "***<lab2 #2>***" << endl;
	cout << endl;
	
	unsigned int u1 = 2; //2를 u1에 대입
	unsigned int u2 = -1;//-1를 u2에 대입

	cout << "u1 = " << u1 << endl;
	cout << "u2 = " << u2 << endl;//언더플로우 값을 출력
	cout << endl;

	cout << "***<lab2 #3>***" << endl;
	cout << endl;

	int person1 = 10;//10을 person1에 대입
	int person2 = 20;//20을 person2에 대입
	int person3 = 30;//30을 person3에 대입
	int person4 = 40;//40을 person4에 대입
	int person5 = 50;//50을 person5에 대입
	cout << "person1 = " << person1 << endl;//person1 값을 출력
	cout << "person2 = " << person2 << endl;//person2 값을 출력
	cout << "person3 = " << person3 << endl;//person3 값을 출력
	cout << "person4 = " << person4 << endl;//person4 값을 출력
	cout << "person5 = " << person5 << endl;//person5 값을 출력
	cout << endl;

	cout << "정수상수(literal) 사용" << endl;
	cout << "person1 = " << person1 + 30 << endl;//person1에 30을 더한 값을 출력
	cout << "person2 = " << person2 + 30 << endl;//person2에 30을 더한 값을 출력
	cout << "person3 = " << person3 + 30 << endl;//person3에 30을 더한 값을 출력
	cout << "person4 = " << person4 + 30 << endl;//person4에 30을 더한 값을 출력
	cout << "person5 = " << person5 + 30 << endl;//person5에 30을 더한 값을 출력
	cout << endl;

	cout << "기호상수(#define) 사용" << endl;
	#define ADD30 30 //기호상수 선언
	cout << "person1 = " << person1 + ADD30 << endl;//person1에 기호상수를 더한 값을 출력
	cout << "person2 = " << person2 + ADD30 << endl;//person2에 기호상수를 더한 값을 출력
	cout << "person3 = " << person3 + ADD30 << endl;//person3에 기호상수를 더한 값을 출력
	cout << "person4 = " << person4 + ADD30 << endl;//person4에 기호상수를 더한 값을 출력
	cout << "person5 = " << person5 + ADD30 << endl;//person5에 기호상수를 더한 값을 출력
	cout << endl;

	cout << "기호상수(const) 사용" << endl;
	const int ADD = 30;//기호상수 선언
	cout << "person1 = " << person1 + ADD << endl;//person1에 기호상수를 더한 값을 출력
	cout << "person2 = " << person2 + ADD << endl;//person2에 기호상수를 더한 값을 출력
	cout << "person3 = " << person3 + ADD << endl;//person3에 기호상수를 더한 값을 출력
	cout << "person4 = " << person4 + ADD << endl;//person4에 기호상수를 더한 값을 출력
	cout << "person5 = " << person5 + ADD << endl;//person5에 기호상수를 더한 값을 출력
	cout << endl;




	return 0;
}