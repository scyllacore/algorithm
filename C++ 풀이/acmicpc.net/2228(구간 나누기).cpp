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

	cout << max(notUseiDp[n][m], useiDp[n][m]);

	return 0;

}

