// 다음 순열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool nextPermutation(vector<int>& arr) {
	int i, j;
	i = j = arr.size() - 1;

	for (; i >= 1 && arr[i - 1] >= arr[i]; i--) {}

	if (i <= 0) { // 오류 : i<=1로 씀. 3 4 2 1이 -1로 나옴
		return false;
	}

	for (; arr[i - 1] >= arr[j]; j--) {} // j>=1보다 큰 조건은 안써도 된다. 이 라인을 실행할 수 있다는 것은 i-1보다 큰 j값이 존재한다는 것이다, 

	swap(arr[i - 1], arr[j]);

	j = arr.size() - 1;

	for (; i < j;) {
		swap(arr[i], arr[j]);
		i++, j--;
	}

	return true;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (nextPermutation(arr)) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
	}
	else {
		cout << -1;
	}

	return 0;
}

//이전 순열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool nextPermutation(vector<int>& arr) {
	int i, j;
	i = j = arr.size() - 1;

	for (; i >= 1 && arr[i - 1] <= arr[i]; i--) {}

	if (i <= 0) {
		return false;
	}

	for (; arr[i - 1] <= arr[j]; j--) {}

	swap(arr[i - 1], arr[j]);

	j = arr.size() - 1;

	for (; i < j;) {
		swap(arr[i], arr[j]);
		i++, j--;
	}

	return true;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (nextPermutation(arr)) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
	}
	else {
		cout << -1;
	}

	return 0;
}