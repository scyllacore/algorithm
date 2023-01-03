#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n,i,idx=1;
	cin >> n;

	int* arr = new int[n + 1];
	vector<int> dp;

	for (i = 1; i <= n; i++){
		cin >> arr[i];
	}

	for (i = 1; i <= n; i++) {
		idx = lower_bound(dp.begin(), dp.end(), arr[i])- dp.begin();

		if (idx + 1 > dp.size())
		{
			dp.push_back(arr[i]);
		}
		else {
			dp[idx] = arr[i];
		}

	}

	cout << dp.size();

	delete[] arr;
	return 0;


}