#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define MAX 1000

using namespace std;

int mapNM[MAX][MAX];
bool visited[MAX][MAX];

int area = 0;
int areaNum[MAX][MAX];
int answer[MAX][MAX];

vector<int> areaNumZeroCnt;

int n, m;

struct pos {
	int y, x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int y, int x) {

	queue<pos> bfsQ;

	bfsQ.push({ y,x });
	visited[y][x] = 1;
	areaNum[y][x] = area;
	areaNumZeroCnt.push_back(1);

	int curY, curX;
	int nextY, nextX;
	int i;

	while (!bfsQ.empty()) {
		curY = bfsQ.front().y;
		curX = bfsQ.front().x;
		bfsQ.pop();

		for (i = 0; i < 4; i++) {
			nextY = curY + dy[i];
			nextX = curX + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) { continue; }

			if (!mapNM[nextY][nextX] && !visited[nextY][nextX]) {
				areaNum[nextY][nextX] = area;
				areaNumZeroCnt[area]++;
				visited[nextY][nextX] = 1;
				bfsQ.push({ nextY,nextX });
			}
		}
	}
}


void countZero() {

	int i, j;
	
	for (i = 0; i < n; i++) {
		fill_n(areaNum[i], m, -1);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (!mapNM[i][j] && !visited[i][j]) {
				bfs(i, j);
				area++;
			}
		}
	}

	int nextY, nextX;
	int k;

	//for (i = 0; i < areaNumZeroCnt.size(); i++) {
	//	cout << areaNumZeroCnt[i] << ' ';
	//}
	//cout << '\n';


	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			if (!mapNM[i][j]) { continue; }

			set<int> searchArea;

			for(k=0; k<4; k++){
				nextY = i + dy[k];
				nextX = j + dx[k];

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || mapNM[nextY][nextX]) { continue; }

				if (searchArea.find(areaNum[nextY][nextX]) == searchArea.end()) {
					searchArea.insert(areaNum[nextY][nextX]);
					answer[i][j] += areaNumZeroCnt[areaNum[nextY][nextX]];
				}

			}
			answer[i][j] = (answer[i][j] + 1) % 10;
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	string str;
	int i, j;

	for (i = 0; i < n; i++) {
		cin >> str;
		for (j = 0; j < m; j++) {
			if (str[j] == '1') {
				mapNM[i][j] = 1;
			}
		}
	}

	countZero();


	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << answer[i][j];
		}
		cout << '\n';
	}

}

//4 4
//1001
//1101
//0010
//0111
