#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001] = { 0 };
vector<int> dp;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, idx = 1;
	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (i = 1; i <= n; i++) {
		idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

		if (idx + 1 > dp.size())
		{
			dp.push_back(arr[i]);
		}
		else {
			dp[idx] = arr[i];
		}

	}

	cout << dp.size();

	return 0;


}