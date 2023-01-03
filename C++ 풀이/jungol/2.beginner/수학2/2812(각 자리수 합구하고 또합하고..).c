#include <stdio.h>

char n[10000];

int an2(void);
int an(int m);
int main(void)
{
	int m;

	scanf("%s", n); // char형 사용 -> 1byte 즉 한 공간에 숫자 하나씩 저장

	m = an2(); // char로 되어있는 것을 int로 변환
	printf("%d\n", m);

	while (m >= 10)
	{
		m = an(m); //int 형 숫자 계산
		printf("%d\n", m);
	}

	return 0;
}
int an2(void)
{
	int i, sum = 0;

	for (i = 0; n[i] != '\0'; i++) // char형 배열에는 아스키 코드값 저장 되어있음 ex) 123입력 -> [49,50,51,52,\n] 5개 공간사용
	{
		sum += n[i] - '0'; // 각 배열 값에 아스키코드 '0' 즉 48을 빼면 원하는 값 이 나옴 ex) 1은 49('1')-48('0') = 1
	}

	return sum;
}
int an(int m)
{
	int sum = 0;

	while (m > 0)
	{
		sum += m % 10; // 끝자리 부터 합치기  1234 -> 0 -> 1
		m = m / 10; // 1234 -> 1 -> 0 ->끝
	}

	return sum;
}
