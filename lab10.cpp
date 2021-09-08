/*
lab10.cpp

lab10 실습 프로그램
#1 정수 배열에서 최대, 최소값 구하기 (4행 3열)
#2 난수(0 ~ 9) 발생 시키기, 숫자의 출현 빈도수 세기 (5행3열)
#3 두 행렬의 합 구하기
#4 두 행렬의 곱 구하기

학번: 2020111242
이름: 김민지
분반: 02(목56교시)
*/

#include <iostream>
#include <iomanip>

using namespace std;

//함수 원형

//#1
void findMinMax(int inumbers[][3], int rowSize);
void print_array(int[][3], int rowSize);

//#2
void randomNumbers(int inumbers[][3], int rowSize);
void randomCounts(int inumbers[][3], int size, int counts[]);

//#3
void addMatrix(int a[][3], int b[][3], int c[][3], int rowSize);
void multiplyMatrix(int a[][3], int b[][3], int c[][3], int rowSize);

//전역변수 
int min, max;

int main()
{
    //#1 정수 배열에서 최대, 최소값 구하기 (4행 3열)
    cout << endl;
    cout << "lab10 #1" << endl;
    cout << endl;

	//배열 초기화
    int inumbers[4][3] = {
		{1,2,4},
		{5,10,100},
		{2,-22,22},
		{-123,33,44}
	};

	//함수 선언
    print_array(inumbers, 4);
	cout << endl;
	findMinMax(inumbers, 4);
	cout << endl;

	//#2 난수(0 ~ 9) 발생 시키기, 숫자의 출현 빈도수 세기 (5행3열)
	cout << endl;
	cout << "lab10 #2" << endl;
	cout << endl;

	int random[5][3] = {0};	//난수를 저장하기 위한 배열
	int num[10] = { 0 };	//난수 빈도수를 저장하기 위한 배열

	//함수 선언
	randomNumbers(random,5);
	cout << endl;
	randomCounts(random,5,num);
	cout << endl;

	//#3 두 행렬의 합 구하기
	cout << endl;
	cout << "lab10 #3" << endl;
	cout << endl;

	
	int a1, a2, b1, b2;
	int a_value = 1;	//배열을 1 부터 12 까지 순서대로 저장하기 위한 변수 
	
	int a[4][3];
	for (a1 = 0; a1 < 4; a1++)
	{
		for (a2 = 0; a2 < 3; a2++)
			a[a1][a2] = a_value++;
	}

	int b[4][3];
	for (b1 = 0; b1 < 4; b1++)
	{
		for (b2 = 0; b2 < 3; b2++)
		{
			b[b1][b2] = b2 + 1;	//배열이 행마다 같은 열을 저장하기 위해
		}
	}

	//배열 출력
	cout << "==================" << endl;
	for (a1 = 0; a1 < 4; a1++)
	{
		for (a2 = 0; a2 < 3; a2++)
			cout << setw(5) << a[a1][a2];
		cout << endl;
	}
	cout << "==================" << endl;
	cout << endl;
	cout << setw(10) << "+" << endl;
	cout << endl;
	cout << "==================" << endl;
	for (b1 = 0; b1 < 4; b1++)
	{
		for (b2 = 0; b2 < 3; b2++)
			cout << setw(5) << b[b1][b2];
		cout << endl;
	}
	cout << "==================" << endl;
	cout << endl;
	cout << setw(10) << "=" << endl;
	cout << endl;

	//함수 선언
	int ab[4][3] = { 0 };
	cout << "==================" << endl;
	addMatrix(a, b, ab, 4);
	cout << "==================" << endl;

	//#4 두 행렬의 곱 구하기
	cout << endl;
	cout << "lab10 #4" << endl;
	cout << endl;
	
	int c1, c2, d1, d2;

	//배열 초기화
	 int c[3][3] = {
		{4,3,1},
		{2,3,3},
		{4,1,1}
	};
	 //배열 초기화
	 int d[3][3] = {
		{3,8,7},
		{4,2,7},
		{7,9,3}
	 };
	 //배열 출력
	 cout << "==================" << endl;
	 for (c1 = 0; c1 < 3; c1++)
	 {
		 for (c2 = 0; c2 < 3; c2++)
			 cout << setw(5) << c[c1][c2];
		 cout << endl;
	 }
	 cout << "==================" << endl;
	 cout << endl;
	 cout << setw(10) << "x" << endl;
	 cout << endl;
	 cout << "==================" << endl;
	 for (d1 = 0; d1 < 3 ; d1++)
	 {
		 for (d2 = 0; d2 < 3; d2++)
			 cout << setw(5) << d[d1][d2];
		 cout << endl;
	 }
	 cout << "==================" << endl;
	 cout << endl;
	 cout << setw(10) << "=" << endl;
	 cout << endl;

	 //함수 선언
	 int cd[3][3] = { 0 };
	 cout << "==================" << endl;
	 multiplyMatrix(c, d, cd, 3);
	 cout << "==================" << endl;

    return 0;
}

