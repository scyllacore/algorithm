#include <iostream>

using namespace std;

#define MAX (int)2e6

bool visitedNumber[MAX + 1] = { 0 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int arr[20];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int bitCase = 1; bitCase < (1 << n); bitCase++) {

		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (bitCase & (1 << i)) {
				sum += arr[i];
			}
		}

		visitedNumber[sum] = 1;
	}


	for (int i = 1; i <= MAX; i++) {
		if (!visitedNumber[i]) {
			cout << i;
			return 0;
		}
	}

}