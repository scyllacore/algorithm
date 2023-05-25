#include <cstdio> // **iostream�� scanf�� ���̾��� �ȵȴ�.
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int>> paper(n, vector<int>(m));

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &paper[i][j]);
		}
	}

	int answer = 0;

	for (int bitCase = 0; bitCase < (1 << n * m); bitCase++) {

		int total = 0;
		int sum = 0;

		for (i = 0; i < n; i++) {
			sum = 0;
			for (j = 0; j < m; j++) {
				int idx = i * m + j;
				if (bitCase & (1 << idx)) {
					sum = sum * 10 + paper[i][j];
				}
				else {
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}
		//total += sum; �̰��� �ƴϴ�

		for (j = 0; j < m; j++) {
			sum = 0;
			for (i = 0; i < n; i++) {
				int idx = i * m + j;
				if (!(bitCase & (1 << idx))) {
					sum = sum * 10 + paper[i][j];
				}
				else {
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}

		answer = max(total, answer);
	}

	printf("%d", answer);
	return 0;

}