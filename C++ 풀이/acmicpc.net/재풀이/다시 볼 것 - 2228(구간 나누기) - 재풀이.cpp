#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MINF -(int)1e9 

int useiDp[101][101];
int notUseiDp[101][101];
int arr[101];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int i, j;

	for (i = 0; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			useiDp[i][j] = notUseiDp[i][j] = MINF;
		}
	}

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= min(m, ((i + 1) / 2)); j++) {
			notUseiDp[i][j] = max(useiDp[i - 1][j], notUseiDp[i - 1][j]);
			useiDp[i][j] = max(useiDp[i - 1][j], notUseiDp[i - 1][j - 1]) + arr[i];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cout << notUseiDp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';


	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cout << useiDp[i][j] << ' ';
		}
		cout << '\n';
	}



	cout << max(notUseiDp[n][m], useiDp[n][m]);

	return 0;

}

/*
#include <iostream>

using namespace std;

int n, m;
bool visit[102][52];
int dp[102][52];
int sum[102];

int areaSum(int num, int area)
{
	if(area == 0) return 0;
	if(num < 2*area-1) return -987654321;
	if(visit[num][area]) return dp[num][area];

	visit[num][area] = true;
	dp[num][area] = areaSum(num-1, area);

	for(int i = num; i >= 1; i--)
	{
		dp[num][area] = max(dp[num][area], sum[num] - sum[i-1] + areaSum(i-2, area-1));
	}

	return dp[num][area];
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int seq;
	for(int i = 1; i <= n; i++)
	{
		cin >> seq;
		sum[i] = sum[i-1] + seq;
	}

	cout << areaSum(n, m);

	return 0;
}
*/

//https://stillchobo.tistory.com/107
//https://ddiyeon.tistory.com/62
//https://kariskan.tistory.com/121