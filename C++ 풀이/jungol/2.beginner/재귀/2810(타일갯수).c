#include    <stdio.h>
int getGCD(int a, int b);

int main()
{
	int w, h;
	scanf("%d %d", &w, &h);

	int gcd = 0;
	if (w > h)
		gcd = getGCD(w, h);
	else
		gcd = getGCD(h, w);

	h /= gcd;
	w /= gcd;

	printf("%d", w * h);

}

int getGCD(int a, int b)
{
	if (a % b == 0) return b;
	return getGCD(b, a % b);
}