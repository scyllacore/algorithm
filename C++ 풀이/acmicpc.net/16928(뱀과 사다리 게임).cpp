#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct pos {
	int spot;
	int cnt;
};

bool visited[101] = { 0 };
queue<pos> bfsQ;
unordered_map<int, int> snakeOrLadder;

int BFS() {

	bfsQ.push({ 1,0 });
	visited[1] = 1;

	int curSpot, curCnt;
	int nextSpot, nextCnt, specialSpot, i;

	while (!bfsQ.empty()) {

		curSpot = bfsQ.front().spot;
		curCnt = bfsQ.front().cnt;
		bfsQ.pop();

		if (curSpot == 100) {
			return curCnt;
		}

		nextCnt = curCnt + 1;

		for (i = 1; i <= 6; i++) {

			nextSpot = curSpot + i;
			if (nextSpot > 100) { break; }

			if (!visited[nextSpot] && snakeOrLadder[nextSpot]) { // snakeOrLadder.find(nextSpot) != snakeOrLadder.end()
				specialSpot = snakeOrLadder[nextSpot];
				visited[specialSpot] = visited[nextSpot] = 1;
				bfsQ.push({ specialSpot,nextCnt });
			}

			else if (!visited[nextSpot]) {
				visited[nextSpot] = 1;
				bfsQ.push({ nextSpot,nextCnt });
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

	int i;
	int a, b;

	for (i = 0; i < n + m; i++) {
		cin >> a >> b;
		snakeOrLadder[a] = b;
		//snakeOrLadder.insert({ a, b });
	}


	cout << BFS();

}


//1 1
//2 88
//94 3