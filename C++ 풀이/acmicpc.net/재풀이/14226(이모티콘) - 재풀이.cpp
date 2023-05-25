#include <iostream>
#include <queue>

using namespace std;

#define MAX (int)1e3

struct emo {
	int screen;
	int clip;
};

int visited[MAX + 1][MAX + 1] = { {0} };
int n;

int bfs(int answer) {
	queue<emo> bfsQ;
	visited[1][0] = 1;
	bfsQ.push({ 1,0 });

	for (; !bfsQ.empty();) {
		int s = bfsQ.front().screen;
		int c = bfsQ.front().clip;
		bfsQ.pop();

		if (s == answer) {
			return visited[s][c] - 1;
		}

		if (s >= 1 && !visited[s][s]) {
			visited[s][s] = visited[s][c] + 1;
			bfsQ.push({ s,s });
		}

		if (c >= 1 && s + c <= MAX && !visited[s + c][c]) {
			visited[s + c][c] = visited[s][c] + 1;
			bfsQ.push({ s + c,c });
		}

		if (s >= 1 && !visited[s - 1][c]) {
			visited[s - 1][c] = visited[s][c] + 1;
			bfsQ.push({ s - 1,c });
		}

	}

	return -1;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int answer;
	cin >> answer;

	cout << bfs(answer);

	return 0;
}