#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define SIZE 3

struct puzzleSnap {
	string snap;
	int move;
};

int dir[] = { -1,1,0,0 };

int bfs(string puzzle) {
	string origin = "123456780";

	queue<puzzleSnap> bfsQ;
	unordered_set<string> visited;

	bfsQ.push({ puzzle,0 });
	visited.insert(puzzle);

	for (; !bfsQ.empty();) {
		string curSnap = bfsQ.front().snap;
		int curMove = bfsQ.front().move;
		bfsQ.pop();

		if (curSnap == origin) {
			return curMove;
		}

		int zeroPos = curSnap.find("0");
		int curY = zeroPos / 3;
		int curX = zeroPos % 3;

		for (int i = 0; i < 4; i++) {
			string nextSnap = curSnap;

			int nextY = curY + dir[i];
			int nextX = curX + dir[3 - i];

			if (nextY < 0 || nextY >= SIZE || nextX < 0 || nextX >= SIZE) {
				continue;
			}

			swap(nextSnap[nextY * 3 + nextX], nextSnap[zeroPos]);

			if (visited.find(nextSnap) == visited.end()) {
				visited.insert(nextSnap);
				bfsQ.push({ nextSnap, curMove + 1 });
			}

		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string puzzle = "";

	int n;
	for (int i = 0; i < SIZE * SIZE; i++) {
		cin >> n;
		puzzle += (char)(n + '0');
	}

	cout << bfs(puzzle);
	return 0;
}