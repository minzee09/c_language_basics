/*	김민지
	디지털미디어
	2020111242
	2분반
	5주차 과제(20/04/16)
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
	cout << "#1 구구단 1x8 형태 출력" << endl << endl;

	int n1, n2;
	//2 부터 9까지 출력
	for (n1 = 2; n1 <= 9; n1++)
	{
		//1 부터 9까지 출력
		for (n2 = 1; n2 <= 9; n2++)
		{
			cout << n1 << " X " << n2 << " = " << setw(3) << n1 * n2 << endl;
		}
		cout << endl;
	}
	getchar();

	cout << "#1 구구단 2x4 형태 출력" << endl << endl;
	int a, b, c;
	//4단씩 출력하기 위해 a을 4씩 증가시킨다
	for (a = 2; a < 10; a += 4)
	{
		//a x b = c에서 b를 1부터 9까지 출력하기 위한 for문
		for (b = 1; b < 10; b++)
		{
			//a x b = c에서 a를 2부터 9까지 출력하기 위한 for문
			for (c = a; c <= a+3; c++)
			{
				cout << c << " x " << b << " = " << setw(2) << b * c << "  ";
			}
			//하나의 'a x b = c'가 끝나면 줄바꿈
			cout << endl;
		}
		//구구단 5단까지 출력 되면 6단부터 출력하기 위한 줄바꿈
		cout << endl;
	}
	getchar();

	//#2
	int random = 0;
	int guess = 0;
	int count = 1;

	srand((unsigned int)time(NULL));

	//랜덤 숫자 선언
	random = rand() % 100 + 1;

	cout << "#2 컴퓨터가 생성한 무작위 수(1~100) 맞추기" << endl;
	cout << "컴퓨터가 생성한 1 ~ 100 사이의 난수를 맞춰 보세요" << endl << endl;
	while (1)
	{
		cout << count << "번째 시도: 추측값은? ";
		cin >> guess;
		//난수를 맞출 경우
		if (guess == random)
		{
			break;
		}
		//난수가 추측값 보다 클 경우
		if (guess < random)
		{
			cout << "좀 더 큰 값을 입력하세요" << endl << endl;
		}
		//난수가 추측값 보다 작을 경우
		else
		{
			cout << "좀 더 작은 값을 입력하세요" << endl << endl;
		}
		//시도 횟수
		count++;

	}
	cout << "정답입니다. " << count << "번만에 맞췄습니다." << endl << endl;
	
	//#3
	int i, num = 0;
	int count2 = 0;
	int count3 = 0; 
	int count5 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum5 = 0;
	
	cout << "#3 1~입력받은 정수 중 2, 3, 5의 배수의 개수와 그 합 구하기 " << endl << endl;
	cout << "정수를 입력하세요: ";
	cin >> num;

	//1부터 입력받은 정수까지 반복
	for (i = 1; i <= num; i++)
	{
		//2의 배수인 경우
		if (i % 2 == 0)
		{
			sum2 += i;//2의 배수의 합
			count2++;//2의 배수의 개수
		}
		//3의 배수인 경우
		if (i % 3 == 0)
		{
			sum3 += i;//3의 배수의 합
			count3++;//3의 배수의 개수
		}
		//5의 배수인 경우
		if (i % 5 == 0)
		{
			sum5 += i;//5의 배수의 합
			count5++;//5의 배수의 개수
		}
	}
	cout << "2의 배수는 " << count2 << "개 이고 합은 " << sum2 << "입니다." << endl;
	cout << "3의 배수는 " << count3 << "개 이고 합은 " << sum3 << "입니다." << endl;
	cout << "5의 배수는 " << count5 << "개 이고 합은 " << sum5 << "입니다." << endl << endl;


	//#4
	int random1, random2, random3;
	int answer1, answer2, answer3;
	char yn = 0;
	cout << "#4 기억력 테스트 게임" << endl << endl;
	cout << "기억력 테스트 입니다" << endl;
	
	do
	{
		cout << "3초 후에 화면에 보이는 숫자들을 기억하다가 다시 쓰세요" << endl << endl;

		//3초 동안 실행 정지
		sleep(3000);

		//0 ~ 9 사이의 난수 3개 선언
		srand((unsigned int)time(NULL));
		random1 = rand() % 10 + 1;
		random2 = rand() % 10 + 1;
		random3 = rand() % 10 + 1;
		cout << "==>		" << random1 << "	" << random2 << "	" << random3;

		//1초 동안 실행 정지
		sleep(1000);

		//줄 맨 앞으로 이동
		cout << '\r';
		cout << "화면에서 본 숫자들을 순서대로 입력하세요 ==> ";
		cin >> answer1 >> answer2 >> answer3;

		//맞춘 경우
		if (random1 == answer1 && random2 == answer2 && random3 == answer3)
			cout << "맞았습니다" << endl;

		//틀린 경우
		else
			cout << "틀렸습니다" << endl;
		cout << endl;
		cout << "다시 하시겠습니까?(Y/N) : ";
		cin >> yn;
		cout << endl;

	} while (yn == 'Y' || yn == 'y');//y 또는 Y 누르면 반복

	//#5 
	int in;

	//나눠 떨어지는지 확인하기 위한 변수
	int divisor = 0;

	cout << "#5 2 ~ 입력받은 정수 사이의 소수 출력" << endl;
	cout << "정수를 입력하세요 : ";
	cin >> in;
	for (int k = 2; k <= in; k++)
	{
		//1 보다 크고 k보다 작은 숫자로 나눠 떨어지는지 확인
		for (int j = 2; j < k; j++)
		{
			//나눠 떨어지면 1과 k사이에 약수가 있다는 뜻
			if (k % j == 0)
			{
				//약수 있으므로 '참'으로 설정
				divisor = 1;
				break;
			}
		}
		//약수가 없으면 소수다
		if (!divisor)
			cout << k << endl;

		//초기화
		divisor = 0;
		
	}




	return 0;
}