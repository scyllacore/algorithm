#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, i;
	cin >> n >> m;

	int* treeN = new int[n];

	for (i = 0; i < n; i++) {
		cin >> treeN[i];
	}

	long long low = 0, high = *max_element(treeN, treeN + n), mid;
	long long cutTree; // 잘려나온 길이를 합치면 int 자료형을 벗어날 수 있다
	int ans = 0;

	while (low <= high) {

		mid = (low + high) / 2;

		cutTree = 0;

		for (i = 0; i < n; i++) {
			cutTree += (treeN[i] - mid > 0 ? treeN[i] - mid : 0);//10-15 = -5 나옴으로 이때 음수 값들은 0으로 만들어야함.
		}

		//cout << cutTree << ' ' << mid <<'\n';

		if (cutTree >= m) {
			if (mid > ans) { ans = mid; } // 이거 먼저 쓰도록
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;
	delete[] treeN;
	return 0;

}