#include "1719.h"


int main()
{
	int n, m;
	printf("Enter triangle hight n and type m: ");
	scanf("%d %d", &n, &m);

	if (n > 100) {
		printf("n must be less than 100\n");
		return -1;
	}

	if (n % 2 == 0) {
		printf("n must be odd number\n");
		return -1;
	}

	if ((m <= 0) || (m > 4)) {
		printf("m must be 1, 2, 3, or 4\n");
		return -1;
	}


	printstar(n, m);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 2 * n + 1; j++) {

			if (arr[i][j] == 1) printf("*");

			else printf(" ");

		}

		printf("\n");

	}


	system("pause>nul");

	return 0;

}