//함수

//#1
void print_array(int x[][3], int rowSize)
{
    cout << "==================" << endl;
	//배열을 rowSize행, 3열으로 출력
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << setw(5) << x[i][j];
		cout << endl;
	}
	cout << "==================" << endl;

}

void findMinMax(int inumbers[][3], int rowSize)
{
	max = inumbers[0][0];//max의 초기값을 지정

	//inumbers[0][0] ~ [rowSize][3]까지 값 비교
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 3; j++)
			//최대값 판단
			if (inumbers[i][j] > max)
				max = inumbers[i][j];
	}

	min = inumbers[0][0];//mix의 초기값을 지정

	//inumbers[0][0] ~ [rowSize][3]까지 값 비교
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 3; j++)
			//최소값 판단
			if (inumbers[i][j] < min)
				min = inumbers[i][j];
	}
	//최대,최소 출력
	cout << "최소값: " << min << ", 최대값: " << max << endl;

}

//#2
void randomNumbers(int inumbers[][3], int rowSize)
{
	srand((unsigned int)time(NULL));

	cout << "==================" << endl;
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//0 ~ 9 까지의 숫자를 랜덤으로 초기화
			inumbers[i][j] = rand() % 10;
			cout << setw(5) << inumbers[i][j];
		}
		cout << endl;
	}
	cout << "==================" << endl;
	
}
void randomCounts(int inumbers[][3], int size, int counts[])
{
	
	int i,j;

	cout << "난수: ";
	for (i = 0; i < 10; i++)
		cout << setw(5) << i;
	cout << endl;

	//난수 빈도수 계산 및 저장
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 3; j++)
			counts[inumbers[i][j]]++;
	}

	//난수 빈도수 출력
	cout << "개수: ";
	for (i = 0; i < 10; i++)
	{
		cout << setw(5) << counts[i];
	}
	cout << endl;

}

//#3
void addMatrix(int a[][3], int b[][3], int c[][3], int rowSize)
{
	int i, j;
	//두 배열의 더한 값을 저장 
	for (i = 0; i < rowSize; i++)
	{
		for (j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
	}
	//두 배열의 더한 값을 출력 
	for (i = 0; i < rowSize; i++)
	{
		for (j = 0; j < 3; j++)
			cout << setw(5) << c[i][j];
		cout << endl;
	}
	
}
void multiplyMatrix(int a[][3], int b[][3], int c[][3], int rowSize)
{
	int i, j, k;
	//배열 a[rowSize][3]랑 b[rowSize][3]의 곱한 값을 저장
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < rowSize; j++)
		{	
			for (k = 0; k < 3; k++)
				c[i][j] += a[i][k] * b[k][j];	//배열 a의 한 열과 배열 b의 한 행을 곱하고 마지막에 더해서 저장
		}
	}

	//곱해진 배열을 출력
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j <rowSize; j++)
			cout << setw(5) << c[i][j];
		cout << endl;
	}
}

