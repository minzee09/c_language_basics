/*
lab10.cpp

lab10 �ǽ� ���α׷�
#1 ���� �迭���� �ִ�, �ּҰ� ���ϱ� (4�� 3��)
#2 ����(0 ~ 9) �߻� ��Ű��, ������ ���� �󵵼� ���� (5��3��)
#3 �� ����� �� ���ϱ�
#4 �� ����� �� ���ϱ�

�й�: 2020111242
�̸�: �����
�й�: 02(��56����)
*/

#include <iostream>
#include <iomanip>

using namespace std;

//�Լ� ����

//#1
void findMinMax(int inumbers[][3], int rowSize);
void print_array(int[][3], int rowSize);

//#2
void randomNumbers(int inumbers[][3], int rowSize);
void randomCounts(int inumbers[][3], int size, int counts[]);

//#3
void addMatrix(int a[][3], int b[][3], int c[][3], int rowSize);
void multiplyMatrix(int a[][3], int b[][3], int c[][3], int rowSize);

//�������� 
int min, max;

int main()
{
    //#1 ���� �迭���� �ִ�, �ּҰ� ���ϱ� (4�� 3��)
    cout << endl;
    cout << "lab10 #1" << endl;
    cout << endl;

	//�迭 �ʱ�ȭ
    int inumbers[4][3] = {
		{1,2,4},
		{5,10,100},
		{2,-22,22},
		{-123,33,44}
	};

	//�Լ� ����
    print_array(inumbers, 4);
	cout << endl;
	findMinMax(inumbers, 4);
	cout << endl;

	//#2 ����(0 ~ 9) �߻� ��Ű��, ������ ���� �󵵼� ���� (5��3��)
	cout << endl;
	cout << "lab10 #2" << endl;
	cout << endl;

	int random[5][3] = {0};	//������ �����ϱ� ���� �迭
	int num[10] = { 0 };	//���� �󵵼��� �����ϱ� ���� �迭

	//�Լ� ����
	randomNumbers(random,5);
	cout << endl;
	randomCounts(random,5,num);
	cout << endl;

	//#3 �� ����� �� ���ϱ�
	cout << endl;
	cout << "lab10 #3" << endl;
	cout << endl;

	
	int a1, a2, b1, b2;
	int a_value = 1;	//�迭�� 1 ���� 12 ���� ������� �����ϱ� ���� ���� 
	
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
			b[b1][b2] = b2 + 1;	//�迭�� �ึ�� ���� ���� �����ϱ� ����
		}
	}

	//�迭 ���
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

	//�Լ� ����
	int ab[4][3] = { 0 };
	cout << "==================" << endl;
	addMatrix(a, b, ab, 4);
	cout << "==================" << endl;

	//#4 �� ����� �� ���ϱ�
	cout << endl;
	cout << "lab10 #4" << endl;
	cout << endl;
	
	int c1, c2, d1, d2;

	//�迭 �ʱ�ȭ
	 int c[3][3] = {
		{4,3,1},
		{2,3,3},
		{4,1,1}
	};
	 //�迭 �ʱ�ȭ
	 int d[3][3] = {
		{3,8,7},
		{4,2,7},
		{7,9,3}
	 };
	 //�迭 ���
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

	 //�Լ� ����
	 int cd[3][3] = { 0 };
	 cout << "==================" << endl;
	 multiplyMatrix(c, d, cd, 3);
	 cout << "==================" << endl;

    return 0;
}

//�Լ�

//#1
void print_array(int x[][3], int rowSize)
{
    cout << "==================" << endl;
	//�迭�� rowSize��, 3������ ���
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
	max = inumbers[0][0];//max�� �ʱⰪ�� ����

	//inumbers[0][0] ~ [rowSize][3]���� �� ��
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 3; j++)
			//�ִ밪 �Ǵ�
			if (inumbers[i][j] > max)
				max = inumbers[i][j];
	}

	min = inumbers[0][0];//mix�� �ʱⰪ�� ����

	//inumbers[0][0] ~ [rowSize][3]���� �� ��
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < 3; j++)
			//�ּҰ� �Ǵ�
			if (inumbers[i][j] < min)
				min = inumbers[i][j];
	}
	//�ִ�,�ּ� ���
	cout << "�ּҰ�: " << min << ", �ִ밪: " << max << endl;

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
			//0 ~ 9 ������ ���ڸ� �������� �ʱ�ȭ
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

	cout << "����: ";
	for (i = 0; i < 10; i++)
		cout << setw(5) << i;
	cout << endl;

	//���� �󵵼� ��� �� ����
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 3; j++)
			counts[inumbers[i][j]]++;
	}

	//���� �󵵼� ���
	cout << "����: ";
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
	//�� �迭�� ���� ���� ���� 
	for (i = 0; i < rowSize; i++)
	{
		for (j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
	}
	//�� �迭�� ���� ���� ��� 
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
	//�迭 a[rowSize][3]�� b[rowSize][3]�� ���� ���� ����
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < rowSize; j++)
		{	
			for (k = 0; k < 3; k++)
				c[i][j] += a[i][k] * b[k][j];	//�迭 a�� �� ���� �迭 b�� �� ���� ���ϰ� �������� ���ؼ� ����
		}
	}

	//������ �迭�� ���
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j <rowSize; j++)
			cout << setw(5) << c[i][j];
		cout << endl;
	}
}

