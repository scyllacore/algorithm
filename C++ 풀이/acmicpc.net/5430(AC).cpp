#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> arr;

string ac, arrStr;

int acCal() {

	int i;
	bool rev = 0;

	for (i = 0; i < ac.size(); i++) {
		if (ac[i] == 'R') {
			rev = !rev;
		}
		else if (ac[i] == 'D') {
			if (arr.empty()) {
				return 0;
			}
			if (rev == 0) {
				arr.pop_front();
			}
			else {
				arr.pop_back();
			}
		}
	}

	if (rev == 0) {
		return 1;
	}
	else {
		return 2;
	}

}

void print(int n) {

	switch (n) {
	case 1:
		cout << '[';
		if (!arr.empty()) {
			for (auto ptr = arr.begin(); ptr < arr.end() - 1; ptr++) {
				cout << *ptr << ',';
			}
			cout << arr.back();
		}
		cout << ']';
		break;
	case 2:
		cout << '[';
		if (!arr.empty()) {
			for (auto ptr = arr.end() - 1; ptr > arr.begin(); ptr--) {
				cout << *ptr << ',';
			}
			cout << arr.front();
		}
		cout << ']';
		break;
	default:
		cout << "error";
		break;
	}

	cout << '\n';

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;

	cin >> tc;

	int i, n, tmp;

	while ((tc--) > 0) {

		cin >> ac >> n >> arrStr;

		auto ptr = arrStr.begin() + 1;

		for (i = 0; i < n; i++) {

			tmp = 0;

			while (*ptr >= '0' && *ptr <= '9') {
				tmp = tmp * 10 + (*ptr - '0');
				ptr++;
			}

			arr.push_back(tmp);
			ptr++;
		}

		int res = acCal();
		print(res);

		arr.clear();

	}

	return 0;

}