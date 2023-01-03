#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	vector<string> idxSearch(n);
	unordered_map<string, int> strSearch;

	int i;

	for (i = 0; i < n; i++) {
		cin >> idxSearch[i];
	}

	for (i = 0; i < n; i++) {
		strSearch.insert({ idxSearch[i],i + 1 });
	}

	string str;
	int idx;

	while ((m--) > 0) {

		cin >> str;

		if (isdigit(str[0])) {
			idx = atoi(str.c_str());
			cout << idxSearch[idx-1];
		}
		else {
			cout << strSearch[str];
		}

		cout << '\n';

	}

	return 0;
	
}

