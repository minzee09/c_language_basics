/*�����
�����й̵���а�
2020111242
*/

#include<iostream>

using namespace std;

int main()
{
	//6��

	double kg;
	const double pound = 2.2;//��ȣ��� ����
	const double ounce = 16;//��ȣ��� ����
	cout << "#6: ų�α׷� => �Ŀ��� �½��� ����ȯ��" << endl;
	cout << "���Ը� �Է��ϼ���(kg): ";
	cin >> kg; //���� kg�� �Էµ� ���� ����

	cout << kg << "ų�α׷���(kg) " << kg * pound << " �Ŀ��(lb)�Դϴ�." << endl;//ų�α׷��� �Ŀ��� ��ȯ�Ͽ� ����
	cout << kg << "ų�α׷���(kg) " << kg * pound * ounce << " �½�(oz)�Դϴ�." << endl;//ų�α׷��� �½��� ��ȯ�Ͽ� ����
	cout << endl;

	//9��

	int n,n1,n10,n100;
	cout << "#9: 10,000���� ���� ���� => õ�� �ڸ�, ���� �ڸ�, ���� �ڸ�, ���� �ڸ��� �и� ���" << endl;
	cout << "10,000���� ���� ������ �Է��ϼ���: ";
	cin >> n;
	n1 = n % 10;//������ ������ ����Ͽ� ���� �ڸ��� n1�� ����
	n /= 10;//���� �ڸ��� ���ϱ� ���� n�� 10�� ������ ����
	n10 = n % 10;//������ ������ ����Ͽ� ���� �ڸ��� n10�� ����
	n /= 10;//���� �ڸ��� ���ϱ� ���� n�� 10�� ������ ����
	n100 = n % 10;//������ ������ ����Ͽ� ���� �ڸ��� n100�� ����
	n /= 10;//õ�� �ڸ��� ���ϱ� ���� n�� 10�� ������ ����
	
	cout << "õ�� �ڸ�: " << n << endl;
	cout << "���� �ڸ�: " << n100 << endl;
	cout << "���� �ڸ�: " << n10 << endl;
	cout << "���� �ڸ�: " << n1 << endl;
	cout << endl;

	//11��
	double radius,height;
	const double pi = 3.14159;//��ȣ��� ����
	cout << "#11: ������� ���� ���" << endl;
	cout << "����� �ظ��� �������� �Է��ϼ���: ";
	cin >> radius;
	cout << "������� ���̸� �Է��ϼ���: ";
	cin >> height;
	cout << "������� ���Ǵ� " << radius * radius * height * pi << "�Դϴ�." << endl;

	return 0;
}