/*
lab8.cpp

lab8 실습 프로그램
#1 삼각형의 둘레 계산
   면적을 계산할 때 3변의 길이를 확인하여 삼각형이 가능한지 확인하고 계산
#2 두 점의 좌표를 입력 받아 두 점 사이의 거리를 계산하는 함수
   (4장 프로그래밍 연습문제 #3)
#3 정수를 입력 받아 각 자리 수의 합을 구하기
   (예- 123 입력시, 3, 2, 1을 각각 더해서 6이라는 값을 구한다.)
#4 수식 계산기(사칙연산): (4장 프로그래밍 연습문제 #11)
    -사용자에게 입력 메시지를 보이고 수식을 입력 받아 연산자를 반환한다
    - 수식은 숫자 연산자 숫자 의 형식으로 입력된다
    - 피연산자는 전역 변수로 선언

학번: 2020111242
이름: 김민지
분반: 02(목56교시)
*/

#include <iostream>
#include <math.h>
using namespace std;

//함수 원형

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

double n1, n2;  //피연산자 전역 변수

int main()
{
    //변수 선언

    char yn;                //반복
    double result;          

    //#1
    double a, b, c;         //삼각형 세변
    bool v;                 //삼각형인지 아닌지 
   
    //#2
    double x1, y1, x2, y2;  //좌표1 좌표2

    //#3
    int number;             //정수
    


    // #1 삼각형의 둘레 계산

    cout << endl;
    cout << "#1: 삼각형의 둘레 계산" << endl;

    do
    {
        cout << "삼각형의 세변을 입력하세요 ==> ";
        cin >> a >> b >> c;

        v = isValid(a, b, c);
        result = getCircumference(a, b, c);

        if (v == true)  //참인 경우
            cout << "삼각형의 둘레 = " << result << endl;
        else            //거짓인 경우
            cout << "삼각형이 구성되지 않습니다." << endl;

        cout << endl;
        cout << "계속하시겠습니까? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    // #2 두 점의 좌표를 입력 받아 두 점 사이의 거리를 계산하는 함수
    
    cout << endl;
    cout << "#2: 두 점 사이의 거리 계산" << endl;

    do
    {
        cout << "좌표 1을 입력하세요 ==> ";
        cin >> x1 >> y1;

        cout << "좌표 2를 입력하세요 ==>";
        cin >> x2 >> y2;

        result = dist_2d(x1, y1, x2, y2);

        cout << "두 점간의 거리는 " << result << "입니다." << endl;


        cout << endl;
        cout << "계속하시겠습니까? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    // #3 정수를 입력 받아 각 자리 수의 합을 구하기
    
    cout << endl;
    cout << "#3: 정수의 각 자리수 합 구하기" << endl;
    do
    {
        cout << "정수를 입력하세요 ==> ";
        cin >> number;

        cout << "getSum() " << number << "의 자리수의 합 = " << getSum(number) << endl;


        cout << endl;
        cout << "계속하시겠습니까? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    // #4 수식 계산기(사칙연산)

    cout << endl;
    cout << "#4: 사칙 연산식 계산하기" << endl;

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
            cout << "연산자를 잘못 입력했습니다." << endl;


        cout << endl;
        cout << "계속하시겠습니까? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');



    return 0;
}

//#1 함수

bool isValid(double a, double b, double c)
{
    //삼각형 결정조건
    if (a + b > c && b + c > a && a + c > b)
        return true;
    else
        return false;
}

double getCircumference(double a, double b, double c)       //삼각형 둘레의 길이 계산
{
    return (a + b + c);
}

//#2 함수

double dist_2d(double x1, double y1, double x2, double y2)  //두 점 사이의 거리 계산 함수
{
    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));     //<math.h>를 이용하여 두 점 사이의 거리 구하기
    return d;
}

//#3 함수

int getSum(int number)                  //입력 받은 정수의 각 자리수의 합 구하는 함수
{
    int result = 0;

    while (number != 0)
    {
        result = result + (number % 10);
        number = number / 10;
    }
    return result;
}

//#4 함수

char get_input()                        //연산자 반환 함수
{
    char op;

    cout << "<숫자1 연산 숫자2>의 형식으로 수식을 입력하세요 ==> ";
    cin >> n1 >> op >> n2;

    return op;
}

double add(double n1, double n2)        //덧셈 연산 함수
{
    static int addcount;                //정적 함수 선언

    addcount++;
    cout << "덧셈 함수는 " << addcount << "번 호출되었습니다." << endl;
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;

    return 0;
}

double subtract(double n1, double n2)   //뺄셈 연산 함수
{
    static int subcount;                //정적 함수 선언

    subcount++;
    cout << "뺄셈 함수는 " << subcount << "번 호출되었습니다." << endl;
    cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;

    return 0;
}

double multiply(double n1, double n2)   //곱셈 연산 함수
{
    static int multcount;               //정적 함수 선언

    multcount++;
    cout << "곱셈 함수는 " << multcount << "번 호출되었습니다." << endl;
    cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;

    return 0;
}

double divide(double n1, double n2)     //나눗셈 연산 함수
{
    static int divcount;                //정적 함수 선언

    if (n2 == 0)                        //분모가 0인 경우
        cout << "결과를 출력할 수 없습니다" << endl;
    else
    {
        divcount++;
        cout << "나눗셈 함수는 " << divcount << "번 호출되었습니다." << endl;
        cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
    }
    return 0;
}

