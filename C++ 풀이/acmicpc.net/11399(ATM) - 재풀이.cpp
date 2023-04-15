#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> atmTime(n);

	for (int i = 0; i < n; i++) {
		cin >> atmTime[i];
	}

	sort(atmTime.begin(), atmTime.end());

	for (int i = 1; i < n; i++) {
		atmTime[i] += atmTime[i - 1];
	}

	cout << accumulate(atmTime.begin(), atmTime.end(), 0);
	return 0;
}