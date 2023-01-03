#include <stdio.h>
#include <stdlib.h>
#define A  65
#define Z  90

int main()
{
	int num;
	int start = A;
	int array[303][303] = { 0, };
	int i, j;
	int x, y = -1;
	scanf("%d", &num);
	int m = num;
	x = num;


	for (; m > 0;)
	{

		//왼쪽 아래 
		for (i = 0; i < m; ++i)
		{
			if (start > Z)
			{
				start = A;
			}
			array[++y][--x] = start++; // index기준 3을 입력하면 0,2로 시작
		}  // 02 ,11 ,20 3회 반복
		   
		m--; // m을 줄여줘서 오른쪽 아래 2회 반복

		//오른쪽 아래 
		for (i = 0; i < m; ++i)
		{
			if (start > Z)
			{
				start = A;
			}
			array[++y][++x] = start++;
		}

		//오른쪽 위 
		for (i = 0; i < m; ++i)
		{
			if (start > Z)
			{
				start = A;
			}
			array[--y][++x] = start++;
		}

		m--;
		//왼쪽   위 
		for (i = 0; i < m; ++i)
		{
			if (start > Z)
			{
				start = A;
			}
			array[--y][--x] = start++;
		}

		y--;
		m++;     // 일반적인 문자달팽이와 달리 한바뀌돌고나면 증가되는 상황 발생 
	}

	for (i = 0; i <= num * 2; i++)
	{
		for (j = 0; j <= num * 2; j++)
		{
			if (array[i][j] == 0)
			{
				printf("  ");
			}
			else
			{
				printf("%c ", array[i][j]);

			}
		}
		printf("\n");
	}

}