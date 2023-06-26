#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int>& oven, int target, int start) {
	bool flag = 1;

	int low = start + 1, high = oven.size() - 1;
	int mid;

	for (; low < high;) {
		mid = (low + high) / 2;

		if (oven[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
			flag = 0;
		}
	}

	//cout << low << '\n';

	if (flag) {
		return -1;
	}

	return high;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int d, n;
	cin >> d >> n;

	vector<int> oven(d);

	for (int i = d - 1; i >= 0; i--) {
		cin >> oven[i];

		if (i != d - 1 && oven[i] > oven[i + 1]) {
			oven[i] = oven[i + 1];
		}
	}

	int pizza;
	int minHeight = -1;

	for (int i = 0; i < n; i++) {
		cin >> pizza;

		minHeight = binarySearch(oven, pizza, minHeight);

		if (minHeight == -1) {
			cout << 0;
			return 0;
		}
	}

	cout << d - minHeight;
	return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int>& oven, int target, int end) {
	bool flag = 1;

	int low = 0, high = end - 1;
	int mid;

	for (; low < high;) {
		mid = (low + high) / 2;

		if (target > oven[mid]) {
			high = mid;
		}
		else {
			low = mid + 1;
			flag = 0;
		}
	}

	//cout << low << '\n';

	if (flag) {
		return -1;
	}

	return high;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int d, n;
	cin >> d >> n;

	vector<int> oven(d);

	for (int i = 0; i < d; i++) {
		cin >> oven[i];

		if (i > 0 && oven[i] > oven[i - 1]) {
			oven[i] = oven[i - 1];
		}
	}

	int pizza;
	int high = d;

	for (int i = 0; i < n; i++) {
		cin >> pizza;

		high = binarySearch(oven, pizza, high);

		if (high == -1) {
			cout << 0;
			return 0;
		}
	}

	cout << high;
	return 0;
}
*/


/*
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int d, n;
	cin >> d >> n;

	int* oven = new int[d];

	for (int i = 0; i < d; i++) {
		cin >> oven[i];

		if (i > 0 && oven[i] > oven[i - 1]) {
			oven[i] = oven[i - 1];
		}
	}

	int* pizza = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> pizza[i];
	}

	int cnt = 0;

	for (int i = d - 1; i >= 0; i--) {
		if (pizza[cnt] <= oven[i]) {
			cnt++;
		}

		if (cnt == n) {
			cout << i + 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
*/

//내림차순일 때 binarySearch 하는 것 생각해볼 것.