#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string n;
	cin >> n;

	sort(n.begin(), n.end(), greater<>());

	if (n.back() != '0') {
		cout << -1;
	}
	else {
		long long sum = 0;

		for (char ch : n) {
			sum += ch - '0';
		}

		if (sum % 3 == 0) {
			cout << n;
		}
		else {
			cout << -1;
		}
	}

	return 0;
}

//https://ladyang86.tistory.com/57

/*
#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string n;
	cin >> n;

	int numCnt[10] = { 0 };

	int len = n.length();

	for (int i = 0; i < len; i++) {
		numCnt[n[i] - '0']++;
	}

	string ans = "";

	for (int i = 9; i >= 0; i--) {
		if (numCnt[i] > 0) {
			for (int j = i; j >= 0; j -= 3) {
				for (; numCnt[j] > 0;) {
					numCnt[j]--;
					ans += to_string(j);
				}
			}
		}
	}

	if (n.length() == ans.length()) {
		cout << ans;
	}
	else {
		cout << -1;
	}
	return 0;
}
*/