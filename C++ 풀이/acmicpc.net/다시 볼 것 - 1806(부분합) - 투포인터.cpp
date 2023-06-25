#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, s;

	cin >> n >> s;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int low, high;
	low = high = 0;

	int sum = arr[0];
	int len = n + 1;

	for (; low <= high && high < n;) {
		if (sum < s) {
			sum += arr[++high];
		}
		else {
			len = min(high - low + 1, len);
			sum -= arr[low++];
		}
	}

	if (len == n + 1) {
		cout << 0;
	}
	else {
		cout << len;
	}

	return 0;
}