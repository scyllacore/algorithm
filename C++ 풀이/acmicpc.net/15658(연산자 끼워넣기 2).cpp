#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int* arr;
int operCnt[4];
int minAns = INT_MAX, maxAns = INT_MIN;

void DFS(int idx, int sum) {

	if (idx >= n) {
		minAns = min(sum, minAns);
		maxAns = max(sum, maxAns);

		return;
	}

	if (operCnt[0]) {
		operCnt[0]--;
		DFS(idx + 1, sum + arr[idx]);
		operCnt[0]++;
	}

	if (operCnt[1]) {
		operCnt[1]--;
		DFS(idx + 1, sum - arr[idx]);
		operCnt[1]++;

	}

	if (operCnt[2]) {
		operCnt[2]--;
		DFS(idx + 1, sum * arr[idx]);
		operCnt[2]++;
	}

	if (operCnt[3]) {
		operCnt[3]--;
		DFS(idx + 1, sum / arr[idx]);
		operCnt[3]++;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	arr = new int[n];

	int i;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (i = 0; i < 4; i++) {
		cin >> operCnt[i];
	}

	DFS(1, arr[0]);

	cout << maxAns << '\n' << minAns;

	return 0;

}
