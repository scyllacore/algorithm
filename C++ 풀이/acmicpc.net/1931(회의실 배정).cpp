#include <iostream>
#include <algorithm>
using namespace std;


struct confTime {
	int start;
	int end;
};

bool cmp(confTime& n1, confTime& n2) {
	if (n1.end != n2.end) {
		return n1.end < n2.end;
	}
	else {
		return n1.start < n2.start;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	confTime* conf = new confTime[n];

	int i;

	for (i = 0; i < n; i++) {
		cin >> conf[i].start >> conf[i].end;
	}

	sort(&conf[0], &conf[n], cmp);

	int Time = 0, confCnt = 0;

	for (i = 0; i < n; i++) {
		if (Time <= conf[i].start) {
			Time = conf[i].end;
			confCnt++;
		}

	}

	cout << confCnt;

}
// 시작 시간을 정렬하지 않으면 아래 입력에 대해 2로 오답을 내놓음.
//3
//1 3
//8 8
//4 8