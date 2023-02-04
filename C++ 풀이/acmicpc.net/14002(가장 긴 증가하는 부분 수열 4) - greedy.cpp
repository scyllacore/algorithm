#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, idx = 1, maxIdx = 1;
	cin >> n;

	int* arr = new int[n + 1];
	int* dpCnt = new int[n + 1];

	vector<int> dp, dpVal;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		dpCnt[i] = 1;
	}

	for (i = 1; i <= n; i++) {
		idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx + 1 > dp.size())
		{
			dp.push_back(arr[i]);
			maxIdx = i;
		}
		else {
			dp[idx] = arr[i];
		}

		dpCnt[i] = idx + 1;
	}

	int size = dp.size();

	cout << size << '\n';

	/*for (i = 1; i <= n; i++) {
		cout << dpCnt[i] << ' ';
	}*/

	for (i = maxIdx; i >= 1; i--) {
		if (size == dpCnt[i]) {
			dpVal.push_back(arr[i]);
			size--;
		}
	}

	for (i = dpVal.size() - 1; i >= 0; i--)
	{
		cout << dpVal[i] << ' ';
	}

	delete[] arr;
	delete[] dpCnt;

	return 0;


}