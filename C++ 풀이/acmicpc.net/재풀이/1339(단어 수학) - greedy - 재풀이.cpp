#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string* words = new string[n];
	vector<int> alphaCoefficient(26, 0);

	for (int i = 0; i < n; i++) {
		cin >> words[i];

		int exponent = 1;
		for (int j = words[i].length() - 1; j >= 0; j--) {
			alphaCoefficient[words[i][j] - 'A'] += exponent;
			exponent *= 10;
		}
	}

	sort(alphaCoefficient.begin(), alphaCoefficient.end(), greater<>());

	int answer = 0;

	for (int i = 0; i < 10; i++) {
		answer += alphaCoefficient[i] * (9 - i);
	}

	cout << answer;
	return 0;
}
