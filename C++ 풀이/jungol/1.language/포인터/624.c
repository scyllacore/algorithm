#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,n;
	scanf("%d", &n);
	double* p = (double*)malloc(sizeof(double) * n);
	double hap = 0;

	for (i = 0; i < n; i++) {
		scanf("%lf", &p[i]);
		hap = hap + *(p + i);
	}

	for (i = 0; i < n; i++) {
		printf("%.2lf ", *(p + i));
	}
	printf("\r\n");



	printf("hap : %.2lf\r\n", hap);
	printf("avg : %.2lf ", hap / n);

	free(p);
	return 0;
}