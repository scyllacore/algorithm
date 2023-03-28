#include <iostream>
#include <queue>

using namespace std;

#define MAX 100

struct spotInfo {
	int spot;
	int movingCnt;
};

bool visited[MAX + 1] = { 0 };
int movingRoute[MAX + 1] = { 0 };

int bfs() {
	queue<spotInfo> bfsQ;
	visited[1] = 1;
	bfsQ.push({ 1,0 });

	for (; !bfsQ.empty();) {
		int curSpot = bfsQ.front().spot;
		int curMovingCnt = bfsQ.front().movingCnt;
		bfsQ.pop();

		if (curSpot == MAX) {
			return curMovingCnt;
		}

		for (int i = 1; i <= 6; i++) {
			int nextSpot = curSpot + i;

			if (nextSpot > 100) {
				break;
			}

			if (!visited[nextSpot] && movingRoute[nextSpot]) {
				int movingSpot = movingRoute[nextSpot];
				visited[nextSpot] = visited[movingSpot] = 1;
				bfsQ.push({ movingSpot,curMovingCnt + 1 });
			}
			else if (!visited[nextSpot]) {
				visited[nextSpot] = 1;
				bfsQ.push({ nextSpot,curMovingCnt + 1 });
			}

		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int start, end;

	for (int i = 0; i < n + m; i++) {
		cin >> start >> end;
		movingRoute[start] = end;
	}

	cout << bfs();
	return 0;
}
