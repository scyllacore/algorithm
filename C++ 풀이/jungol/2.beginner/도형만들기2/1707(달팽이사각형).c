#include <stdio.h>

int main()
{

	int arr[100][100] = { NULL };
	int i, check;
	int s;
	int x = 0;
	int y = -1;
	int flag = 1;
	int cnt = 1;
	scanf("%d", &s);
	check = s;

	while (check > 0)
	{
		for (i = 0; i < check; i++)
		{
			y += flag;
			arr[x][y] = cnt++;

		}
		check--;


		for (i = 0; i < check; i++)
		{
			x += flag;
			arr[x][y] = cnt++;
		}
		flag *= -1;
	}



	for (x = 0; x < s; x++)
	{
		for (y = 0; y < s; y++)
		{
			printf("%3d ", arr[x][y]);
		}
		printf("\n");
	}

	return 0;

}