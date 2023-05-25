#include <iostream>
#include <algorithm>

using namespace std;


struct dayInfo {
	int t;
	int p;
};

int n;
int maxP = 0;
dayInfo* day;

void dfs(int curDay, int sumT) {

	if (curDay > n + 1) {
		return;
	}

	maxP = max(sumT, maxP);

	for (int i = curDay; i <= n; i++) {
		dfs(i + day[i].t, sumT + day[i].p);
	}

	/*if (curDay == 8) {
		cout << "8" << '\n';
	} 마지막 날(n)의 다음 날(n+1)에서는 재귀 접근을 하지 않으며, for문 조건이 맞지 않아 함수가 끝난다 */

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	day = new dayInfo[n + 1];

	int i;

	for (i = 1; i <= n; i++) {
		cin >> day[i].t >> day[i].p;
	}

	for (i = 1; i <= n; i++) {
		dfs(i, 0);
	}

	cout << maxP;

}