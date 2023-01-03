#include <iostream>
#include <queue>

using namespace std;

struct number {
	int n;
	string cmd;
};

bool visited[10000] = { 0 };
int A, B;

string bfs() {

	queue<number> bfsQ;

	bfsQ.push({ A,"" });
	visited[A] = 1;

	int curN;
	string curCmd;

	while (!bfsQ.empty()) {

		curN = bfsQ.front().n;
		curCmd = bfsQ.front().cmd;
		bfsQ.pop();

		if (curN == B) {
			return curCmd;
		}

		int nextN;

		nextN = (2 * curN) % 10000; // D
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN , curCmd + 'D' });
		}

		nextN = (curN == 0 ? 9999 : curN - 1); // S
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN , curCmd + 'S' });
		}

		nextN = (curN % 1000) * 10 + curN / 1000; // L
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN , curCmd + 'L' });
		}

		nextN = (curN % 10) * 1000 + curN / 10; // R
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN , curCmd + 'R' });
		}

	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> A >> B;
		cout << bfs() << '\n';
		fill_n(visited, 10000, 0);
	}

	return 0;
}
