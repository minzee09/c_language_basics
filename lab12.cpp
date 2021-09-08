/*
lab12.cpp

lab12 실습 프로그램
#1 실수 배열의 값에 대한 평균, 최대, 총합을 계산해서 인수로 반환
   (프로그래밍 연습문제 #9 교재 295쪽)
#2 두 수 중에서 최소/최대값을 반환하는 함수 findMinMax()
   (LAB #1 교재 330쪽)
#3 사용자의 답변이 긍적이면 1을, 부정이면 0, 그 외에는 -1을 반환하는 함수 getAnswer(char *question)
   (프로그래밍 연습문제 #19 교재 297쪽)


학번: 2020111242
이름: 김민지
분반: 02(목56교시)
*/

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//함수 원형

//#1
void get_stat(double dnumbers[], int size, double* avg, double* max, double* sum);    //포인터 인수로 반환
void get_stat(double dnumbers[], int size, double& avg, double& max, double& sum);   //레퍼런스 인수로 반환

//#2
void findMinMax(int x, int y, int& max, int& min);                      //정수 2개 & 레퍼런스 인수 사용
void findMinMax(double x, double y, double* max, double* min);          //실수 2개 & 포인터 인수 사용
void findMinMax(int x[], int size, int& max, int& min);                 //정수 배열 & 레퍼런스 인수 사용

//#3
int getAnswer(char* question);    //사용자의 답변이 긍정이면 1 반환, 부정이면 -1 반환


int main()
{
    const int SIZE = 10;    //배열 크기 기호 상수로 선언 및 저장

    //#1
    double adv, max, sum;
    double dnumbers[SIZE] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.0 };

    //배열 출력
    cout << "배열 :";
    for (int i = 0; i < SIZE; i++)
        cout << setw(5) << dnumbers[i];
    cout << endl << endl;

    cout << endl;
    cout << "#1-1 배열의 원소에 대한 평균, 최대, 합계 계산 (참조에 의한 호출(포인터/주소))" << endl;
    cout << endl;

    get_stat(dnumbers, SIZE, &adv, &max, &sum);     //포인터 인수로 변환하는 함수 호출

    cout << "합계 : " << sum << endl;
    cout << "평균 : " << adv << endl;
    cout << "최대 : " << max << endl;

    cout << endl;
    cout << "#1-2 배열의 원소에 대한 평균, 최대, 합계 계산 (참조에 의한 호출(레퍼런스))" << endl;
    cout << endl;
    
    //0으로 초기화
    adv = 0;
    max = 0;
    sum = 0;

    get_stat(dnumbers, SIZE, adv, max, sum);        //레퍼런스 인수로 변환하는 함수 호출

    cout << "합계 : " << sum << endl;
    cout << "평균 : " << adv << endl;
    cout << "최대 : " << max << endl;
    
    getchar();

    //#2

    //#2-1
    cout << endl;
    cout << "#2-1 두 정수 중 최대/최소값 계산 (참조에 의한 호출(레퍼런스))" << endl;
    cout << endl;

    int n1 = 12;
    int n2 = 34;
    int intmax, intmin;

    findMinMax(n1, n2, intmax, intmin);     //레퍼런스 인수 사용하는 함수 호출

    cout << "두 정수 중 최소값은 " << intmin << ", 최대값은 " << intmax << "입니다." << endl;
    
    getchar();

    //#2-2
    cout << endl;
    cout << "#2-2 두 정수 중 최대/최소값 계산 (참조에 의한 호출(포인터))" << endl;
    cout << endl;

    double d1 = 1.2;
    double d2 = 3.4;
    double dmax, dmin;

    findMinMax(d1, d2, &dmax, &dmin);       //포인터 인수 사용하는 함수 호출

    cout << "두 정수 중 최소값은 " << dmin << ", 최대값은 " << dmax << "입니다." << endl;

    getchar();

    //#2-3
    cout << endl;
    cout << "#2-3 정수 배열 원소 중 최대/최소값 계산 (참조에 의한 호출(레퍼런스))" << endl;
    cout << endl;

    int inumbers[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
    //0으로 초기화
    intmax = 0;
    intmin = 0;

    findMinMax(inumbers, SIZE, intmax, intmin);     //정수 배열 & 레퍼런스 인수 사용하는 함수 호출

    cout << endl;
    cout << "배열 원소 중 최소값은 " << intmin << ", 최대값은 " << intmax << "입니다." << endl;

    getchar();

    //#3
    cout << endl;
    cout << "#3 긍정/부정 답변 구별하기" << endl;
    cout << endl;

    int result;
    char yn;
    char question[30];

    do
    {
        cout << "질문 : C++ 프로그래밍 재미있나요?" << endl;
        cout << "대답 : ";
        cin >> question;

        //반환값에 따른 호출
        result = getAnswer(question);
        if (result == 1)         //함수에서 1이 반환된 경우
            cout << "긍정적인 답변입니다." << endl;
        else if (result == 0)   //함수에서 1이 반환된 경우
            cout << "부정적인 답변입니다." << endl;
        else                    //함수에서 -1이 반환된 경우
            cout << "긍정이나 부정이 아닌 답변입니다." << endl;
        
        cout << endl;
        cout << "계속하시겠습니까? [y/n] : ";
        cin >> yn;
        cout << endl;

    } while (yn == 'Y' || yn == 'y');

    return 0;
}

//함수
//#1

//#1-1
void get_stat(double dnumbers[], int size, double* avg, double* max, double* sum)
{
    //0으로 초기화
    *sum = 0;
    *avg = 0;
    *max = dnumbers[0];

    //총합 계산
    for (int i = 0; i < size; i++)
        *sum += dnumbers[i];

    //평균값 계산
    *avg = *sum / (double)size;

    //최대값 계산
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
    //0으로 초기화
    sum = 0;
    avg = 0;
    max = dnumbers[0];

    //총합 계산
    for (int i = 0; i < size; i++)
        sum += dnumbers[i];

    //평균값 계산
    avg = sum / (double)size;

    //최대값 계산
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
    //x가 최대값, y가 최소값인 경우 
    if (x > y)
    {
        max = x;
        min = y;
    }
    //y가 최대값, x가 최소값인 경우
    else
    {
        max = y;
        min = x;
    }
}
//#2-2
void findMinMax(double x, double y, double* max, double* min)
{
    //x가 최대값, y가 최소값인 경우
    if (x > y)
    {
        *max = x;
        *min = y;
    }
    //y가 최대값, x가 최소값인 경우
    else
    {
        *max = y;
        *min = x;
    }
}
//#2-3
void findMinMax(int x[], int size, int& max, int& min)
{
    //배열 출력
    for (int i = 0; i < size; i++)
        cout << setw(5) << x[i];
    cout << endl;

    max = x[0];
    min = x[0];
    //최대값,최소값 찾기
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
    //사용자의 답변과 긍정적 답변 비교    
    if (strcmp(question,"yes") == 0 || strcmp(question,"ok") == 0)           //일치 하는 경우 -> 1 반환
        return 1;
    //사용자의 답변과 부정적 답변 비교
    else if (strcmp(question, "no") == 0 || strcmp(question, "never") == 0) //일치 하는 경우 -> 0 반환
        return 0;
    else
        return -1;      //긍정도 부정도 아닌 경우 -> -1 반환;
}