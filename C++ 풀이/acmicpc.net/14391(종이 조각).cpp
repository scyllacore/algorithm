#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	int n, m, maxVal = 0;
	int paper[4][4];

	scanf("%d %d", &n, &m);

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &paper[i][j]);
		}
	}

	int loop;

	for (loop = 0; loop < (1 << n * m); loop++) {

		int total = 0;

		for (i = 0; i < n; i++) {
			int sum = 0;
			for (j = 0; j < m; j++) {
				int k = i * m + j;
				if (loop & (1 << k)) {
					sum = sum * 10 + paper[i][j];
				}
				else {
					total += sum;
					sum = 0;
				}

			}
			total += sum;
		}

		for (j = 0; j < m; j++) {
			int sum = 0;
			for (i = 0; i < n; i++) {
				int k = i * m + j;
				if (!(loop & (1 << k))) {
					sum = sum * 10 + paper[i][j];
				}
				else {
					total += sum;
					sum = 0;
				}

			}
			total += sum;
		}

		maxVal = max(total, maxVal);
	}

	printf("%d", maxVal);

	return 0;

}