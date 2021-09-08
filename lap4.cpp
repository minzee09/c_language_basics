/*	�����
	�����й̵���а�
	2020111242
	2�й�
	4���� ���� (20/04/9)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// #4
	double num1, num2;
	char ch;
	cout << "#4 ����" << endl;
	cout << "*************" << endl;
	cout << "+ --- Add" << endl;
	cout << "- --- Subtract" << endl;
	cout << "* --- Multiply" << endl;
	cout << "/ --- Divide" << endl;
	cout << "*************" << endl;
	cout << endl;

	cout << "������ �����Ͻÿ�: ";
	cin >> ch;

	cout << "�� ���� �������� �и��Ͽ� �Է��ϼ���:  ";
	cin >> num1 >> num2;

	//<if�� ���>
	cout << "if��: " << endl;
	//�����ϴ� ���
	if (ch == '+')
		cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
	//�����ϴ� ���
	else if (ch == '-')
		cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
	//�����ϴ� ���
	else if (ch == '*')
		cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
	//�������ϴ� ���
	else if (ch == '/')
		//�и� 0�� ���
		if (num2 == 0)
			cout << "�и� 0�̿��� ���� �� �����ϴ�." << endl;
	//�и� 0�� �ƴ� ���
		else
			cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;
	//������ �ܿ� �Է��� ��� 
	else
		cout << "�߸� �Է��߽��ϴ�." << endl;

	//<switch�� ���>
	cout << "switch��: " << endl;
	switch (ch)
	{
		//�����ϴ� ���
	case '+':
		cout << num1 << "+" << num2 << "=" << num1 + num2 << endl;
		break;
		//�����ϴ� ���
	case '-':
		cout << num1 << "-" << num2 << "=" << num1 - num2 << endl;
		break;
		//�����ϴ� ���
	case '*':
		cout << num1 << "*" << num2 << "=" << num1 * num2 << endl;
		break;
		//�������ϴ� ���
	case '/':
		//�и� 0�� ���
		if (num2 == 0)
			cout << "�и� 0�̿��� ���� �� �����ϴ�." << endl;
		//�и� 0�� �ƴ� ���
		else
			cout << num1 << "/" << num2 << "=" << num1 / num2 << endl;
		break;
		//������ �ܿ� �Է��� ���
	default:
		cout << "�߸� �Է��߽��ϴ�." << endl;
		break;
	}
	cout << endl;

	// #5
	char rtc;
	double n1, n2;
	cout << "#5 ������ ���� ���ϱ�" << endl;
	cout << "���ڸ� �Է��ϼ��� (R,T,C) : ";
	cin >> rtc;


	//<if�� ���>
	cout << "if��:" << endl;
	// r �Ǵ� R �Է��� ���
	if (rtc == 'r' || rtc == 'R')
	{
		cout << "�غ� ����, ���̸� �Է��ϼ���: ";
		cin >> n1 >> n2;
		cout << "�簢���� ������ : " << n1 * n2 << endl;
	}
	// t �Ǵ� T �Է��� ���
	else if (rtc == 't' || rtc == 'T')
	{
		cout << "�غ�, ���̸� �Է��ϼ���: ";
		cin >> n1 >> n2;
		cout << "�ﰢ���� ������ : " << (n1 * n2) / 2 << endl;
	}
	// c �Ǵ� C �Է��� ���
	else if (rtc == 'c' || rtc == 'C')
	{
		cout << "�������� �Է��ϼ���: ";
		cin >> n1;
		cout << "���� ������ : " << pow(n1, 2) * 3.14 << endl;
	}
	//�߸� �Է����� ���
	else
		cout << "�߸� �Է��߽��ϴ�.(R, T, C)" << endl;
	cout << endl;

	//0���� �ʱ�ȭ
	n1, n2 = 0;

	//<switch�� ���>
	cout << "switch��:" << endl;
	switch (rtc)
	{
		// r �Ǵ� R �Է��� ���
	case'r':
	case'R':
		cout << "�غ� ����, ���̸� �Է��ϼ���: ";
		cin >> n1 >> n2;
		cout << "�簢���� ������ : " << n1 * n2 << endl;
		break;
		// t �Ǵ� T �Է��� ���
	case't':
	case'T':
		cout << "�غ�, ���̸� �Է��ϼ���: ";
		cin >> n1 >> n2;
		cout << "�ﰢ���� ������ : " << (n1 * n2) / 2 << endl;
		break;
		// c �Ǵ� C �Է��� ���
	case'c':
	case'C':
		cout << "�������� �Է��ϼ���: ";
		cin >> n1;
		cout << "���� ������ : " << pow(n1, 2) * 3.14 << endl;
		break;
		//�߸� �Է����� ���
	default:
		cout << "�߸� �Է��߽��ϴ�.(R, T, C)" << endl;
		break;
	}
	cout << endl;

	//#9
	char vc; //vowel consonants
	cout << "#9 ������ ������ ����" << endl;
	cout << "�ϳ��� ���ڸ� �Է��ϼ��� : ";
	cin >> vc;
	cout << endl;

	//���ĺ����� �ƴ��� ����
	if (vc <= 64 || (vc >= 91 && vc <= 96) || vc >= 123)//�ƽ�Ű�ڵ� ���
		cout << "���ĺ��� �ƴմϴ�." << endl;
	else
	{
		//<if�� ���>
		cout << "if��:" << endl;
		if (vc == 65 || vc == 69 || vc == 73 || vc == 79 || vc == 85 || vc == 97 || vc == 101 || vc == 105 || vc == 111 || vc == 117)//���� (��ҹ��� ����)
			cout << "�Է��Ͻ� ���ڴ� �����Դϴ�." << endl;
		else
			cout << "�Է��Ͻ� ���ڴ� �����Դϴ�." << endl;

		//<switch�� ���>
		cout << "switch��:" << endl;
		switch (vc)
		{
		case 65: case 69: case 73: case 79: case 85: case 97: case 101: case 105: case 111: case 117://���� (��ҹ��� ����)
			cout << "�Է��Ͻ� ���ڴ� �����Դϴ�." << endl;
			break;
		default:
			cout << "�Է��Ͻ� ���ڴ� �����Դϴ�." << endl;
			break;
		}
	}
	return 0;
}
