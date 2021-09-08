/*
lab12.cpp

lab12 �ǽ� ���α׷�
#1 �Ǽ� �迭�� ���� ���� ���, �ִ�, ������ ����ؼ� �μ��� ��ȯ
   (���α׷��� �������� #9 ���� 295��)
#2 �� �� �߿��� �ּ�/�ִ밪�� ��ȯ�ϴ� �Լ� findMinMax()
   (LAB #1 ���� 330��)
#3 ������� �亯�� �����̸� 1��, �����̸� 0, �� �ܿ��� -1�� ��ȯ�ϴ� �Լ� getAnswer(char *question)
   (���α׷��� �������� #19 ���� 297��)


�й�: 2020111242
�̸�: �����
�й�: 02(��56����)
*/

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//�Լ� ����

//#1
void get_stat(double dnumbers[], int size, double* avg, double* max, double* sum);    //������ �μ��� ��ȯ
void get_stat(double dnumbers[], int size, double& avg, double& max, double& sum);   //���۷��� �μ��� ��ȯ

//#2
void findMinMax(int x, int y, int& max, int& min);                      //���� 2�� & ���۷��� �μ� ���
void findMinMax(double x, double y, double* max, double* min);          //�Ǽ� 2�� & ������ �μ� ���
void findMinMax(int x[], int size, int& max, int& min);                 //���� �迭 & ���۷��� �μ� ���

//#3
int getAnswer(char* question);    //������� �亯�� �����̸� 1 ��ȯ, �����̸� -1 ��ȯ


