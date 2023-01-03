#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	map<string, int> nameList;
	vector<string> interList;

	string name;

	while ((n--) > 0) {
		cin >> name;
		nameList.insert({ name,1 });
	}



	while ((m--) > 0) {
		cin >> name;

		auto iter = nameList.find(name);

		if (iter != nameList.end()) {
			interList.push_back(name);
		}
	}

	sort(interList.begin(), interList.end());

	int size = interList.size();
	cout << size << '\n';

	for (int i = 0; i < size; i++) {
		cout << interList[i] << '\n';
	}


}
