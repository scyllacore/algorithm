#include <iostream>
#include <vector>
#define max(a,b) a>b?a:b

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j,maxDp=0,maxIdx=0;
	cin >> n;

	int* arr = new int[n + 1];
	int* dp = new int[n + 1];
	vector<int> dpVal;

	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}


	for (i = 1; i <= n; i++)
	{
		for (j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		if (maxDp < dp[i])
		{
			maxDp = dp[i];
			maxIdx = i;
		}

	}

	for(i=maxIdx; i>=1; i--){
		if (maxDp == dp[i]) {
			dpVal.push_back(arr[i]);
			maxDp--;
		}
	}

	int size = dpVal.size();

	cout << size << '\n';

	for (i = size - 1; i >= 0; i--) {
		cout << dpVal[i] << ' ';
	}

	delete[] arr;
	delete[] dp;
	return 0;

}