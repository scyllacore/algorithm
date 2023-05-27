#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int operCnt[4] = { 0 };

int maxVal = -(int)1e10;
int minVal = (int)1e10;

vector<int> arr;

void calNum(int val, int idx) {
	if (idx >= arr.size()) {
		maxVal = max(val, maxVal);
		minVal = min(val, minVal);
		return;
	}

	if (operCnt[0] > 0) {
		operCnt[0]--;
		calNum(val + arr[idx], idx + 1);
		operCnt[0]++;
	}

	if (operCnt[1] > 0) {
		operCnt[1]--;
		calNum(val - arr[idx], idx + 1);
		operCnt[1]++;
	}

	if (operCnt[2] > 0) {
		operCnt[2]--;
		calNum(val * arr[idx], idx + 1);
		operCnt[2]++;
	}

	if (operCnt[3] > 0) {
		operCnt[3]--;
		calNum(val / arr[idx], idx + 1);
		operCnt[3]++;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> operCnt[i];
	}

	calNum(arr[0], 1);

	cout << maxVal << '\n';
	cout << minVal;


	return 0;
}