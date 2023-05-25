#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int answer = 0;

	for (int i = n - 1; i >= 0; i--) {
		int coinVal = coin[i];

		for (; k - coinVal >= 0;) {
			k -= coinVal;
			answer++;
		}
	}

	cout << answer;
	return 0;
}