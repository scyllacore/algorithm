#include <iostream>
#include <deque>

using namespace std;

#define MAX (int)1e5

int visited[MAX + 1] = { 0 };

int bfs(int start, int end) {
	deque<int> bfsDq;

	visited[start] = 1;
	bfsDq.push_back(start);

	for (; !bfsDq.empty();) {
		int cur = bfsDq.front();
		bfsDq.pop_front();

		if (cur == end) {
			return visited[cur] - 1;
		}

		if (cur >= 1 && cur <= MAX / 2 && !visited[cur * 2]) {
			visited[cur * 2] = visited[cur];
			bfsDq.push_front(cur * 2);
		}

		if (cur >= 1 && !visited[cur - 1]) {
			visited[cur - 1] = visited[cur] + 1;
			bfsDq.push_back(cur - 1);
		}

		if (cur <= MAX - 1 && !visited[cur + 1]) {
			visited[cur + 1] = visited[cur] + 1;
			bfsDq.push_back(cur + 1);
		}

	}

	return -1;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);

	return 0;
}