#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0 ,0,-1,1 };


int map[26][26] = { {0} };
vector<int> blockN;

int n, houseN;

void DFS_btrk(int y, int x) {

	map[y][x] = -1;
	houseN++;

	int i;

	for (i = 0; i < 4; i++) {
		int yNew = y + dy[i];
		int xNew = x + dx[i];

		if (xNew >= 1 && xNew <= n && yNew >= 1 && yNew <= n) {
			if (map[yNew][xNew]==1) {
				DFS_btrk(yNew, xNew);
			}
		}
	}


}

int main() {


	scanf("%d", &n);


	int i, j;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j]==1)
			{
				houseN = 0;
				DFS_btrk(i, j);
				blockN.push_back(houseN);
			}
		}
	}

	sort(blockN.begin(), blockN.end());


	printf("%d\n", blockN.size());

	for (i = 0; i < blockN.size(); i++) {
		printf("%d\n", blockN[i]);
	}

	return 0;

}