int main()
{
    const int SIZE = 10;    //�迭 ũ�� ��ȣ ����� ���� �� ����

    //#1
    double adv, max, sum;
    double dnumbers[SIZE] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.0 };

    //�迭 ���
    cout << "�迭 :";
    for (int i = 0; i < SIZE; i++)
        cout << setw(5) << dnumbers[i];
    cout << endl << endl;

    cout << endl;
    cout << "#1-1 �迭�� ���ҿ� ���� ���, �ִ�, �հ� ��� (������ ���� ȣ��(������/�ּ�))" << endl;
    cout << endl;

    get_stat(dnumbers, SIZE, &adv, &max, &sum);     //������ �μ��� ��ȯ�ϴ� �Լ� ȣ��

    cout << "�հ� : " << sum << endl;
    cout << "��� : " << adv << endl;
    cout << "�ִ� : " << max << endl;

    cout << endl;
    cout << "#1-2 �迭�� ���ҿ� ���� ���, �ִ�, �հ� ��� (������ ���� ȣ��(���۷���))" << endl;
    cout << endl;
    
    //0���� �ʱ�ȭ
    adv = 0;
    max = 0;
    sum = 0;

    get_stat(dnumbers, SIZE, adv, max, sum);        //���۷��� �μ��� ��ȯ�ϴ� �Լ� ȣ��

    cout << "�հ� : " << sum << endl;
    cout << "��� : " << adv << endl;
    cout << "�ִ� : " << max << endl;
    
    getchar();

    //#2

    //#2-1
    cout << endl;
    cout << "#2-1 �� ���� �� �ִ�/�ּҰ� ��� (������ ���� ȣ��(���۷���))" << endl;
    cout << endl;

    int n1 = 12;
    int n2 = 34;
    int intmax, intmin;

    findMinMax(n1, n2, intmax, intmin);     //���۷��� �μ� ����ϴ� �Լ� ȣ��

    cout << "�� ���� �� �ּҰ��� " << intmin << ", �ִ밪�� " << intmax << "�Դϴ�." << endl;
    
    getchar();

    //#2-2
    cout << endl;
    cout << "#2-2 �� ���� �� �ִ�/�ּҰ� ��� (������ ���� ȣ��(������))" << endl;
    cout << endl;

    double d1 = 1.2;
    double d2 = 3.4;
    double dmax, dmin;

    findMinMax(d1, d2, &dmax, &dmin);       //������ �μ� ����ϴ� �Լ� ȣ��

    cout << "�� ���� �� �ּҰ��� " << dmin << ", �ִ밪�� " << dmax << "�Դϴ�." << endl;

    getchar();

    //#2-3
    cout << endl;
    cout << "#2-3 ���� �迭 ���� �� �ִ�/�ּҰ� ��� (������ ���� ȣ��(���۷���))" << endl;
    cout << endl;

    int inumbers[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
    //0���� �ʱ�ȭ
    intmax = 0;
    intmin = 0;

    findMinMax(inumbers, SIZE, intmax, intmin);     //���� �迭 & ���۷��� �μ� ����ϴ� �Լ� ȣ��

    cout << endl;
    cout << "�迭 ���� �� �ּҰ��� " << intmin << ", �ִ밪�� " << intmax << "�Դϴ�." << endl;

    getchar();

    //#3
    cout << endl;
    cout << "#3 ����/���� �亯 �����ϱ�" << endl;
    cout << endl;

    int result;
    char yn;
    char question[30];

    do
    {
        cout << "���� : C++ ���α׷��� ����ֳ���?" << endl;
        cout << "��� : ";
        cin >> question;

        //��ȯ���� ���� ȣ��
        result = getAnswer(question);
        if (result == 1)         //�Լ����� 1�� ��ȯ�� ���
            cout << "�������� �亯�Դϴ�." << endl;
        else if (result == 0)   //�Լ����� 1�� ��ȯ�� ���
            cout << "�������� �亯�Դϴ�." << endl;
        else                    //�Լ����� -1�� ��ȯ�� ���
            cout << "�����̳� ������ �ƴ� �亯�Դϴ�." << endl;
        
        cout << endl;
        cout << "����Ͻðڽ��ϱ�? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    return 0;
}

//�Լ�
//#1

//#1-1
void get_stat(double dnumbers[], int size, double* avg, double* max, double* sum)
{
    //0���� �ʱ�ȭ
    *sum = 0;
    *avg = 0;
    *max = dnumbers[0];

    //���� ���
    for (int i = 0; i < size; i++)
        *sum += dnumbers[i];

    //��հ� ���
    *avg = *sum / (double)size;

    //�ִ밪 ���
    for (int i = 1; i < size; i++)
    {
        if (dnumbers[i] > *max) 
        {
            *max = dnumbers[i];
        }
    }
}
//#1-2
void get_stat(double dnumbers[], int size, double& avg, double& max, double& sum)
{
    //0���� �ʱ�ȭ
    sum = 0;
    avg = 0;
    max = dnumbers[0];

    //���� ���
    for (int i = 0; i < size; i++)
        sum += dnumbers[i];

    //��հ� ���
    avg = sum / (double)size;

    //�ִ밪 ���
    for (int i = 0; i < size; i++)
    {
        if (dnumbers[i] > max)
        {
            max = dnumbers[i];
        }
    }
}

//#2

//#2-1
void findMinMax(int x, int y, int& max, int& min)
{
    //x�� �ִ밪, y�� �ּҰ��� ��� 
    if (x > y)
    {
        max = x;
        min = y;
    }
    //y�� �ִ밪, x�� �ּҰ��� ���
    else
    {
        max = y;
        min = x;
    }
}
//#2-2
void findMinMax(double x, double y, double* max, double* min)
{
    //x�� �ִ밪, y�� �ּҰ��� ���
    if (x > y)
    {
        *max = x;
        *min = y;
    }
    //y�� �ִ밪, x�� �ּҰ��� ���
    else
    {
        *max = y;
        *min = x;
    }
}
//#2-3
void findMinMax(int x[], int size, int& max, int& min)
{
    //�迭 ���
    for (int i = 0; i < size; i++)
        cout << setw(5) << x[i];
    cout << endl;

    max = x[0];
    min = x[0];
    //�ִ밪,�ּҰ� ã��
    for (int i = 1; i < size; i++)
    {
        if (x[i] > max)
            max = x[i];
        if (x[i] < min)
            min = x[i];
    }

}

//#3
int getAnswer(char* question)
{
    //������� �亯�� ������ �亯 ��    
    if (strcmp(question,"yes") == 0 || strcmp(question,"ok") == 0)           //��ġ �ϴ� ��� -> 1 ��ȯ
        return 1;
    //������� �亯�� ������ �亯 ��
    else if (strcmp(question, "no") == 0 || strcmp(question, "never") == 0) //��ġ �ϴ� ��� -> 0 ��ȯ
        return 0;
    else
        return -1;      //������ ������ �ƴ� ��� -> -1 ��ȯ;
}