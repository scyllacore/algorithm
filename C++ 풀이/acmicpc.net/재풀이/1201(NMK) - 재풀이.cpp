#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	if (!(n >= m + k - 1 && n <= m * k)) { // m*k+1 인 상황 -> 비둘기집의 원리
		cout << -1;
		return 0;
	}

	vector<int> sequence(1, 0);

	for (int i = 1; i <= n; i++) {
		sequence.push_back(i);
	}

	vector<int> rangeV;
	rangeV.push_back(0);
	rangeV.push_back(k);

	n -= k;
	m -= 1;

	int groupSize = n / (m > 0 ? m : 1);
	int r = n % (m > 0 ? m : 1);

	for (int i = 0; i < m; i++) {
		rangeV.push_back(rangeV.back() + groupSize + (r > 0 ? 1 : 0));
		if (r > 0) {
			r--;
		}
	}

	/*for (int i = 0; i < rangeV.size(); i++) {
		cout << rangeV[i] << ' ';
	}
	cout << '\n';*/

	int start, end = rangeV[0];

	for (int i = 1; i < rangeV.size(); i++) {
		start = end + 1;
		end = rangeV[i];

		for (int j = end; j >= start; j--) {
			cout << j << ' ';
		}
	}

	return 0;
}