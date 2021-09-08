/*
lab9.cpp

lab9 �ǽ� ���α׷�
#1 ��� �� 80 �̻��� ���� ���ϱ�
   -���Ͽ��� �����͸� �о� ���� �迭�� �����Ѵ�.
   -�迭�� lab9.exe�� ���� �������� ����Ѵ�.
   -��հ��� ����Ѵ�.
   -80 �̻��� ������ ����Ѵ�.
#2 �迭�� �������� �����
   (�迭 �ʱ�ȭ ���)
#3 10 ���� ������ ����(0 ~ 9) �߻� ��Ű��, ������ ���� �󵵼� ����
   -���� �߻� �� �� ���
   -�ִ� �� Ƚ�����

�й�: 2020111242
�̸�: �����
�й�: 02(��56����)
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

//�Լ� ����

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
	cout << "�ǽ�9 #1:" << endl;
	cout << endl;
	
	const int NUM = 50;
	int mid[NUM];

	ifstream input;		// �����Է�
	input.open("data.txt");	//"data.txt" ����

	//�������� ������ �˰� �ִ� ���
	for (int i = 0; i < NUM; i++)	//���Ͽ��� �����͸� �о� ���� �迭(int mid[])�� �����Ѵ�.
		input >> mid[i];

	//�Լ� ȣ��
	printArray(mid, 50);	//�迭 ���
	over80(mid, 50);		//80�� �̻��� ������ ���
	average(mid, 50);		//�� ����� ���

	getchar();
	cout << endl;

	//#2
	cout << "�ǽ�9 #2 �迭 �������� �����" << endl;
	cout << endl;

	const int SIZE = 8;
	int inumbers[SIZE] = { 1,3,5,7,2,4,6,8 };

	//���� �迭 ���
	cout << "���� �迭:	";
	for (int i = 0; i < SIZE; i++)
		cout << inumbers[i] << "  ";
	cout << endl;
	
	//�Լ� ȣ��
	reverse(inumbers, SIZE);	//���� �迭 ���

	getchar();
	cout << endl;

	//#3
	cout << "�ǽ�9 #3 �����߻� ��Ű��, ������ ���� �󵵼� ����" << endl;
	cout << endl;

	int num[10] = { 0 };

	//�Լ� ȣ��
	randomCounts(num,10);	//���� �߻� �� �󵵼� ���
	findMax(num, 10);		//�ִ� �� Ƚ�� ���

	cout << endl;
	system("pause");

	return 0;
}

// #1 �Լ�
void printArray(int x[], int size)
{
	cout << "�迭 mid" << endl;
	cout << "================" << endl;
	cout << "�ε���	��" << endl;
	cout << "================" << endl;
	//�迭 ���
	for (int i = 0; i < size; i++)
		cout << setw(2) << i << "	" << setw(2) << x[i] << endl;
	cout << "================" << endl;
	cout << endl;
}
double average(int x[], int size)
{
	//�迭 x�� ������ ���(��/����) ���
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += x[i];
	cout << "�߰���� ������ ����� " << sum / size << "�� �Դϴ�." << endl;

	return (sum/size);
}

int over80(int x[], int size)
{
	//�迭 x�� ���Ұ� 80 �̻��̸� ���
	int count = 0;
	for (int i = 0; i < size; i++)
		if (x[i] >= 80)
			count++;
	cout << "�߰���� ���� �� 80�� �̻��� " << count << "�� �Դϴ�." << endl;

	return count;
}

//#2 �Լ�
void reverse(int x[], int size)
{
	int t;
	int left = 0;			//���ʿ��� ù��° �׸��� ��ġ
	int right = size - 1;	//�����ʿ��� ù��° �׸��� ��ġ 

	for (int i = 0; i < size / 2; i++)	//�ٲ�� Ƚ���� �迭 �׸��� ���ݸ�ŭ
	{
		//�迭�� ���ʰ� �������� ���� ��ȯ
		t = x[left];
		x[left] = x[right];
		x[right] = t;
		left++;
		right--;
	}
	cout << "���� �迭:	";
	for (int i = 0; i < size; i++)
		cout << x[i] << "  ";
	cout << endl;

}

//#3 �Լ�
void randomCounts(int count[], int size)
{
	int i;
	//���� �߻�
	srand((unsigned)time(NULL));
	for (i = 0; i < 100; i++)
		count[rand() % 10]++;	//0 ~ 9 ������ ������ �߻����� �ش� �迭�� ����
	
	//���� �󵵼� ���
	cout << "���� ��: ";
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
		//�迭�� ũ�� ��
		if (count[i] > max) 
		{
			max = count[i];
			t = i;
		}
	}
	cout << "���� ���� ������ ������ " << t << "�̸� Ƚ���� " << count[t] << "�� �Դϴ�." << endl;

	return t;
}