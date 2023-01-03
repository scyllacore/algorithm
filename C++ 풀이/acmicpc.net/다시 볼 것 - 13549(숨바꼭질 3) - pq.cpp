#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100000

int n, k;
bool visited[MAX + 1];

struct subin {
	int pos, sec;
};

struct cmp {
	bool operator()(const subin& s1, const subin& s2) {
		if (s1.sec != s2.sec) {
			return s1.sec > s2.sec;
		}
		else {
			return s1.pos > s2.pos;
		}
	}
};

int BFS() {

	priority_queue<subin, vector<subin>, cmp> bfsQ;

	bfsQ.push({ n,0 });
	visited[n] = 1;

	int curPos, curSec;
	int nextPos, nextSec;

	while (!bfsQ.empty()) {

		curPos = bfsQ.top().pos;
		curSec = bfsQ.top().sec;
		bfsQ.pop();

		if (curPos == k) {
			return curSec;
		}


		if (curPos > 0 && curPos <= MAX / 2 && !visited[curPos * 2]) {
			nextPos = curPos * 2;
			visited[nextPos] = 1;
			bfsQ.push({ nextPos, curSec });
		}


		if (curPos > 0 && !visited[curPos - 1]) {
			nextPos = curPos - 1, nextSec = curSec + 1;
			visited[nextPos] = 1;
			bfsQ.push({ nextPos, nextSec });
		}

		if (curPos < MAX && !visited[curPos + 1]) {
			nextPos = curPos + 1, nextSec = curSec + 1;
			visited[nextPos] = 1;
			bfsQ.push({ nextPos, nextSec });
		}

	}

	return -1;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill(&visited[0], &visited[MAX + 1], 0);

	cin >> n >> k;

	cout << BFS();


}