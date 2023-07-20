#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct numInfo {
	int count;
	int idx;
};

unordered_map<int, numInfo> numCount;

bool cmp(int a, int b) {
	if (numCount[a].count == numCount[b].count) {
		return numCount[a].idx < numCount[b].idx;
	}

	return numCount[a].count > numCount[b].count;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		numCount[arr[i]].count++;

		if (numCount[arr[i]].idx == 0) {
			numCount[arr[i]].idx = i + 1;
		}
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}