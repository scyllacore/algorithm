#include <stdio.h>


void math1(int num) {


	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j <= i; j++) {

			printf("%c", '*');

		}
		printf("\n");
	

	}

	for (int i = num / 2+1; i < num; i++) {

		for (int j = 0; j < num-i; j++) { // 1

			printf("%c", '*');

		}
		printf("\n");

	}

}

void math2(int num) {

	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j < num / 2 - i; j++) 
			printf("%c", ' ');

		for (int j = 0; j <= i; j++) 
			printf("%c", '*');
		
		printf("\n");

	}


	for (int i = num / 2 + 1; i < num; i++) {

		for (int j = 0; j < i- num / 2; j++)
			printf("%c", ' ');


		for (int j = 0; j < num - i; j++)  
			printf("%c", '*');

		printf("\n");

	}

}

void  math3(int num) {


	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j < i; j++)
			printf("%c", ' ');

		for (int j = 0; j < num - i*2; j++) 
			printf("%c", '*');

		printf("\n");

	}


	for (int i = num / 2 + 1; i < num; i++) {

		for (int j = 0; j < num-i-1; j++) // 1
			printf("%c", ' ');
			
		for (int j = 0; j <= 2*(i - num / 2); j++)
			printf("%c", '*');

		printf("\n");


	}

}

void math4(int num) {

	for (int i = 0; i < num / 2 + 1; i++) {

		for (int j = 0; j < i; j++)
			printf("%c", ' ');

		for (int j = 0; j <= num/2 - i; j++)
			printf("%c", '*');


		printf("\n");
	}


	for (int i = num / 2 + 1; i < num; i++) {

		for (int j = 0; j < num / 2; j++) // 1
			printf("%c", ' ');

		for (int j = 0; j <= i - num / 2; j++)
			printf("%c", '*');

		printf("\n");
	}

}

int main() {

	int n, m;

	scanf("%d %d", &n, &m);

	if (n < 0 || n % 2 == 0 || n >= 100 || m < 1 || m>4) {

		printf("INPUT ERROR!");

		return 0;

	}


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


}