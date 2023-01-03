#include <stdio.h>

int a, b;
void count(int day);
void answer(int k);
int main(void)
{
	int day, k; //day=할머니가 넘어온 날, k=그날 호랑이에게 준 떡의 개수 
	scanf("%d %d", &day, &k);

	count(day);
	answer(k);

	return 0;
}
void count(int day)
{
	int i, arr[30][2];
	arr[0][0] = 1,arr[0][1] = 0;// day1
	arr[1][0] = 0,arr[1][1] = 1;// day2
	

	for (i = 2; i < day; i++)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}
	a = arr[day - 1][0];//a = arr[day - 2][1];
	b = arr[day - 1][1];
}
void answer(int k)
{
	int i, j, result;

	for (i = 1; ; i++)
	{
		for (j = i; ; j++)
		{
			result = (i * a) + (j * b);
			if (result >= k)
				break;
		}
		if (result == k)
			break;
	}
	printf("%d\n%d", i, j);
}
