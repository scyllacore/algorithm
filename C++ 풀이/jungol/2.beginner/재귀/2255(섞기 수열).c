#include <stdio.h>
#include <stdbool.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}


int Shuffle();

// 속도를 조금이라도 올리기 위해 전역으로 선언
int n;    // 정수의 개수(1~20,000)
int arr[20000];
bool checked[20000];

int main(void)
{
	scanf("%d", &n);

	// n개의 자연수 입력
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	printf("%d", Shuffle());
}

int Shuffle()
{
	int result = 1;
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0; // 현재 섞기 회수
		int startNum = i + 1;
		int curNum = startNum;
		if (startNum == arr[startNum - 1])    // 안 움직이는 놈은 안건듬
			continue;
		if (checked[i])    // 한번 확인한 루트는 더 이상 안돔
			continue;
		while (true)
		{
			++cnt;
			checked[curNum - 1] = true;    // 확인 체크
			curNum = arr[curNum - 1];
			if (startNum == curNum)    // 처음으로 돌아온 경우 종료
				break;
		}
		result = lcm(result, cnt);    // 최소 공배수 구하기
	}
	return result;
}
