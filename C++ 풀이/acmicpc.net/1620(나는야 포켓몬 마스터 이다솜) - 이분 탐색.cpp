#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.first.compare(b.first) < 0;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	vector<string> idxSearch(n);
	vector<pair<string, int>> strSearch(n);

	int i;

	for (i = 0; i < n; i++) {
		cin >> idxSearch[i];
	}

	for (i = 0; i < n; i++) {
		strSearch[i].first = idxSearch[i];
		strSearch[i].second = i + 1;
	}

	sort(strSearch.begin(), strSearch.end(), compare);

	string str;
	int idx;

	while ((m--) > 0) {

		cin >> str;

		if (isdigit(str[0])) {
			idx = atoi(str.c_str());
			cout << idxSearch[idx - 1];
		}
		else {
			int low = 0, high = n - 1;

			while (low <= high) {

				int mid = (low + high) / 2;

				if (str == strSearch[mid].first) {
					cout << strSearch[mid].second;
					break;
				}
				else if (str < strSearch[mid].first) {
					high = mid - 1;
				}
				else if (str > strSearch[mid].first) {
					low = mid + 1;
				}
			}

		}

		cout << '\n';

	}

	return 0;

}

