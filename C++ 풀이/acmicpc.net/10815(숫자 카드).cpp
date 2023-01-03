#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int* nCard = new int[n];
	int i;
	for (i = 0; i < n; i++) {
		cin >> nCard[i];
	}

	sort(nCard, nCard + n);

	int m, mCard;
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> mCard;

		int mCardIdx = lower_bound(nCard, nCard + n, mCard) - nCard;

		if (nCard[mCardIdx] == mCard) {
			cout << '1';
		}
		else {
			cout << '0';
		}
		cout << ' ';

	}

}
