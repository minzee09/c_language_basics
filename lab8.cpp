/*
lab8.cpp

lab8 �ǽ� ���α׷�
#1 �ﰢ���� �ѷ� ���
   ������ ����� �� 3���� ���̸� Ȯ���Ͽ� �ﰢ���� �������� Ȯ���ϰ� ���
#2 �� ���� ��ǥ�� �Է� �޾� �� �� ������ �Ÿ��� ����ϴ� �Լ�
   (4�� ���α׷��� �������� #3)
#3 ������ �Է� �޾� �� �ڸ� ���� ���� ���ϱ�
   (��- 123 �Է½�, 3, 2, 1�� ���� ���ؼ� 6�̶�� ���� ���Ѵ�.)
#4 ���� ����(��Ģ����): (4�� ���α׷��� �������� #11)
    -����ڿ��� �Է� �޽����� ���̰� ������ �Է� �޾� �����ڸ� ��ȯ�Ѵ�
    - ������ ���� ������ ���� �� �������� �Էµȴ�
    - �ǿ����ڴ� ���� ������ ����

�й�: 2020111242
�̸�: �����
�й�: 02(��56����)
*/

#include <iostream>
#include <math.h>
using namespace std;

//�Լ� ����

//#1
bool isValid(double a, double b, double c);
double getCircumference(double a, double b, double c);

//#2
double dist_2d(double x1, double y1, double x2, double y2);

//#3
int getSum(int number);

//#4
char get_input();
double add(double n1, double n2);
double subtract(double n1, double n2);
double multiply(double n1, double n2);
double divide(double n1, double n2);

double n1, n2;  //�ǿ����� ���� ����

int main()
{
    //���� ����

    char yn;                //�ݺ�
    double result;          

    //#1
    double a, b, c;         //�ﰢ�� ����
    bool v;                 //�ﰢ������ �ƴ��� 
   
    //#2
    double x1, y1, x2, y2;  //��ǥ1 ��ǥ2

    //#3
    int number;             //����
    


    // #1 �ﰢ���� �ѷ� ���

    cout << endl;
    cout << "#1: �ﰢ���� �ѷ� ���" << endl;

    do
    {
        cout << "�ﰢ���� ������ �Է��ϼ��� ==> ";
        cin >> a >> b >> c;

        v = isValid(a, b, c);
        result = getCircumference(a, b, c);

        if (v == true)  //���� ���
            cout << "�ﰢ���� �ѷ� = " << result << endl;
        else            //������ ���
            cout << "�ﰢ���� �������� �ʽ��ϴ�." << endl;

        cout << endl;
        cout << "����Ͻðڽ��ϱ�? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    // #2 �� ���� ��ǥ�� �Է� �޾� �� �� ������ �Ÿ��� ����ϴ� �Լ�
    
    cout << endl;
    cout << "#2: �� �� ������ �Ÿ� ���" << endl;

    do
    {
        cout << "��ǥ 1�� �Է��ϼ��� ==> ";
        cin >> x1 >> y1;

        cout << "��ǥ 2�� �Է��ϼ��� ==>";
        cin >> x2 >> y2;

        result = dist_2d(x1, y1, x2, y2);

        cout << "�� ������ �Ÿ��� " << result << "�Դϴ�." << endl;


        cout << endl;
        cout << "����Ͻðڽ��ϱ�? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    // #3 ������ �Է� �޾� �� �ڸ� ���� ���� ���ϱ�
    
    cout << endl;
    cout << "#3: ������ �� �ڸ��� �� ���ϱ�" << endl;
    do
    {
        cout << "������ �Է��ϼ��� ==> ";
        cin >> number;

        cout << "getSum() " << number << "�� �ڸ����� �� = " << getSum(number) << endl;


        cout << endl;
        cout << "����Ͻðڽ��ϱ�? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    // #4 ���� ����(��Ģ����)

    cout << endl;
    cout << "#4: ��Ģ ����� ����ϱ�" << endl;

    do
    {
        char get_input();
       
        result = get_input();

        if (result == '+')
            add(n1, n2);
        else if (result == '-')
            subtract(n1, n2);
        else if (result == '*')
            multiply(n1, n2);
        else if (result == '/')
            divide(n1, n2);
        else
            cout << "�����ڸ� �߸� �Է��߽��ϴ�." << endl;


        cout << endl;
        cout << "����Ͻðڽ��ϱ�? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');



    return 0;
}

//#1 �Լ�

bool isValid(double a, double b, double c)
{
    //�ﰢ�� ��������
    if (a + b > c && b + c > a && a + c > b)
        return true;
    else
        return false;
}

double getCircumference(double a, double b, double c)       //�ﰢ�� �ѷ��� ���� ���
{
    return (a + b + c);
}

//#2 �Լ�

double dist_2d(double x1, double y1, double x2, double y2)  //�� �� ������ �Ÿ� ��� �Լ�
{
    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));     //<math.h>�� �̿��Ͽ� �� �� ������ �Ÿ� ���ϱ�
    return d;
}

//#3 �Լ�

int getSum(int number)                  //�Է� ���� ������ �� �ڸ����� �� ���ϴ� �Լ�
{
    int result = 0;

    while (number != 0)
    {
        result = result + (number % 10);
        number = number / 10;
    }
    return result;
}

//#4 �Լ�

char get_input()                        //������ ��ȯ �Լ�
{
    char op;

    cout << "<����1 ���� ����2>�� �������� ������ �Է��ϼ��� ==> ";
    cin >> n1 >> op >> n2;

    return op;
}

double add(double n1, double n2)        //���� ���� �Լ�
{
    static int addcount;                //���� �Լ� ����

    addcount++;
    cout << "���� �Լ��� " << addcount << "�� ȣ��Ǿ����ϴ�." << endl;
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;

    return 0;
}

double subtract(double n1, double n2)   //���� ���� �Լ�
{
    static int subcount;                //���� �Լ� ����

    subcount++;
    cout << "���� �Լ��� " << subcount << "�� ȣ��Ǿ����ϴ�." << endl;
    cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;

    return 0;
}

double multiply(double n1, double n2)   //���� ���� �Լ�
{
    static int multcount;               //���� �Լ� ����

    multcount++;
    cout << "���� �Լ��� " << multcount << "�� ȣ��Ǿ����ϴ�." << endl;
    cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;

    return 0;
}

double divide(double n1, double n2)     //������ ���� �Լ�
{
    static int divcount;                //���� �Լ� ����

    if (n2 == 0)                        //�и� 0�� ���
        cout << "����� ����� �� �����ϴ�" << endl;
    else
    {
        divcount++;
        cout << "������ �Լ��� " << divcount << "�� ȣ��Ǿ����ϴ�." << endl;
        cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
    }
    return 0;
}

