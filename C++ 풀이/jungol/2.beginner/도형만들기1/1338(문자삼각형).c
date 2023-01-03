#include <stdio.h>



int main()

{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);



	int arr[100][100];
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			arr[i][j] = 0;



	int x = 0, y = 0;
	int num = 0;


	for (int i = 0; i < n; i++) {
		x = i; y = n - 1;
		for (int j = 0; j < n - i; j++) {
			arr[x++][y--] = ++num;
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) printf("%c\t", (arr[i][j] - 1) % 26 + 65);
			else printf("\t");
		}
		printf("\n");
	}



	return 0;

}