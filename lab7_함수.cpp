/*
lab7_�Լ�.cpp

lab7 �ǽ� ���α׷�(�Լ� ���� ����)
#1 ������ �������(131�� programming #5)
   ��, �ﰢ��, �簢�� �� �����Ͽ� ������ ����Ѵ�
#2 3���� ������ �Է� �޾� �ִ밪�� ����Ѵ�
#3 ���� ��ȯ(��->��, ��->��, ��/��->��/��)
#4 �� ���� �����ڸ� �Է� �޾� ��Ģ ������ ó��(if��, switch��)
#5 1 ~ 100 ������ �Ҽ� ��� (195�� programming #2)

�й�: 2020111242
�̸�: �����
�й�: 02(��56����)
*/


#include <iostream>
using namespace std;

//#1 �Լ� - �簢���� ���� ���ϱ�
double square_area(double w, double h)
{
	return (w*h);
}
//#1 �Լ� - ���� ���� ���ϱ�
double circle_area(double r)
{
	return((r * r) * 3.14);
}


//#2 �Լ� - �ִ밪 ã��
int findMax(int n1, int n2, int n3)
{
	int max = 0;	//�ִ밪

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
//#2 �Լ� - �ּҰ� ã��
int findMin(int n1, int n2, int n3)
{
	int min = 0;	//�ּҰ�

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

//#3 �Լ� - �ҹ���->�빮��
char convertDownUp(char ch)
{
	return (ch - 32);
}
//#3 �Լ� - �빮��->�ҹ���
char convertUpDown(char ch)
{
	return (ch + 32);
}

//#4 �Լ� - ��Ģ����(if)
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
//#4 �Լ� - ��Ģ����(switch)
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

//#5 �Լ� - �Ҽ� ã��
int isPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)			// 2 ~ n-1 ���� �ݺ� 
	{
		if (n % i == 0)				// 1�� �ڱ� �ڽ��� �ƴ� �ٸ� ���� ������ �������� �Ҽ��� �ƴϴ�.
			return 0;
	}
	return 1;
}

//*****************************< lab7 #1 >**********************************
// #1 ��, �ﰢ��, �簢�� �� �����Ͽ� ������ ����Ѵ�
//**************************************************************************

