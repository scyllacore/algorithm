#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector <vector<int>> arr(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			arr[j][i] += arr[j - 1][i];
		}
	}

	int y1, x1, y2, x2;

	for (int i = 0; i < m; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << arr[y2][x2] - arr[y2][x1 - 1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1] << '\n';
	}

	return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n * n + 1);

	arr[0] = 0;
	for (int i = 1; i <= n * n; i++) {
		cin >> arr[i];
	}

	for (int i = 2; i <= n * n; i++) {
		arr[i] += arr[i - 1];
	}

	int x1, y1, x2, y2;

	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		cout << arr[(x2 - 1) * n + y2] - arr[(x1 - 1) * n + y1 - 1] << '\n';
	}

}
*/