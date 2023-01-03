#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100001] = { 0 };

int BFS(int spot) {

	queue<int> spotBFS;
	spotBFS.push(spot);

	int curSpot, nextSpot;

	while (!spotBFS.empty()) {

		curSpot = spotBFS.front();
		spotBFS.pop();

		if (curSpot == k) {
			return visited[curSpot] - 1;
		}

		if (curSpot >= 1 && !visited[curSpot - 1]) {
			nextSpot = curSpot - 1;
			visited[nextSpot] = visited[curSpot] + 1;
			spotBFS.push(nextSpot);
		}

		if (curSpot <= 99999 && !visited[curSpot + 1]) {
			nextSpot = curSpot + 1;
			visited[nextSpot] = visited[curSpot] + 1;
			spotBFS.push(nextSpot);
		}

		if (curSpot >= 2 && curSpot <= 50000 && !visited[curSpot * 2]) {
			nextSpot = curSpot * 2;
			visited[nextSpot] = visited[curSpot] + 1;
			spotBFS.push(nextSpot);
		}

	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	visited[n] = 1;
	cout << BFS(n);

}