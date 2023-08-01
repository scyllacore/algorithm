#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int& a, const int& b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> guest(n);

	for (int i = 0; i < n; i++) {
		cin >> guest[i];
	}

	sort(guest.begin(), guest.end(), cmp);

	unsigned long long tip = 0;

	for (int i = 0; i < n; i++) {
		if (guest[i] - i <= 0) {
			break;
		}
		tip += guest[i] - i;
	}

	cout << tip;

	return 0;
}