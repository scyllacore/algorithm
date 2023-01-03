#include <stdio.h>

void first(int a);
void second(int b);
void third(int c);

int i, j;
int cnt = 1;
int arr[100][100];

int main() {

	int n = 0, m = 0;

	scanf("%d %d", &n, &m);

		while (m > 3 || m < 1) {
			printf("오류\n");
			scanf("%d %d", &n, &m);
	}
	

	if (m == 1) {
		first(n);
	}
	else if (m == 2) {
		second(n);
	}
	else {
		third(n);
	}


	return 0;
}

void first(int a) {

	for (int i = 0; i < a; i++) 
		for (int j = 0; j < a; j++) 
			arr[i][j] = i + 1;


		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}

	}

		

void second(int b) {

	int num = 1;

	for (i = 0; i < b; i++) { // 정방향
		if (i % 2 == 0) {
			for (j = 0; j < b; j++) {
				arr[i][j] = num++;
			}
		}
		else { // 역방향
			for (j = 0; j <b; j++) {
				arr[i][j] = (num--)-1;
			}
		}
	}
	for (i = 0; i < b; i++) {
		for (j = 0; j < b; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}
 

void third(int c) {

	for (int i = 0; i < c; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] = (i+1) * (j+1);


	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}