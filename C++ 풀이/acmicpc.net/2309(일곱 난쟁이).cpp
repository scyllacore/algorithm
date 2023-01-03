#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i,j,k,sum=0;
	int arr[9];

	for (i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);


	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				for (k = 0; k < 9; k++) {
					if (i == k || j == k) continue;
					cout << arr[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;

}