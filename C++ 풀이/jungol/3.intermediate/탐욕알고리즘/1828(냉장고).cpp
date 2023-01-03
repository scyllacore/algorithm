#include <iostream>
#include <algorithm>

using namespace std;

struct C {
	int start;
	int end;
}c[100];

bool cmp(const C& c1, const C& c2) {
	if (c1.end == c2.end) {
		return c1.start < c2.start;
	}
	return c1.end < c2.end;
}

int n;

int main() {

	cin >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> c[i].start >> c[i].end;
	}

	sort(&c[0], &c[n], cmp);

	/*cout << "--------\n";

	for (i = 0; i < n; i++) {
		cout << c[i].start << ' ' << c[i].end << '\n';
	}*/

	int end = c[0].end;
	int minCnt = 1;

	for (i = 1; i < n; i++) {
		if (c[i].start > end) {
			end = c[i].end;
			minCnt++;
		}
	}

	cout << minCnt;

	return 0;


}

