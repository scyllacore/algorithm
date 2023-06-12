#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 1000
#define BOUNDARY -(int)1e6

int dy[] = { 1,0,0 };
int dx[] = { 0,-1,1 };

int mapNM[SIZE][SIZE];
int dp[SIZE][SIZE][3];
bool visited[SIZE][SIZE] = { {0} };


int n, m;

int dfs(int y, int x, int dir) {
	if (y == n - 1 && x == m - 1) {
		return mapNM[y][x];
	}

	if (dp[y][x][dir] != BOUNDARY) {
		return dp[y][x][dir];
	}

	visited[y][x] = 1;

	for (int i = 0; i < 3; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY >= n || nextX < 0 || nextX >= m || visited[nextY][nextX]) {
			continue;
		}

		dp[y][x][dir] = max(dfs(nextY, nextX, i) + mapNM[y][x], dp[y][x][dir]);
	}

	visited[y][x] = 0;

	return dp[y][x][dir];
	//dp[y][x][dir]의 의미는 이전 지점에서 dir방향으로 움직여 현재 y,x 지점으로 접근했다는 것을 나타냄.
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mapNM[i][j];
		}
	}

	fill(&dp[0][0][0], &dp[SIZE - 1][SIZE - 1][3], BOUNDARY);

	cout << dfs(0, 0, 0); // 시작점에서 방향은 아무거나 상관 없음 

}

/*
#include <iostream>

using namespace std;

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;

int N, M, A[1010][1010], D[1010][1010];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> A[i][j];

	for (int i = 1; i <= M; i++) D[1][i] = D[1][i - 1] + A[1][i];
	for (int i = 2; i <= N; i++) {
		int L[1010], R[1010];
		L[1] = D[i - 1][1] + A[i][1];
		R[M] = D[i - 1][M] + A[i][M];
		for (int j = 2; j <= M; j++) L[j] = max(D[i - 1][j], L[j - 1]) + A[i][j];
		for (int j = M - 1; j; j--) R[j] = max(D[i - 1][j], R[j + 1]) + A[i][j];
		for (int j = 1; j <= M; j++) D[i][j] = max(L[j], R[j]);
	}
	cout << D[N][M];
}
*/