int main()
{
	// ��������

	// #1
	double width, height, radius;// �غ�, ����, ������
	char choice, yn;			 // �������� 

	// #2
	int n1, n2, n3;				 // �� ���� 

	// #3
	char ch;					// �Է¹���

	// #4
	double v1, v2;				// �ǿ�����,
	char op;					// ������ 
	bool ok = true;				// ������ ��ȿ��

	// #5
	int num;					 // �Ҽ�?

	//*****************************< lab7 #1 >**********************************
	// #1 ��, �ﰢ��, �簢�� �� �����Ͽ� ������ ���
	//**************************************************************************

	cout << endl;
	cout << "lab7 #1" << endl << endl;

	do
	{
		// �޴� ������ ��������
		cout << endl;
		cout << "�ﰢ��: t" << endl;
		cout << "�簢��: r" << endl;
		cout << "��:     c" << endl;
		cout << "----------" << endl;
		cout << "������ ������ �Է��ϼ���:";
		cin >> choice;

		if (choice == 'r' || choice == 'R')
		{
			cout << "�غ��� �Է��ϼ��� :";
			cin >> width;
			cout << "���̸� �Է��ϼ��� :";
			cin >> height;
			cout << "�簢���� ������ : " << square_area(width, height) << "�Դϴ�." << endl;
		}
		else if (choice == 't' || choice == 'T')
		{
			cout << "�غ��� �Է��ϼ��� :";
			cin >> width;
			cout << "���̸� �Է��ϼ��� :";
			cin >> height;
			cout << "�ﰢ���� ������ : " << square_area(width, height) / 2.0 << "�Դϴ�." << endl;
		}
		else if (choice == 'c' || choice == 'C')
		{
			cout << "�������� �Է��ϼ��� :";
			cin >> radius;
			cout << "���� ������ : " << circle_area(radius) << "�Դϴ�." << endl;
		}
		else
			cout << "�߸��� �����Դϴ�." << endl;


		cout << endl;
		cout << "����Ͻðڽ��ϱ�? [y/n] : ";
		cin >> yn;

		// ȭ�� �����
		system("cls");

	} while (yn == 'Y' || yn == 'y');


	//*****************************< lab7 #2 >**********************************
	// #2 3���� ������ �Է� �޾� �ִ�, �ּҰ� ���
	//**************************************************************************

	cout << endl << endl;
	cout << "lab7 #2" << endl << endl;
	do
	{
		cout << endl;
		cout << "�� ������ �������� �и��Ͽ� �Է��ϼ��� : ";
		cin >> n1 >> n2 >> n3;

		// �ִ밪
		cout << "���� ū ���� " << findMax(n1, n2, n3) << "�Դϴ�." << endl;

		// �ּҰ�
		cout << "���� ���� ���� " << findMin(n1, n2, n3) << "�Դϴ�." << endl << endl;

		cout << "����Ͻðڽ��ϱ�? [y/n] : ";
		cin >> yn;

	} while (yn == 'Y' || yn == 'y');

	// ȭ�� �����
	system("cls");

	//*****************************< lab7 #3 >**********************************
	// #3 ���� ��ȯ(��->��, ��->��, ��/��->��/��)
	//**************************************************************************

	cout << endl;
	cout << "lab7 #3" << endl << endl;

	do {
		cout << endl;
		cout << "#3-1: �ҹ��� -> �빮�� ��ȯ" << endl;
		cout << "�ҹ��ڸ� �Է��ϼ���. : ";
		cin >> ch;
		if ((ch >= 'a') && (ch <= 'z'))
		{
			cout << "�ҹ��� : " << ch << " => �빮�� : " << convertDownUp(ch) << endl << endl;
		}
		else
			cout << "�ҹ��ڸ� �Է����� �ʾҽ��ϴ�." << endl << endl;

		cout << "#3-2: �빮�� -> �ҹ��� ��ȯ" << endl;
		cout << "�빮�ڸ� �Է��ϼ���. : ";
		cin >> ch;
		if ((ch >= 'A') && (ch <= 'Z'))
		{

			cout << "�빮�� : " << ch << " => �ҹ��� : " << convertUpDown(ch) << endl << endl;
		}
		else
			cout << "�빮�ڸ� �Է����� �ʾҽ��ϴ�." << endl << endl;

		cout << "����Ͻðڽ��ϱ�? [y/n] : ";
		cin >> yn;
	} while (yn == 'Y' || yn == 'y');

	// ȭ�� �����
	system("cls");

	//*****************************< lab7 #4 >**********************************
	// #4 �� ���� �����ڸ� �Է� �޾� ��Ģ ������ ó��(if��, switch��)
	//**************************************************************************

	cout << endl << endl;
	cout << "lab7 #4" << endl << endl;

	cout << "������ �Է��ϼ���(��: 3 * 4) ";
	cin >> v1 >> op >> v2;

	if (op == '/' && v2 == 0)
		cout << "�и� 0�̾ ������ �����ϴ�." << endl;
	else
	{
		// if��
			cout << endl;
			cout << "#4 if��" << endl;
			cout << v1 << " " << op << " " << v2 << " = " << calculateValuesIf(v1, v2, op) << endl << endl;

		// switch ��
			cout << endl;
			cout << "#4 switch��" << endl;
			cout << v1 << " " << op << " " << v2 << " = " << calculateValuesSwitch(v1, v2, op) << endl << endl;

		getchar(); getchar();
	}

	// ȭ�� �����
	system("cls");

	//*****************************< lab7 #5 >**********************************
		// #5 1 ~100 ������ ��� �Ҽ��� ���
		//**************************************************************************

	cout << endl << endl;
	cout << "lab7 #5" << endl << endl;

	cout << "2 ~ 100 ������ �Ҽ���" << endl;

	// lab7 ���( 2 ~ n-1 ������ ��� ���� ������ �ѹ��̶� ������ �������� �Ҽ��� �ƴϴ�)

	//2 ~ 100���� �ݺ�
	for (num = 2; num <= 100; num++)
	{
		//num�� �Ҽ��� ���
		if (isPrime(num) == 1)
		{
			cout << num << endl;
		}
	}

	system("pause");
	return 0;
}
