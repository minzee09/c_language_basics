/*
lab11.cpp

lab11 실습 프로그램
#1 lab9을 배열대신 포인터로 구현하기
#2 정렬된 두 배열 a[ ], b[ ] 를 하나로 병합하기
   (programming exercise #10 p295)


학번: 2020111242
이름: 김민지
분반: 02(목56교시)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale.h>
#include <time.h>

using namespace std;

#define ARRAY_SIZE(a) (sizeof (a) / sizeof (a[0]))
//실습 #1
// 함수원형 #1
void print_array(int*, int size);	// 배열을 출력
double average(int*, int size);		// 배열의 평균
int over80(int*, int size);			// 80 이상의 갯수
int findMax(int*, int size);		// 최고값 
int findMin(int*, int size);		// 최저값

// 함수원형 #2
void reverse(int* inumbers, int size);

// 함수원형 #3
void randomNumbers(int* inumbers, int size);
void randomCounts(int* inumbers, int size, int* counts);

//실습 #2
//함수원형
void merge(int* a, int* b, int* c, int size);



int main()
{

	ifstream infile;	// 입력파일스트림

	int mid[50];

	infile.open("data.txt");
	if (!infile)
	{
		cout << "파일을 열수 없습니다.";
		exit(1);
	}

	// 파일에서 중간고사 점수 읽어 배열 mid[]에 저장하기
	int count=0;
	while(!infile.eof())
		infile >> mid[count++];
	infile.close();

	cout << endl;
	cout << "실습11 #1-1: " << endl;

	cout << endl;
	cout << "배열 mid " << endl;
//	print_array(mid, count);
	print_array(mid, ARRAY_SIZE(mid));

	cout << "중간고사 성적 중 80점 이상은 " << over80(mid, count) << "명 입니다." << endl;
	cout << "중간고사 성적의 평균은 " << average(mid, count) << "점 입니다." << endl;
	cout << "중간고사 성적의 최고점수는 " << findMax(mid, count) << "점 입니다." << endl;
	cout << "중간고사 성적의 최저점수는 " << findMin(mid, count) << "점 입니다." << endl;

	getchar();

	cout << endl;
	cout << "실습11 #1-2 배열 역순으로 만들기" << endl;

	int inumbers1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	cout << "원본 배열: " << endl;
//	print_array(inumbers1, 8);
	print_array(inumbers1, ARRAY_SIZE(inumbers1));

	cout << endl;

//	reverse(inumbers1, 8);
	reverse(inumbers1, ARRAY_SIZE(inumbers1));

	cout << "역순 배열: " << endl;
//	print_array(inumbers1, 8);
	print_array(inumbers1, ARRAY_SIZE(inumbers1));
	cout << endl;


	getchar();

	cout << endl;
	cout << "실습11 #1-3 난수발생 시키기, 숫자의 출현 빈도수 세기" << endl;

//	const int size = 10;
	int counts[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };    // 숫자 별 개수
	int inumbers2[10];

	srand((unsigned)time(NULL));

//	randomNumbers(inumbers2, size);			// 난수로 배열 초기화
//	randomCounts(inumbers2, size, counts);	// 숫자 별 개수 계산

	randomNumbers(inumbers2, ARRAY_SIZE(inumbers2));			// 난수로 배열 초기화
	randomCounts(inumbers2, ARRAY_SIZE(inumbers2), counts);		// 숫자 별 개수 계산

	// 난수 배열 출력
	cout << "난수 배열: " << endl;
//	print_array(inumbers2, size);
	print_array(inumbers2, ARRAY_SIZE(inumbers2));
	cout << endl;

	// 난수 출현 빈도 출력
	cout << "난수 출현빈도: " << endl;
	print_array(counts, ARRAY_SIZE(counts));
	cout << endl;

	getchar();

	cout << endl << endl;
	cout << "실습11 #2 정렬된 두 배열을 하나로 병합하기(A + B => C)" << endl << endl;

	// 실습 #2 

	int a[5] = { 1, 3, 4, 7, 8 };
	int b[5] = { 2, 5, 6, 9, 10 };
	int c[10] = { 0 };


	cout << "배열 A" << endl;
	//print_array(a, 5);
	print_array(a, ARRAY_SIZE(a));	//a 배열 출력
	cout << "배열 B" << endl;
	//print_array(b, 5);
	print_array(b, ARRAY_SIZE(b));	//b 배열 출력
	cout << "배열 C" << endl;
	merge(a, b, c, ARRAY_SIZE(c));	//하나로 합치기
	print_array(c, ARRAY_SIZE(c));	//c 배열 출력
	
	

	system("pause");
	return 0;
}

// 배열을 출력하는 함수정의
void print_array(int* a, int size)
{
	cout << "=================\n";
	cout << "인덱스     값    \n";
	cout << "=================\n";
	for(int i = 0; i < size; i++)
		cout << setw(3) << i << '\t' << setw(5) << *(a + i) << endl;
		//cout << setw(3) << i << '\t' << setw(5) << a[i] << endl;
	cout << "=================\n";
	cout << endl;
}

// 80 이상의 갯수
int over80(int* a, int size)
{
	int count = 0;
	for(int i = 0; i < size; i++)
		if (*(a + i) >= 80)		//a[i] >= 80
			count++;
	return count;
}

// 배열의 평균 계산
double average(int* a, int size)
{ 
	int sum = 0; 
	for(int i = 0; i < size; i++) 
		sum += *(a + i);		//sum += a[i];
	return (double)sum / size; 
}

// 최고값
int findMax(int* a, int size)
{
	int max=0; 
	for(int i = 0; i < size; i++) 
		if (max < *(a + i))		//max < a[i]
			max = *(a + i);		//max = a[i];
	return max;
}
	
// 최저값
int findMin(int* a, int size)
{
	int min=100; 
	for (int i = 0; i < size; i++)
		if (min > * (a + i))	//(min > a[i])
			min = *(a + i);		//min = a[i];
	return min;
}

// 배열을 매개변수로 전달받아 역순으로 만든다
// 0<->n-1, 1<->n-2, 2<->n-3,. . .
void reverse(int* inumbers, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = *(inumbers + i);
		*(inumbers + i) = *(inumbers + size - 1 - i);	//inumbers[size - 1 - i];
		*(inumbers + size - 1 - i) = temp;				//inumbers[size - 1 - i] = temp;
	}
}

// 난수로 배열 초기화 
void randomNumbers(int* inumbers, int size)
{
	for (int i = 0; i < size; i++)
		*(inumbers+i) = rand() % 10;	//inumbers[i] = rand() % 10;
}

// 숫자 별 개수 계산
void randomCounts(int* inumbers, int size, int* counts)
{
	for (int i = 0; i < size; i++)
	{
		(*(counts + *(inumbers + i)))++;
			//counts[inumbers[i]] ++;

	}
}

//하나로 병합하기
void merge(int* a, int* b, int* c, int size)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (k = 0; k < size; k++)
	{
		if (i >= size / 2)				//더 이상 비교하지 않고 b의 원소 가져오기
		{
			*(c + k) = *(b + j);
			j++;
		}
		else if (j >= size / 2)			//더 이상 비교하지 않고 a의 원소 가져오기
		{
			*(c + k) = *(a + i);
			i++;
		}
		else if (*(a + i) < *(b + j))	//a,b 중 더 작은 원소 출력하기
		{
			*(c + k) = *(a + i);
			i++;
		}
		else if (*(a + i) > * (b + j))	//a,b 중 더 작은 원소 출력하기
		{
			*(c + k) = *(b + j);
			j++;
		}
	}
}


