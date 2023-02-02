#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> divisors;
	int i, divisor;

	for (i = 0; i < n; i++) {
		cin >> divisor;
		divisors.push_back(divisor);
	}

	sort(divisors.begin(), divisors.end());

	cout << divisors[0] * divisors[divisors.size() - 1];

	return 0;
}