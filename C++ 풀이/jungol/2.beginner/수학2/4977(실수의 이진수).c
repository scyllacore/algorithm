#include <stdio.h>

void changeIntPart(int n) {

	if (n <= 0) {
		return;
	}

	changeIntPart(n / 2);
	printf("%d", n % 2);
}

void changeDecPart(double n,int cnt) {

	if (cnt >= 4) {return;}

	double decBinary = n * 2;

	if (decBinary >= 1) { printf("1"), decBinary -= 1; }
	else{ printf("0"); }

	changeDecPart(decBinary,cnt+1);
}

int main() {

	double n;
	scanf("%lf", &n);

	int i;
	int intPart = (int)n;
	double decPart = n - intPart;

	changeIntPart(intPart);
	printf(".");
	changeDecPart(decPart,0);
	
}