#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int d, n;
	cin >> d >> n;

	vector<int> dVec(d);

	for (int i = 0; i < d; i++) {
		cin >> dVec[i];
		if (i != 0 && dVec[i] > dVec[i - 1]) {
			dVec[i] = dVec[i - 1];
		}
	}

	vector<int> nVec(n);

	for (int i = 0; i < d; i++) {
		cin >> nVec[i];
	}

	int count = 0;
	for (int i = d - 1; i >= 0; i--) {
		if (nVec[count] <= dVec[i]) { count++; }

		if (count == n) {
			cout << i + 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}

//https://velog.io/@fantastik/40 ÀÌºÐ Å½»ö
//https://moons-memo.tistory.com/106