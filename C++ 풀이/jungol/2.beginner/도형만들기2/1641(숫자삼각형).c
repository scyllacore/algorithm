#include <stdio.h>



int main()

{

	int n, m;

	printf("Enter triangle height n and type m: ");

	scanf("%d %d", &n, &m);



	if ((n < 0) || (n > 100) || (n % 2 == 0)) {

		printf("INPUT ERROR!\n");

		return -1;

	}



	if ((m < 1) || (m > 3)) {

		printf("INPUT ERROR!\n");

		return -1;

	}



	int arr[100][100];

	for (int i = 0; i < 100; i++)

		for (int j = 0; j < 100; j++)

			arr[i][j] = -1;

	int num = 0;



	switch (m) {

	case 1:

		for (int i = 0; i < n; i++) {

			if (i % 2 != 0) { // i is odd number

				for (int j = i; j >= 0; j--) {

					arr[i][j] = ++num;

				}

			}

			else {

				for (int j = 0; j <= i; j++) {

					arr[i][j] = ++num;

				}

			}

		}

		break;

	case 2:

		for (int i = 0; i < n; i++) {

			arr[i][n - 1] = i;

			for (int j = 1; j < n - i; j++) {

				arr[i][n - 1 + j] = i;

				arr[i][n - 1 - j] = i;

			}

		}

		break;

	case 3:

		for (int i = 0; i < n / 2 + 1; i++) {

			num = 0;

			for (int j = 0; j < i + 1; j++) {

				arr[i][j] = ++num;

			}

		}



		for (int i = n / 2 + 1; i < n; i++) {

			num = 0;

			for (int j = 0; j < n - i; j++) {

				arr[i][j] = ++num;

			}

		}

		break;

	default:

		break;

	}



	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 2 * n; j++) {

			if (arr[i][j] != -1) printf("%d ", arr[i][j]);

			else printf("  ");

		}

		printf("\n");

	}



	return 0;

}