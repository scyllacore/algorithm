#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int e, s, m;
	cin >> e >> s >> m;

	int cnt;

	for (cnt = 0; ; cnt++) {
		if ((cnt % 15) + 1 == e && (cnt % 28) + 1 == s && (cnt % 19) + 1 == m) {
			break;
		}
	}

	cout << cnt + 1;

}
