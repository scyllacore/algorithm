#include <iostream>

using namespace std;

#define SIZE 50

struct spot {
	int r, c;
	int d;
};

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

int n, m;
int room[SIZE][SIZE] = { {0} };

int ans = 1;

void dfs(spot cur) {

	room[cur.r][cur.c] = -1;

	for (int i = 0; i < 4; i++) {
		int nextD = (cur.d + 3 - i) % 4;
		int nextR = cur.r + dr[nextD];
		int nextC = cur.c + dc[nextD];

		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
			continue;
		}

		if (room[nextR][nextC] != 0) {
			continue;
		}

		ans++;
		dfs({ nextR,nextC,nextD });

		return;
	}

	int backD = (cur.d + 2) % 4;
	int backR = cur.r + dr[backD];
	int backC = cur.c + dc[backD];

	if (backR < 0 || backR >= n || backC < 0 || backC >= m) {
		return;
	}

	if (room[backR][backC] != 1) {
		dfs({ backR,backC,cur.d });
	}

	cout << ans;
	exit(0);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	spot start;
	cin >> start.r >> start.c >> start.d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	dfs(start);

	cout << ans;

	return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 50

struct spot {
	int r, c;
	int d;
};

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int n, m;
bool room[SIZE][SIZE] = { {0} };
bool visited[SIZE][SIZE] = { {0} };

int ans = 0;

void dfs(spot cur) {

	if (visited[cur.r][cur.c]) {
		return;
	}

	visited[cur.r][cur.c] = 1;
	ans++;

	for (int i = 0; i < 4; i++) {
		int nextD = (cur.d + 3 - i) % 4;
		int nextR = cur.r + dr[nextD];
		int nextC = cur.c + dc[nextD];

		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
			continue;
		}

		if (room[nextR][nextC] || visited[nextR][nextC]) {
			continue;
		}

		dfs({ nextR,nextC,nextD });
	}

	int backD = (cur.d + 2) % 4;
	int backR = cur.r + dr[backD];
	int backC = cur.c + dc[backD];

	if (backR >= 0 && backR < n && backC >= 0 && backC < m) {
		if (!room[backR][backC]) {
			dfs({ backR,backC,cur.d });
		}
		else {
			cout << ans;
			exit(0);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	spot start;
	cin >> start.r >> start.c >> start.d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	dfs(start);

	return 0;
}

/*
1.#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 50

struct spot {
	int r, c;
	int d;
};

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int n, m;
bool room[SIZE][SIZE] = { {0} };
bool visited[SIZE][SIZE] = { {0} };

int ans = 0;

void dfs(spot cur) {

	if (visited[cur.r][cur.c]) {
		return;
	}

	visited[cur.r][cur.c] = 1;
	ans++;

	for (int i = 0; i < 4; i++) {
		int nextD = (cur.d + i) % 4;

		int nextR = cur.r + dr[nextD];
		int nextC = cur.c + dc[nextD];

		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
			continue;
		}

		if (room[nextR][nextC] || visited[nextR][nextC]) {
			continue;
		}

		dfs({ nextR,nextC,nextD });
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	spot start;
	cin >> start.r >> start.c >> start.d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	dfs(start);

	cout << ans;

	return 0;
}
*/

/*
2.
#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 50

struct spot {
	int r, c;
	int d;
};

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int n, m;
bool room[SIZE][SIZE] = { {0} };
bool visited[SIZE][SIZE] = { {0} };

int ans = 0;

void dfs(spot cur) {

	if (visited[cur.r][cur.c]) {
		return;
	}

	visited[cur.r][cur.c] = 1;
	ans++;

	int cnt = 0;
	int nextD, nextR, nextC;

	for (int i = 0; i < 4; i++) {
		 nextD = 3 - (cur.d + i + 1) % 4;
		 nextR = cur.r + dr[nextD];
		 nextC = cur.c + dc[nextD];

		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
			continue;
		}

		if (room[nextR][nextC] || visited[nextR][nextC]) {
			continue;
		}

		dfs({ nextR,nextC,nextD });
		cnt++;
	}

	if (cnt == 0) {
		nextR = cur.r - dr[cur.d];
		nextC = cur.c - dc[cur.d];

		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
			return;
		}

		if (room[nextR][nextC]) {
			return;
		}

		dfs({ nextR,nextC,cur.d });
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	spot start;
	cin >> start.r >> start.c >> start.d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	dfs(start);

	cout << ans;

	return 0;
}
*/
*/