#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	if (!(n >= m + k - 1 && n <= m * k)) { // 조건1. 최장 연속 증가 및 감소에 따른 조건. 조건2. 비둘기집 원리에 의한 조건
		cout << -1;
		return 0;
	}

	vector<int> sequence(1, 0);

	for (int i = 1; i <= n; i++) {
		sequence.push_back(i);
	}

	vector<int> rangeV;

	//가장 긴 감소 부분 수열 처리. 첫번째 그룹에 해당한다.
	rangeV.push_back(0);
	rangeV.push_back(k);
	n -= k;
	m -= 1;// 숫자 개수가 k개인 첫번째 그룹 반영. k개의 숫자와 그룹 1개를 사용.

	//가장 긴 증가 부분 수열 처리. 첫번째 그룹을 처리한 후 남은 그룹에 해당한다.
	int groupSize = m == 0 ? 0 : n / m; // 남은 숫자 / 만들어야 하는 그룹 수 = 그룹 하나에 들어가야하는 숫자 개수
	int r = m == 0 ? 0 : n % m; //숫자 한개를 추가로 넣어줘야하는 그룹의 수 계산

	for (int i = 0; i < m; i++) {
		rangeV.push_back(rangeV.back() + groupSize + (r > 0 ? 1 : 0));
		if (r > 0) {
			r--;
		}
	}

	int start, end = rangeV[0];

	for (int i = 1; i < rangeV.size(); i++) {
		start = end + 1;
		end = rangeV[i];

		for (int j = end; j >= start; j--) {
			cout << sequence[j] << ' ';
		}
	}

	return 0;
}
//https://hongjw1938.tistory.com/191