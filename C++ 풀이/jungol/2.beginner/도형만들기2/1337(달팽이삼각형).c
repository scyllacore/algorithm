#include <stdio.h>
#define BLANK 100
#define BOUNDARY -1



int main() {
	int n;
	//printf("Enter triangle height n: ");
	scanf("%d", &n);


	int arr[100][100];
	int tot_num = 0;


	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)

			arr[i][j] = BOUNDARY;



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			arr[i][j] = BLANK;
			tot_num++;
		}
	}


	int loopidx = 0;
	int x = 0, y = 0;
	int num = 0;

	arr[x][y] = num;

	for( ; loopidx < tot_num / 2; )
	{
		for(;arr[x + 1][y + 1] == BLANK;)
		{
			x++; y++;
			arr[x][y] = (++num) % 10; //대각선
		}

		for ( ; arr[x][y - 1] == BLANK; ) {
			y--;
			arr[x][y] = (++num) % 10; // 아래로
		}

		for ( ; arr[x - 1][y] == BLANK; ) {
			x--;
			arr[x][y] = (++num) % 10; // 오른쪽으로
		}


		loopidx++;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == BOUNDARY) printf(" ");

			else if (arr[i][j] != BLANK) printf("%d ", arr[i][j]);

			else printf("\t");

		}
		printf("\n");
	}

	return 0;

}