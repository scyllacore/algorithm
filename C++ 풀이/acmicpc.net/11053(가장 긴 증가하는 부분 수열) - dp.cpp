#include <iostream>
#include <vector>
#define max(a,b) a>b?a:b

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j, ans = 1;
	cin >> n;

	int* arr = new int[n + 1];
	int* dp = new int[n + 1];
	

	//vector<int> dp;

	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}


	for (i = 2; i <= n; i++)
	{
		for (j = i-1; j >=1; j--) // for (j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}

		ans = max(ans, dp[i]);

	}

	cout << ans;


}

//8 9 17 10 2 15 16 