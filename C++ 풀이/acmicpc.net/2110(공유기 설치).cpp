#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;

	vector<int> house;
	int housePos;
	int i;

	for (i = 0; i < n; i++) {
		cin >> housePos;
		house.push_back(housePos);
	}
	
	sort(house.begin(), house.end());

	int low = 1, high = house[n - 1]-house[0], mid;
	int gap, housePre,wifiCnt;
	int ans = 1;

	while (low <= high) {

		mid = (low + high) / 2;
		wifiCnt = 1;
		housePre = house[0];

		for (i = 1; i < n; i++) {
			gap = house[i] - housePre;
			if (gap >= mid) {
				wifiCnt++;
				housePre = house[i];
			}
		}

		if (wifiCnt >= c) {
			ans = max(mid, ans);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}

	cout << ans;
}