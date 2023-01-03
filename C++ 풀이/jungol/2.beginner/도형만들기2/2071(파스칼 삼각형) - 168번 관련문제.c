# include <stdio.h>

int main()
{
	int i, j, n, m;
	int arr[100][100] = { {0} };

	scanf("%d %d", &n, &m);

	arr[1][1] = 1;

	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	if (m == 1)
	{
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= i; j++) {
				{
					printf("%d ", arr[i][j]);
				}
			}
			printf("\n");
		}
	}

	else if (m == 2)
	{
		for (i = n ; i >= 0; i--)
		{
			for (j = 0; j < n - i ; j++)
			{
				printf(" ");
			}

			for (j = i; j >= 1; j--) // for (j = 1; j <= i; j++)
			{
				printf("%d ", arr[i][j]);
			}

			printf("\n");
		}
	}

	else if (m == 3)
	{
		for (i = n; i >=1 ; i--) // (i = 0; i < n; i++)
		{
			for (j = n; j >= i; j--) // j = n; j >= n - i; j--)
			{
				printf("%d ", arr[j][i]); // arr[j][n - i]
			}
			printf("\n");
		}


	}

	return 0;

}
