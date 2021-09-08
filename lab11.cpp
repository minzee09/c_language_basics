/*
lab11.cpp

lab11 �ǽ� ���α׷�
#1 lab9�� �迭��� �����ͷ� �����ϱ�
#2 ���ĵ� �� �迭 a[ ], b[ ] �� �ϳ��� �����ϱ�
   (programming exercise #10 p295)


�й�: 2020111242
�̸�: �����
�й�: 02(��56����)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale.h>
#include <time.h>

using namespace std;

#define ARRAY_SIZE(a) (sizeof (a) / sizeof (a[0]))
//�ǽ� #1
// �Լ����� #1
void print_array(int*, int size);	// �迭�� ���
double average(int*, int size);		// �迭�� ���
int over80(int*, int size);			// 80 �̻��� ����
int findMax(int*, int size);		// �ְ� 
int findMin(int*, int size);		// ������

// �Լ����� #2
void reverse(int* inumbers, int size);

// �Լ����� #3
void randomNumbers(int* inumbers, int size);
void randomCounts(int* inumbers, int size, int* counts);

//�ǽ� #2
//�Լ�����
void merge(int* a, int* b, int* c, int size);



int main()
{

	ifstream infile;	// �Է����Ͻ�Ʈ��

	int mid[50];

	infile.open("data.txt");
	if (!infile)
	{
		cout << "������ ���� �����ϴ�.";
		exit(1);
	}

	// ���Ͽ��� �߰���� ���� �о� �迭 mid[]�� �����ϱ�
	int count=0;
	while(!infile.eof())
		infile >> mid[count++];
	infile.close();

	cout << endl;
	cout << "�ǽ�11 #1-1: " << endl;

	cout << endl;
	cout << "�迭 mid " << endl;
//	print_array(mid, count);
	print_array(mid, ARRAY_SIZE(mid));

	cout << "�߰���� ���� �� 80�� �̻��� " << over80(mid, count) << "�� �Դϴ�." << endl;
	cout << "�߰���� ������ ����� " << average(mid, count) << "�� �Դϴ�." << endl;
	cout << "�߰���� ������ �ְ������� " << findMax(mid, count) << "�� �Դϴ�." << endl;
	cout << "�߰���� ������ ���������� " << findMin(mid, count) << "�� �Դϴ�." << endl;

	getchar();

	cout << endl;
	cout << "�ǽ�11 #1-2 �迭 �������� �����" << endl;

	int inumbers1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	cout << "���� �迭: " << endl;
//	print_array(inumbers1, 8);
	print_array(inumbers1, ARRAY_SIZE(inumbers1));

	cout << endl;

//	reverse(inumbers1, 8);
	reverse(inumbers1, ARRAY_SIZE(inumbers1));

	cout << "���� �迭: " << endl;
//	print_array(inumbers1, 8);
	print_array(inumbers1, ARRAY_SIZE(inumbers1));
	cout << endl;


	getchar();

	cout << endl;
	cout << "�ǽ�11 #1-3 �����߻� ��Ű��, ������ ���� �󵵼� ����" << endl;

//	const int size = 10;
	int counts[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };    // ���� �� ����
	int inumbers2[10];

	srand((unsigned)time(NULL));

//	randomNumbers(inumbers2, size);			// ������ �迭 �ʱ�ȭ
//	randomCounts(inumbers2, size, counts);	// ���� �� ���� ���

	randomNumbers(inumbers2, ARRAY_SIZE(inumbers2));			// ������ �迭 �ʱ�ȭ
	randomCounts(inumbers2, ARRAY_SIZE(inumbers2), counts);		// ���� �� ���� ���

	// ���� �迭 ���
	cout << "���� �迭: " << endl;
//	print_array(inumbers2, size);
	print_array(inumbers2, ARRAY_SIZE(inumbers2));
	cout << endl;

	// ���� ���� �� ���
	cout << "���� ������: " << endl;
	print_array(counts, ARRAY_SIZE(counts));
	cout << endl;

	getchar();

	cout << endl << endl;
	cout << "�ǽ�11 #2 ���ĵ� �� �迭�� �ϳ��� �����ϱ�(A + B => C)" << endl << endl;

	// �ǽ� #2 

	int a[5] = { 1, 3, 4, 7, 8 };
	int b[5] = { 2, 5, 6, 9, 10 };
	int c[10] = { 0 };


	cout << "�迭 A" << endl;
	//print_array(a, 5);
	print_array(a, ARRAY_SIZE(a));	//a �迭 ���
	cout << "�迭 B" << endl;
	//print_array(b, 5);
	print_array(b, ARRAY_SIZE(b));	//b �迭 ���
	cout << "�迭 C" << endl;
	merge(a, b, c, ARRAY_SIZE(c));	//�ϳ��� ��ġ��
	print_array(c, ARRAY_SIZE(c));	//c �迭 ���
	
	

	system("pause");
	return 0;
}

// �迭�� ����ϴ� �Լ�����
void print_array(int* a, int size)
{
	cout << "=================\n";
	cout << "�ε���     ��    \n";
	cout << "=================\n";
	for(int i = 0; i < size; i++)
		cout << setw(3) << i << '\t' << setw(5) << *(a + i) << endl;
		//cout << setw(3) << i << '\t' << setw(5) << a[i] << endl;
	cout << "=================\n";
	cout << endl;
}

// 80 �̻��� ����
int over80(int* a, int size)
{
	int count = 0;
	for(int i = 0; i < size; i++)
		if (*(a + i) >= 80)		//a[i] >= 80
			count++;
	return count;
}

// �迭�� ��� ���
double average(int* a, int size)
{ 
	int sum = 0; 
	for(int i = 0; i < size; i++) 
		sum += *(a + i);		//sum += a[i];
	return (double)sum / size; 
}

// �ְ�
int findMax(int* a, int size)
{
	int max=0; 
	for(int i = 0; i < size; i++) 
		if (max < *(a + i))		//max < a[i]
			max = *(a + i);		//max = a[i];
	return max;
}
	
// ������
int findMin(int* a, int size)
{
	int min=100; 
	for (int i = 0; i < size; i++)
		if (min > * (a + i))	//(min > a[i])
			min = *(a + i);		//min = a[i];
	return min;
}

// �迭�� �Ű������� ���޹޾� �������� �����
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

// ������ �迭 �ʱ�ȭ 
void randomNumbers(int* inumbers, int size)
{
	for (int i = 0; i < size; i++)
		*(inumbers+i) = rand() % 10;	//inumbers[i] = rand() % 10;
}

// ���� �� ���� ���
void randomCounts(int* inumbers, int size, int* counts)
{
	for (int i = 0; i < size; i++)
	{
		(*(counts + *(inumbers + i)))++;
			//counts[inumbers[i]] ++;

	}
}

//�ϳ��� �����ϱ�
void merge(int* a, int* b, int* c, int size)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (k = 0; k < size; k++)
	{
		if (i >= size / 2)				//�� �̻� ������ �ʰ� b�� ���� ��������
		{
			*(c + k) = *(b + j);
			j++;
		}
		else if (j >= size / 2)			//�� �̻� ������ �ʰ� a�� ���� ��������
		{
			*(c + k) = *(a + i);
			i++;
		}
		else if (*(a + i) < *(b + j))	//a,b �� �� ���� ���� ����ϱ�
		{
			*(c + k) = *(a + i);
			i++;
		}
		else if (*(a + i) > * (b + j))	//a,b �� �� ���� ���� ����ϱ�
		{
			*(c + k) = *(b + j);
			j++;
		}
	}
}


