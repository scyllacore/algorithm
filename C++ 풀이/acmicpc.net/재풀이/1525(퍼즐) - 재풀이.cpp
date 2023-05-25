#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define ORIGIN "123456780"
#define SIZE 3

struct puzzleInfo {
	string puzzle;
	int count;
};
int dir[] = { -1,1,0,0 };


int bfs(string& puzzle) {

	queue<puzzleInfo> bfsQ;
	unordered_set<string> visited;

	bfsQ.push({ puzzle,0 });
	visited.insert(puzzle);

	string curPuzzle, nextPuzzle;
	int curCount;

	for (; !bfsQ.empty();) {
		curPuzzle = bfsQ.front().puzzle;
		curCount = bfsQ.front().count;
		bfsQ.pop();

		if (curPuzzle == ORIGIN) {
			return curCount;
		}

		int zeroIdx = curPuzzle.find("0");

		int curY = zeroIdx / 3;
		int curX = zeroIdx % 3;

		for (int i = 0; i < 4; i++) {
			nextPuzzle = curPuzzle;

			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= SIZE || nextX < 0 || nextX >= SIZE) {
				continue;
			}

			swap(nextPuzzle[nextY * 3 + nextX], nextPuzzle[curY * 3 + curX]);

			if (visited.find(nextPuzzle) == visited.end()) {
				bfsQ.push({ nextPuzzle,curCount + 1 });
				visited.insert(nextPuzzle);
			}
		}

	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string puzzle = ORIGIN;

	for (int i = 0; i < 9; i++) {
		cin >> puzzle[i];
	}

	cout << bfs(puzzle);
	return 0;
}