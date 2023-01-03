#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int gcd2(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n%d\n", gcd(a, b), a * b / gcd(a, b));
	//printf("%d\n%d\n", gcd2(a, b), a * b / gcd2(a, b));

	return 0;
}


//유클리드 호제법