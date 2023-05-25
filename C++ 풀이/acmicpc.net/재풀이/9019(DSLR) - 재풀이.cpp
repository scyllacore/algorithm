#include <iostream>
#include <queue>

using namespace std;

struct numberInfo {
	int number;
	string cmds;
};

#define MAX (int)1e4

bool visited[MAX] = { 0 };

string bfs(int& start, int& end) {
	queue<numberInfo> bfsQ;
	visited[start] = 1;
	bfsQ.push({ start,"" });

	for (; !bfsQ.empty();) {
		int curN = bfsQ.front().number;
		string curCmds = bfsQ.front().cmds;
		bfsQ.pop();

		if (curN == end) {
			return curCmds;
		}

		int nextN;

		nextN = (2 * curN) % MAX;
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN,curCmds + "D" });
		}

		nextN = curN == 0 ? MAX - 1 : curN - 1;
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN,curCmds + "S" });
		}

		nextN = (curN % 1000) * 10 + curN / 1000;
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN,curCmds + "L" });
		}

		nextN = (curN % 10) * 1000 + curN / 10; // curN / 100
		if (!visited[nextN]) {
			visited[nextN] = 1;
			bfsQ.push({ nextN,curCmds + "R" });
		}
	}

	return "NOT_EXIST_CMDS";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int start, end;
	for (; tc--;) {
		cin >> start >> end;
		cout << bfs(start, end) << '\n';
		fill(visited, visited + MAX, 0);
	}

	return 0;
}