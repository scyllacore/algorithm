#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meetingTime {
	int start, end;
};

bool cmp(meetingTime& m1, meetingTime& m2) {
	if (m1.end == m2.end) {
		return m1.start < m2.start;
	}

	return m1.end < m2.end;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<meetingTime> meeting(n);

	for (int i = 0; i < n; i++) {
		cin >> meeting[i].start >> meeting[i].end;
	}

	sort(meeting.begin(), meeting.end(), cmp);

	int answer = 1;

	int start, end = meeting[0].end;

	for (int i = 1; i < n; i++) {
		start = meeting[i].start;

		if (end <= start) {
			end = meeting[i].end;
			answer++;
		}
	}

	cout << answer;
	return 0;
}

// 8 8 같이 시작과 끝 시간이 같은 경우, 4 8 같이 시작과 끝이 다른 시간 먼저 처리되어야 한다.