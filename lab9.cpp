/*
lab9.cpp

lab9 실습 프로그램
#1 평균 및 80 이상의 개수 구하기
   -파일에서 데이터를 읽어 정수 배열에 저장한다.
   -배열을 lab9.exe와 같은 형식으로 출력한다.
   -평균값을 계산한다.
   -80 이상의 개수를 계산한다.
#2 배열을 역순으로 만들기
   (배열 초기화 사용)
#3 10 개의 임의의 정수(0 ~ 9) 발생 시키기, 숫자의 출현 빈도수 세기
   -난수 발생 및 빈도 계산
   -최댓값 및 횟수출력

학번: 2020111242
이름: 김민지
분반: 02(목56교시)
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

//함수 원형

//#1
void printArray(int[], int);
double average(int[], int);
int over80(int[], int);

//#2
void reverse(int[], int);

//#3
void randomCounts(int[], int);
int findMax(int[], int);


int main()
{
	//#1
	cout << endl;
	cout << "실습9 #1:" << endl;
	cout << endl;
	
	const int NUM = 50;
	int mid[NUM];

	ifstream input;		// 파일입력
	input.open("data.txt");	//"data.txt" 연결

	//데이터의 개수를 알고 있는 경우
	for (int i = 0; i < NUM; i++)	//파일에서 데이터를 읽어 정수 배열(int mid[])에 저장한다.
		input >> mid[i];

	//함수 호출
	printArray(mid, 50);	//배열 출력
	over80(mid, 50);		//80점 이상인 개수를 출력
	average(mid, 50);		//총 평균을 출력

	getchar();
	cout << endl;

	//#2
	cout << "실습9 #2 배열 역순으로 만들기" << endl;
	cout << endl;

	const int SIZE = 8;
	int inumbers[SIZE] = { 1,3,5,7,2,4,6,8 };

	//원본 배열 출력
	cout << "원본 배열:	";
	for (int i = 0; i < SIZE; i++)
		cout << inumbers[i] << "  ";
	cout << endl;
	
	//함수 호출
	reverse(inumbers, SIZE);	//역순 배열 출력

	getchar();
	cout << endl;

	//#3
	cout << "실습9 #3 난수발생 시키기, 숫자의 출현 빈도수 세기" << endl;
	cout << endl;

	int num[10] = { 0 };

	//함수 호출
	randomCounts(num,10);	//난수 발생 및 빈도수 계산
	findMax(num, 10);		//최댓값 및 횟수 계산

	cout << endl;
	system("pause");

	return 0;
}

// #1 함수
void printArray(int x[], int size)
{
	cout << "배열 mid" << endl;
	cout << "================" << endl;
	cout << "인덱스	값" << endl;
	cout << "================" << endl;
	//배열 출력
	for (int i = 0; i < size; i++)
		cout << setw(2) << i << "	" << setw(2) << x[i] << endl;
	cout << "================" << endl;
	cout << endl;
}
double average(int x[], int size)
{
	//배열 x의 원소의 평균(합/개수) 출력
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += x[i];
	cout << "중간고사 성적의 평균은 " << sum / size << "점 입니다." << endl;

	return (sum/size);
}

int over80(int x[], int size)
{
	//배열 x의 원소가 80 이상이면 출력
	int count = 0;
	for (int i = 0; i < size; i++)
		if (x[i] >= 80)
			count++;
	cout << "중간고사 성적 중 80점 이상은 " << count << "명 입니다." << endl;

	return count;
}

//#2 함수
void reverse(int x[], int size)
{
	int t;
	int left = 0;			//왼쪽에서 첫번째 항목의 위치
	int right = size - 1;	//오른쪽에서 첫번째 항목의 위치 

	for (int i = 0; i < size / 2; i++)	//바뀌는 횟수는 배열 항목의 절반만큼
	{
		//배열의 왼쪽과 오른쪽을 서로 교환
		t = x[left];
		x[left] = x[right];
		x[right] = t;
		left++;
		right--;
	}
	cout << "역순 배열:	";
	for (int i = 0; i < size; i++)
		cout << x[i] << "  ";
	cout << endl;

}

//#3 함수
void randomCounts(int count[], int size)
{
	int i;
	//난수 발생
	srand((unsigned)time(NULL));
	for (i = 0; i < 100; i++)
		count[rand() % 10]++;	//0 ~ 9 사이의 난수를 발생시켜 해당 배열에 저장
	
	//난수 빈도수 출력
	cout << "난수 빈도: ";
	for (i = 0; i < size; i++)
		cout << count[i] << "  ";
	cout << endl;
	
}


int findMax(int count[], int size)
{
	int max = count[0];
	int t = 0;
	for (int i = 1; i < size; i++)
	{
		//배열의 크기 비교
		if (count[i] > max) 
		{
			max = count[i];
			t = i;
		}
	}
	cout << "가장 많이 생성된 난수는 " << t << "이며 횟수는 " << count[t] << "번 입니다." << endl;

	return t;
}