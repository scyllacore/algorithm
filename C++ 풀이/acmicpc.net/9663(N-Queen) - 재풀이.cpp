#include <iostream>
#include <cmath>

using namespace std;

#define MAX_X_POS 15

int yPos[MAX_X_POS + 1] = { 0 };

int n;
int answer = 0;

bool checkQueenPos(int xDepth) {
	for (int i = 1; i < xDepth; i++) {
		if (yPos[i] == yPos[xDepth]
			|| abs(yPos[xDepth] - yPos[i]) == xDepth - i) {
			return 0;
		}
	}

	return 1;
}

void dfs(int xDepth) {
	if (xDepth > n) {
		answer++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		yPos[xDepth] = i;

		if (checkQueenPos(xDepth)) {
			dfs(xDepth + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	dfs(1);

	cout << answer;
	return 0;
}