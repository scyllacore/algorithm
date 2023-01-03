#include <stdio.h>


int main() {
  
	int flag = 1;
	int i, j,x=0,y=0,cnt=1;
	int n;

	scanf("%d", &n);

	int** arr = malloc(sizeof(int*) * n);

	for(i=0; i<n; i++)
		arr[i] = malloc(sizeof(int) * n);


	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			arr[y][x] = cnt++;
			y += 1 * flag;
			x += -1 * flag;
		}
		flag *= -1;

		if (i % 2 == 0)	x++;
		else y++;

	}

	if (n % 2 == 0) { x -= 1; y += 1; }
	else {	x += 1;	y -= 1;}

	for (i = n-1; i >0; i--)
	{
		for (j = 0; j < i; j++)
		{
			arr[y][x] = cnt++;
			y += 1 * flag;
			x += -1 * flag;
		}
		flag *= -1;

		if (i % 2 == 0) { y += 2; x -= 1; }
		else { x += 2; y -= 1; };

	}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
}