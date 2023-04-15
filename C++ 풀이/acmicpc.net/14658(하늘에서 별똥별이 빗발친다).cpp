#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int y, x;
};

int getCrush(int& y, int& x, int& l, vector<pos>& star) {

	int crush = 0;

	for (int i = 0; i < star.size(); i++) {
		if (star[i].y < y || star[i].y > y + l || star[i].x < x || star[i].x > x + l) {
			crush++;
		}
	}

	return crush;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, l, k;

	cin >> n >> m >> l >> k;

	int y, x;
	vector<pos> star;

	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		star.push_back({ y,x });
	}

	int ans = 100;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			ans = min(getCrush(star[i].y, star[j].x, l, star), ans);
		}
	}

	cout << ans;

	return 0;
}