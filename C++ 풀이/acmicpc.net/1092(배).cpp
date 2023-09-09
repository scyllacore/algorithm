#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> crain(n);

	for (int i = 0; i < n; i++) {
		cin >> crain[i];
	}

	int m;
	cin >> m;

	vector<int> box(m);

	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}

	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	int ans = 0;

	for (;;) {

		int moveCount = 0;

		for (int i = 0; i < n; i++) {

			if (box.empty()) {
				break;
			}

			int idx = lower_bound(box.begin(), box.end(), crain[i]) - box.begin();

			if (idx >= box.size()) {
				moveCount++;
				box.pop_back();
			}
			else if (box[idx] == crain[i]) {
				moveCount++;
				box.erase(box.begin() + idx);
			}
			else if (idx >= 1) {
				moveCount++;
				box.erase(box.begin() + idx - 1);
			}

		}

		if (moveCount == 0) {
			break;
		}

		ans++;
	}

	if (box.empty()) {
		cout << ans;
	}
	else {
		cout << -1;
	}

	return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> crain(n);

	for (int i = 0; i < n; i++) {
		cin >> crain[i];
	}

	int m;
	cin >> m;

	vector<int> box(m);

	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}

	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	int ans = 0;

	for (; !box.empty();) {

		int crainSize = n;

		for (int i = 0; i < n && !box.empty(); i++) {
			int idx = lower_bound(box.begin(), box.end(), crain[i]) - box.begin();

			cout << idx << '\n';

			1.
			if (idx >= crain.size()) {
				crainSize--;
				box.pop_back();
			}
			else if (idx < crain.size() && box[idx] <= crain[i]) {
				crainSize--;
				box.erase(box.begin() + idx);
			}

			2.
			if (idx >= box.size()) {
				moveCount++;
				box.pop_back();
			}
			else if (box[idx] > crain[i] && idx >= 1) { // crain이 box의 제일 앞에 배치된 경우, 해당 crain이 제일 앞 위치의 박스를 옮길 수 있는지 고려해야한다.
				moveCount++;
				box.erase(box.begin() + idx - 1);
			}
			else if (box[idx] <= crain[i]) {
				moveCount++;
				box.erase(box.begin() + idx);
			}

			for (int j = 0; j < box.size(); j++) {
				cout << box[j] << ' ';
			}
			cout << '\n';

			for (int j = 0; j < box.size(); j++) {
				cout << box[j] << ' ';
			}
			cout << '\n';

		}

		if (crainSize == 0 || box.empty()) {
			ans++;
		}
		else {
			ans = -1;
			break;
		}

	}

	cout << ans;

	return 0;
}
*/
