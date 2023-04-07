#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX (int)1e4
#define INF (int)1e5

struct number {
	int idx;
	int move;
};

bool prime[MAX] = { {0} };
int visited[MAX] = { 0 };

void setPrime() {

	for (int i = 2; i < MAX / i; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				prime[j] = 1;
			}
		}
	}
}

int bfs(int& start, int& end) {

	fill_n(visited, MAX, INF);

	queue<number> bfsQ;
	bfsQ.push({ start,0 });
	visited[start] = 0;

	for (; !bfsQ.empty();) {
		int curIdx = bfsQ.front().idx;
		int curMove = bfsQ.front().move;
		bfsQ.pop();

		string idxStr = to_string(curIdx);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 0 && j == 0) {
					continue;
				}

				string tmpIdx = idxStr; // 오류1. 원래값을 통해 바꿔야하는데 바뀐 값을 통해 바꾼다.

				tmpIdx[i] = j + '0';
				int nextIdx = stoi(tmpIdx);

				if (!prime[nextIdx] && curMove + 1 < visited[nextIdx]) {
					visited[nextIdx] = curMove + 1;
					bfsQ.push({ nextIdx,curMove + 1 });
				}
			}
		}
	}

	return visited[end];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	setPrime();
	int start, end;

	for (; tc--;) {
		cin >> start >> end;
		cout << bfs(start, end) << '\n';
	}

	return 0;
}

//문제 자체에 imposible 오류가 있다.