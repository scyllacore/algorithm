#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i;
	cin >> n;

	vector<int> arr(n);

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int m,idx,num;

	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> num;

		if (binary_search(arr.begin(), arr.end(), num)) {
			cout << 1;
		}
		else {
			cout << 0;
		}

		cout << '\n';

	}


}