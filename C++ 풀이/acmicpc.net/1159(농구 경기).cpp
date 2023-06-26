#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int alpha[26] = { 0 };

	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		alpha[word[0] - 'a']++;
	}

	string ans = "";

	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) {
			ans.push_back((char)i + 'a');
		}
	}

	if (ans.empty()) {
		cout << "PREDAJA";
	}
	else {
		cout << ans;
	}

	return 0;
}