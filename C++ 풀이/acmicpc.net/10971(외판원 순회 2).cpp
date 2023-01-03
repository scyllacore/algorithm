#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int sequence[11] = { 0 };
bool visited[11] = { 0 };
int W[11][11] = { {0} };

int n;
int res = INT_MAX;

void DFS_btrk(int depth, int sumCost) {

	if (sumCost > res) { // 시간 줄여줌
		return;
	}

	int cost;

	if (depth > n) {
		cost = W[sequence[n]][sequence[1]];
		if (cost == 0) return;

		res = min(sumCost + cost, res);
		return;
	}

	int i;

	for (i = 1; i <= n; i++) {
		if (visited[i]) continue;

		sequence[depth] = i;
		cost = W[sequence[depth - 1]][sequence[depth]]; //depth는 2부터 시작
		if (cost == 0) {
			continue; // return으로 쓰면 안됨.
		}

		visited[i] = true;
		DFS_btrk(depth + 1, sumCost + cost); // sum값 누적
		visited[i] = false;
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> W[i][j];
		}
	}

	for (i = 1; i <= n; i++) { // depth 1 처리
		sequence[1] = i;
		visited[i] = true;
		DFS_btrk(2, 0);
		visited[i] = false;
	}

	cout << res;

	return 0;

}
