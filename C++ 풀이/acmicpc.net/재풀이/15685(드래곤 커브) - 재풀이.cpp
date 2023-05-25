#include <iostream>
#include <vector>

using namespace std;

#define SIZE 100

struct pos {
	int y, x;
};

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };

bool curveMap[SIZE + 1][SIZE + 1] = { {0} };

void visitCurve(vector<int>& dirV, pos& endPos) {
	int size = dirV.size();

	for (int i = size - 1; i >= 0; i--) {
		int nextDir = (dirV[i] + 1) % 4;
		dirV.push_back(nextDir);

		endPos = { endPos.y + dy[nextDir], endPos.x + dx[nextDir] };
		curveMap[endPos.y][endPos.x] = 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int y, x, d, g;
	pos endPos;
	vector<int> dirV;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g; // 실수1. 입력 y,x로 처리

		dirV.clear();

		endPos = { y + dy[d],x + dx[d] };
		curveMap[endPos.y][endPos.x] = curveMap[y][x] = 1;
		dirV.push_back(d);

		for (int j = 0; j < g; j++) {
			visitCurve(dirV, endPos);
		}
	}

	int ans = 0;

	for (int i = 0; i <= SIZE - 1; i++) {
		for (int j = 0; j <= SIZE - 1; j++) {
			if (curveMap[i][j] && curveMap[i + 1][j] && curveMap[i][j + 1] && curveMap[i + 1][j + 1]) {
				ans++;
			}
		}
	}

	cout << ans;
}