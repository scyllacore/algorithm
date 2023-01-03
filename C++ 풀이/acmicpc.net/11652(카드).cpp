#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	long long* arr = new long long[n];

	int i;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int cnt=1,ansCnt=1;
	long long ansNum=arr[0];

	for (i = 1; i < n; i++) {

		if (arr[i-1] == arr[i]) {
			cnt++;
		}
		else {
			if (cnt > ansCnt) {
				ansCnt = cnt;
				ansNum = arr[i - 1];
			}
			cnt = 1;
		}
	}

	if (cnt > ansCnt) {
		ansCnt = cnt;
		ansNum = arr[n-1];
	}
	cnt = 1;

	cout << ansNum;

}

