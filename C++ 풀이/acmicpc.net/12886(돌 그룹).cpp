#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 1501

int a, b, c;

struct stone {
	int a, b, c;
};

bool visited[MAX][MAX] = { {0} };

bool BFS() {

	if ((a + b + c) % 3 != 0) {
		return 0;
	}

	queue<stone> bfsQ;

	bfsQ.push({ a,b,c });
	visited[a][b] = 1;

	int curA, curB, curC;
	int i;
	int next1, next2;

	while (!bfsQ.empty()) {

		curA = bfsQ.front().a;
		curB = bfsQ.front().b;
		curC = bfsQ.front().c;
		bfsQ.pop();

		if (curA == curB && curB == curC) { return 1; }

		if (curA != curB) {

			if (curA < curB) { next1 = curA * 2, next2 = curB - curA; }
			else { next1 = curA - curB, next2 = curB * 2; }

			if (!visited[next1][next2]) {
				visited[next2][next1] = visited[next1][next2] = 1;
				bfsQ.push({ next1,next2,curC });
			}

		}


		if (curA != curC) {

			if (curA < curC) { next1 = curA * 2, next2 = curC - curA; }
			else { next1 = curA - curC, next2 = curC * 2; }

			if (!visited[next1][next2]) {
				visited[next2][next1] = visited[next1][next2] = 1;
				bfsQ.push({ next1,next2,curB });
			}

		}

		if (curB != curC) {

			if (curB < curC) { next1 = curB * 2, next2 = curC - curB; }
			else { next1 = curB - curC, next2 = curC * 2; }

			if (!visited[next1][next2]) {
				visited[next2][next1] = visited[next1][next2] = 1;
				bfsQ.push({ next1,next2,curA });
			}

		}

	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int i;

	cin >> a >> b >> c;

	cout << BFS();

	return 0;

}
