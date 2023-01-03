#include<stdio.h>
int main() {
	int i, j, m, n, msrnum = 0, sum = 0,min = 0, min_flag = 0;
	scanf("%d %d", &m, &n);

	if (m == 1) m = 2;

	for (i = m; i <= n; i++) {
		for (j = 2; j <= i/j; j++) {
			if (i % j == 0) {
				msrnum = 1;
				break;
			}
		}

		if (msrnum == 0) {
			sum += i;
			if (min_flag == 0) {
				min = i;
				min_flag = 1;
			}
		}

		msrnum = 0;
	}
	if (min_flag == 0) {
		printf("-1");
		return 0;
	}
	printf("%d\n%d", sum, min);
}