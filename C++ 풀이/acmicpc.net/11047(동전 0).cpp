#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int* arr = new int[n];
	int i;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int j, coinCnt = 0;

	for (i = n - 1; i >= 0; i--) {
		for (; k >= arr[i];) {
			k -= arr[i];
			coinCnt++;
		}
	}

	cout << coinCnt;
}
