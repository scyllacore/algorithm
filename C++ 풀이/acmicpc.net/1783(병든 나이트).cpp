#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	if (n == 1) {
		cout << 1;
	}
	else if (n == 2) {
		cout << min((m + 1) / 2, 4);
	}
	else if (m < 7) {
		cout << min(m, 4);
	}
	else {
		cout << m - 7 + 5;
	}

	return 0;
}