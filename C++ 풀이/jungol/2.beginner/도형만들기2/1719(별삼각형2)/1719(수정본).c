#include <stdio.h>
#include <stdlib.h>

int** arr;

void memalloc(int num) {

	arr = malloc(sizeof(int*) * num);

	for (int i = 0; i < num; i++) {

		arr[i] = malloc(sizeof(int) * num);

	}

	for (int i = 0; i < num; i++) {

		for (int j = 0; j < num; j++) {

			arr[i][j] = 32;

		}

	}

}


void fuc_print(int num) {

	for (int i = 0; i < num; i++) {

		for (int j = 0; j < num; j++) {

			printf("%c", arr[i][j]);

		}

		printf("\n");

	}

}

void math1(int num) {

	int cnt = 0;

	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j <= i; j++) {

			arr[i][cnt++] = 42;

		}

		cnt = 0;

	}

	for (int i = num / 2+1; i < num; i++) {

		for (int j = 0; j < num-i; j++) { // 1

			arr[i][cnt++] = 42;

		}

		cnt = 0;

	}

}

void math2(int num) {

	int cnt = num/2;

	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j <= i; j++) {

			arr[i][cnt--] = 42;

		}

		cnt = num / 2;

	}


	for (int i = num / 2 + 1; i < num; i++) {

		for (int j = 0; j < num - i; j++) { // 1

			arr[i][cnt--] = 42;

		}

		cnt = num / 2;

	}

}

void  math3(int num) {

	int cnt1 = num / 2, cnt2 = num / 2;

	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j <= num / 2 - i; j++) {

			arr[i][cnt1--] = 42;
			arr[i][cnt2++] = 42;

		}

		cnt1= cnt2 = num / 2;

	}


	for (int i = num / 2 + 1; i < num; i++) {

		for (int j = 0; j <= i - num / 2; j++) { // 1

			arr[i][cnt1--] = 42;
			arr[i][cnt2++] = 42;

		}

		cnt1 = cnt2 = num / 2;

	}

}

void math4(int num) {

	int cnt1 = num / 2, cnt2 = num / 2;

	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j <= num / 2 - i; j++) {

			arr[i][cnt1--] = 42;

		}

		cnt1 = cnt2 = num / 2;

	}


	for (int i = num / 2 + 1; i < num; i++) {

		for (int j = 0; j <= i - num / 2; j++) { // 1

			arr[i][cnt2++] = 42;

		}

		cnt1 = cnt2 = num / 2;

	}

}

int main() {

	int n, m;

	scanf("%d %d", &n, &m);

	if (n < 0 || n % 2 == 0 || n >= 100 || m < 1 || m>4) {

		printf("INPUT ERROR!");

		return 0;

	}

	memalloc(n);

	if (m == 1) {

		math1(n);

	}

	else if (m == 2) {

		math2(n);

	}

	else if (m == 3) {

		math3(n);

	}

	else if (m == 4) {

		math4(n);

	}

	fuc_print(n);

}