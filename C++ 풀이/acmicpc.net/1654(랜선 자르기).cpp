#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int k, n, i;
	
	cin >> k >> n;

	int* arr = new int[k];

	for (i = 0; i < k; i++) {
		cin >> arr[i];
	}

	long long low = 1, high = *max_element(arr, arr + k), mid;// low랑 high를 더하면 int자료형을 벗어날 수 있다.
	int cntLan,ans=0;

	for (; low <= high;) {

		cntLan = 0;
		mid = (low + high) / 2;

		for (i = 0; i < k; i++) {
			cntLan += arr[i]/mid;
		}

		if (n <= cntLan) {
			low = mid + 1;
			if (mid > ans) { ans = mid; }
		}
		else {
			high = mid - 1;
		}

	}

	cout << ans;

	delete[] arr;
	return 0;



}
