#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int* arr = new int[n];

	int i;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(&arr[0], &arr[n]);

	for (i = 1; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i];
	}

	cout << accumulate(&arr[0], &arr[n], 0);
	
}