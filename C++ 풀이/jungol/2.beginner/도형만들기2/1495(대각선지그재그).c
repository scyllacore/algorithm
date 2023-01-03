#include <stdio.h>
#define MAX 100

void pr(int n, int squ[][MAX]);
void square(int n, int squ[][MAX]);

int main(void)
{
	int n, squ[MAX][MAX] = { 0 };
	scanf("%d", &n);

	square(n, squ);
	pr(n, squ);
	return 0;
}
void pr(int n, int squ[][MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", squ[i][j]);
		printf("\n");
	}
}
void square(int n, int squ[][MAX])
{
	int x = 0, y = 0, a = 1, i, j, c = 1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < c; j++)
			squ[x--][y++] = a++; // 왼쪽 아래로 (1 4 5 6 9)

		x++; // 위 for문 연산 완료후 y=-1 이 되는 문제 해결

		if (i == n - 1) break; // 반복횟수가 입력 횟수와 같을 시 멈춤
		if (i >= n / 2) { x++; y--; c--; } // 중간 지점 일 때 감소 반복횟수 감소
		else c++; // 반복 횟수 1회 추가

		for (j = 0; j < c; j++)
			squ[x++][y--] = a++; //오른쪽 위로 (2 3 7 8)

		y++; // 위 for문 연산 완료후 x=-1 이 되는 문제 해결


		if (i >= n / 2) { x--; y++; c--; }
		else c++;
	}
}