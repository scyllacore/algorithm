#include <iostream>
#include <algorithm>
#define MAX 100000
#define MAX_VAL 987654321

using namespace std;

bool switchArr[MAX];
bool switchArrAns[MAX];
bool switchArrTmp[MAX];


int n,minAns= MAX_VAL;

bool sameCheck() {

	int i;

	for (i = 0; i < n; i++) {
		if (switchArrTmp[i] != switchArrAns[i]) return 0;
	}

	return 1;

}

void change(int idx) {

	int i;

	for (i = idx - 1; i <= idx + 1; i++) {

		if (i < 0 || i > n - 1) continue;

		switchArrTmp[i] = !switchArrTmp[i];
	}
}

void input() {
	int i;
	char ch;

	for (i = 0; i < n; i++) {
		cin >> ch;
		switchArr[i] = (ch == '0' ? '0' : '1') - 48;
	}

	for (i = 0; i < n; i++) {
		cin >> ch;
		switchArrAns[i] = (ch == '0' ? '0' : '1') - 48;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	input();

	int cnt, i;

	//0번째 킨 경우

	copy(&switchArr[0], &switchArr[n], switchArrTmp);

	change(0), cnt=1;
	for (i = 1; i < n; i++) {
		if (switchArrTmp[i - 1] != switchArrAns[i - 1]) {
			change(i);
			cnt++;
		}
	}

	if (sameCheck()) {
		minAns = min(cnt, minAns);
	}

	//0번째 안 킨 경우

	copy(&switchArr[0], &switchArr[n], switchArrTmp);

	cnt = 0;

	for (i = 1; i < n; i++) {
		if (switchArrTmp[i - 1] != switchArrAns[i - 1]) {
			change(i);
			cnt++;
		}
	}

	if (sameCheck()) {
		minAns = min(cnt, minAns);
	}

	//최소값 확인

	if (minAns != MAX_VAL) {
		cout << minAns;
	}
	else {
		cout << -1;
	}

	return 0;

}