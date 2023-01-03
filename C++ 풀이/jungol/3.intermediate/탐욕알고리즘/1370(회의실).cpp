#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meeting {
	int no;
	int start;
	int end;
}mInfo[500];

bool cmp(const meeting& m1, const meeting& m2) {
	if (m1.end == m2.end) {
		return m1.start < m2.start;
	}
	else {
		return m1.end < m2.end;
	}
}

int main() {

	int n;
	cin >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> mInfo[i].no >> mInfo[i].start >> mInfo[i].end;
	}

	sort(&mInfo[0], &mInfo[n], cmp);

	vector<int> noList;

	int end = mInfo[0].end;
	noList.push_back(mInfo[0].no);

	for (i = 1; i < n; i++) {
		if (end <= mInfo[i].start) {
			end = mInfo[i].end;
			noList.push_back(mInfo[i].no);
		}
	}

	cout << noList.size() << '\n';
	for (auto no : noList) {
		cout << no << ' ';
	}

	return 0;

}
