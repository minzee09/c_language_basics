/*	�����
	�����й̵��
	2020111242
	2�й�
	5���� ����(20/04/16)
*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void sleep(clock_t wait)
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}


int main()
{
	//#1 
	cout << "#1 ������ 1x8 ���� ���" << endl << endl;

	int n1, n2;
	//2 ���� 9���� ���
	for (n1 = 2; n1 <= 9; n1++)
	{
		//1 ���� 9���� ���
		for (n2 = 1; n2 <= 9; n2++)
		{
			cout << n1 << " X " << n2 << " = " << setw(3) << n1 * n2 << endl;
		}
		cout << endl;
	}
	getchar();

	cout << "#1 ������ 2x4 ���� ���" << endl << endl;
	int a, b, c;
	//4�ܾ� ����ϱ� ���� a�� 4�� ������Ų��
	for (a = 2; a < 10; a += 4)
	{
		//a x b = c���� b�� 1���� 9���� ����ϱ� ���� for��
		for (b = 1; b < 10; b++)
		{
			//a x b = c���� a�� 2���� 9���� ����ϱ� ���� for��
			for (c = a; c <= a+3; c++)
			{
				cout << c << " x " << b << " = " << setw(2) << b * c << "  ";
			}
			//�ϳ��� 'a x b = c'�� ������ �ٹٲ�
			cout << endl;
		}
		//������ 5�ܱ��� ��� �Ǹ� 6�ܺ��� ����ϱ� ���� �ٹٲ�
		cout << endl;
	}
	getchar();

	//#2
	int random = 0;
	int guess = 0;
	int count = 1;

	srand((unsigned int)time(NULL));

	//���� ���� ����
	random = rand() % 100 + 1;

	cout << "#2 ��ǻ�Ͱ� ������ ������ ��(1~100) ���߱�" << endl;
	cout << "��ǻ�Ͱ� ������ 1 ~ 100 ������ ������ ���� ������" << endl << endl;
	while (1)
	{
		cout << count << "��° �õ�: ��������? ";
		cin >> guess;
		//������ ���� ���
		if (guess == random)
		{
			break;
		}
		//������ ������ ���� Ŭ ���
		if (guess < random)
		{
			cout << "�� �� ū ���� �Է��ϼ���" << endl << endl;
		}
		//������ ������ ���� ���� ���
		else
		{
			cout << "�� �� ���� ���� �Է��ϼ���" << endl << endl;
		}
		//�õ� Ƚ��
		count++;

	}
	cout << "�����Դϴ�. " << count << "������ ������ϴ�." << endl << endl;
	
	//#3
	int i, num = 0;
	int count2 = 0;
	int count3 = 0; 
	int count5 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum5 = 0;
	
	cout << "#3 1~�Է¹��� ���� �� 2, 3, 5�� ����� ������ �� �� ���ϱ� " << endl << endl;
	cout << "������ �Է��ϼ���: ";
	cin >> num;

	//1���� �Է¹��� �������� �ݺ�
	for (i = 1; i <= num; i++)
	{
		//2�� ����� ���
		if (i % 2 == 0)
		{
			sum2 += i;//2�� ����� ��
			count2++;//2�� ����� ����
		}
		//3�� ����� ���
		if (i % 3 == 0)
		{
			sum3 += i;//3�� ����� ��
			count3++;//3�� ����� ����
		}
		//5�� ����� ���
		if (i % 5 == 0)
		{
			sum5 += i;//5�� ����� ��
			count5++;//5�� ����� ����
		}
	}
	cout << "2�� ����� " << count2 << "�� �̰� ���� " << sum2 << "�Դϴ�." << endl;
	cout << "3�� ����� " << count3 << "�� �̰� ���� " << sum3 << "�Դϴ�." << endl;
	cout << "5�� ����� " << count5 << "�� �̰� ���� " << sum5 << "�Դϴ�." << endl << endl;


	//#4
	int random1, random2, random3;
	int answer1, answer2, answer3;
	char yn = 0;
	cout << "#4 ���� �׽�Ʈ ����" << endl << endl;
	cout << "���� �׽�Ʈ �Դϴ�" << endl;
	
	do
	{
		cout << "3�� �Ŀ� ȭ�鿡 ���̴� ���ڵ��� ����ϴٰ� �ٽ� ������" << endl << endl;

		//3�� ���� ���� ����
		sleep(3000);

		//0 ~ 9 ������ ���� 3�� ����
		srand((unsigned int)time(NULL));
		random1 = rand() % 10 + 1;
		random2 = rand() % 10 + 1;
		random3 = rand() % 10 + 1;
		cout << "==>		" << random1 << "	" << random2 << "	" << random3;

		//1�� ���� ���� ����
		sleep(1000);

		//�� �� ������ �̵�
		cout << '\r';
		cout << "ȭ�鿡�� �� ���ڵ��� ������� �Է��ϼ��� ==> ";
		cin >> answer1 >> answer2 >> answer3;

		//���� ���
		if (random1 == answer1 && random2 == answer2 && random3 == answer3)
			cout << "�¾ҽ��ϴ�" << endl;

		//Ʋ�� ���
		else
			cout << "Ʋ�Ƚ��ϴ�" << endl;
		cout << endl;
		cout << "�ٽ� �Ͻðڽ��ϱ�?(Y/N) : ";
		cin >> yn;
		cout << endl;

	} while (yn == 'Y' || yn == 'y');//y �Ǵ� Y ������ �ݺ�

	//#5 
	int in;

	//���� ���������� Ȯ���ϱ� ���� ����
	int divisor = 0;

	cout << "#5 2 ~ �Է¹��� ���� ������ �Ҽ� ���" << endl;
	cout << "������ �Է��ϼ��� : ";
	cin >> in;
	for (int k = 2; k <= in; k++)
	{
		//1 ���� ũ�� k���� ���� ���ڷ� ���� ���������� Ȯ��
		for (int j = 2; j < k; j++)
		{
			//���� �������� 1�� k���̿� ����� �ִٴ� ��
			if (k % j == 0)
			{
				//��� �����Ƿ� '��'���� ����
				divisor = 1;
				break;
			}
		}
		//����� ������ �Ҽ���
		if (!divisor)
			cout << k << endl;

		//�ʱ�ȭ
		divisor = 0;
		
	}




	return 0;
}