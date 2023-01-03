#include <iostream>

using namespace std;

int arr[1025][1025] = { {0} };

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	
	

	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 2; j <= n; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 2; j <= n; j++) {
			arr[j][i] += arr[j-1][i];
		}
	}

	
	int x1, y1, x2, y2;

	for (; m--;) {
		cin >> y1 >> x1 >> y2 >> x2;	
		cout << arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1] << '\n';
	}
	

	return 0;


}