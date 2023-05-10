#include <iostream>
#include <vector>

using namespace std;

#define MAX 100 + 1

bool curveMap[MAX][MAX] = { {0} };

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 }; // 실수1. 좌표 설정 잘못함.

struct pos {
	int y, x;
};

void checkDragonDir(vector<int>& dragonDir, pos& curPos) {

	int curSize = dragonDir.size();

	for (int i = curSize - 1; i >= 0; i--) {
		int nextDir = (dragonDir[i] + 1) % 4;

		curPos = { curPos.y + dy[nextDir] ,curPos.x + dx[nextDir] };
		curveMap[curPos.y][curPos.x] = 1;

		dragonDir.push_back(nextDir);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> dragonDir;
	int y, x, d, g;
	pos curPos;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;

		dragonDir.clear();

		curPos = { y + dy[d],  x + dx[d] };
		curveMap[curPos.y][curPos.x] = curveMap[y][x] = 1;
		dragonDir.push_back(d); // 0세대 처리

		for (int j = 0; j < g; j++) {
			checkDragonDir(dragonDir, curPos);
		}
	}

	int ans = 0;

	for (int i = 0; i <= MAX - 2; i++) {
		for (int j = 0; j <= MAX - 2; j++) {
			if (curveMap[i][j] && curveMap[i + 1][j] && curveMap[i][j + 1] && curveMap[i + 1][j + 1]) {
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}
