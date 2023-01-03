#include <stdio.h>

int main()
{
	double x;
	double *p, **p2, ***p3;

	p = &x;
	p2 = &p;
	p3 = &p2;

	scanf("%lf",(*(*p3)));
	
	printf("%.2lf", *(*(*p3)));
	


}