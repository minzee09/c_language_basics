//�̸�:�����
//�й�:2020111242
//�а�:�����й̵��

#include <iostream>
using namespace std;

int main()
{
	cout << "***<lab2 #1>***" << endl;
	cout << endl;

	short s1 = SHRT_MAX;//short�� �ִ��� s1�� ����
	short s2 = SHRT_MIN;//short�� �ּڰ��� s1�� ����

	cout << "s1 = "<< s1 << endl; //short�� �ִ��� ���
	s1 = s1 + 1;//�����÷ο� �߻�
	cout << "s1 + 1 = " << s1 << endl; //�����÷ο� ���� ���
	cout << endl;
	cout << "s2 = " << s2 << endl; //short�� �ּڰ��� ���
	s2 = s2 - 1;//����÷ο� �߻�
	cout << "s2 - 1 = " << s2 << endl; //����÷ο� ���� ���
	cout << endl;

	cout << "***<lab2 #2>***" << endl;
	cout << endl;
	
	unsigned int u1 = 2; //2�� u1�� ����
	unsigned int u2 = -1;//-1�� u2�� ����

	cout << "u1 = " << u1 << endl;
	cout << "u2 = " << u2 << endl;//����÷ο� ���� ���
	cout << endl;

	cout << "***<lab2 #3>***" << endl;
	cout << endl;

	int person1 = 10;//10�� person1�� ����
	int person2 = 20;//20�� person2�� ����
	int person3 = 30;//30�� person3�� ����
	int person4 = 40;//40�� person4�� ����
	int person5 = 50;//50�� person5�� ����
	cout << "person1 = " << person1 << endl;//person1 ���� ���
	cout << "person2 = " << person2 << endl;//person2 ���� ���
	cout << "person3 = " << person3 << endl;//person3 ���� ���
	cout << "person4 = " << person4 << endl;//person4 ���� ���
	cout << "person5 = " << person5 << endl;//person5 ���� ���
	cout << endl;

	cout << "�������(literal) ���" << endl;
	cout << "person1 = " << person1 + 30 << endl;//person1�� 30�� ���� ���� ���
	cout << "person2 = " << person2 + 30 << endl;//person2�� 30�� ���� ���� ���
	cout << "person3 = " << person3 + 30 << endl;//person3�� 30�� ���� ���� ���
	cout << "person4 = " << person4 + 30 << endl;//person4�� 30�� ���� ���� ���
	cout << "person5 = " << person5 + 30 << endl;//person5�� 30�� ���� ���� ���
	cout << endl;

	cout << "��ȣ���(#define) ���" << endl;
	#define ADD30 30 //��ȣ��� ����
	cout << "person1 = " << person1 + ADD30 << endl;//person1�� ��ȣ����� ���� ���� ���
	cout << "person2 = " << person2 + ADD30 << endl;//person2�� ��ȣ����� ���� ���� ���
	cout << "person3 = " << person3 + ADD30 << endl;//person3�� ��ȣ����� ���� ���� ���
	cout << "person4 = " << person4 + ADD30 << endl;//person4�� ��ȣ����� ���� ���� ���
	cout << "person5 = " << person5 + ADD30 << endl;//person5�� ��ȣ����� ���� ���� ���
	cout << endl;

	cout << "��ȣ���(const) ���" << endl;
	const int ADD = 30;//��ȣ��� ����
	cout << "person1 = " << person1 + ADD << endl;//person1�� ��ȣ����� ���� ���� ���
	cout << "person2 = " << person2 + ADD << endl;//person2�� ��ȣ����� ���� ���� ���
	cout << "person3 = " << person3 + ADD << endl;//person3�� ��ȣ����� ���� ���� ���
	cout << "person4 = " << person4 + ADD << endl;//person4�� ��ȣ����� ���� ���� ���
	cout << "person5 = " << person5 + ADD << endl;//person5�� ��ȣ����� ���� ���� ���
	cout << endl;




	return 0;
}