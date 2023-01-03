#include <iostream>

using namespace std;


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, s;
	int arr[21];

	cin >> n >> s;

	int i, j, cnt = 0;;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (i = 1; i < (1 << n); i++) {

		int sum = 0;

		for (j = 0; j < n; j++) {

			if(i&(1<<j)){
				sum += arr[j+1];
			}
		}

		if (sum == s) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;



}