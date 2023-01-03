#include <iostream>
#include <algorithm>

using namespace std;

#define MAX (int)(1e5+1)

struct bag {
	int w, v;
};

int dp[MAX] = { 0 };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	bag bagInfo[101];
	int i, j;

	for (i = 1; i <= n; i++) {
		cin >> bagInfo[i].w >> bagInfo[i].v;
	}

	for (i = 1; i <= n; i++) {
		/*for (j = bagInfo[i].w; j <= k; j++) {
			dp[j] = max(dp[j - bagInfo[i].w] + bagInfo[i].v, dp[j]);
		}*/

		for (j = k; j >= bagInfo[i].w; j--) {
			dp[j] = max(dp[j - bagInfo[i].w] + bagInfo[i].v, dp[j]);
		}
		// j >= bagInfo[i].w+1을 못하는 것은 자기 자신을 반영하기 위해서다. 


		/*for (j = 1; j <= k; j++) {
			cout << dp[j] << ' ';
		}

		cout << '\n';*/
	}

	cout << dp[k];

	return 0;
}


//2 10
//2 7
//7 9