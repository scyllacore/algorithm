#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int* arr = new int[n + m];

	int i;
	for (i = 0; i < n + m; i++) {
		cin >> arr[i];
	}


	sort(arr, arr + n + m);


	for (i = 0; i < n + m; i++) {
		cout << arr[i] << ' ';
	}

	return 0;

}


