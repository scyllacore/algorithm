#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
    int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

bool visited[100][100] = { {0} };

int bfs(vector<string>& maps, int& y, int& x) {
    queue<pos> bfsQ;

    bfsQ.push({ y,x });
    visited[y][x] = 1;
    int sum = maps[y][x] - '0';

    int row = maps.size();
    int col = maps[0].size();


    for (; !bfsQ.empty();) {
        int curY = bfsQ.front().y;
        int curX = bfsQ.front().x;
        bfsQ.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col) {
                continue;
            }

            if (maps[nextY][nextX] != 'X' && !visited[nextY][nextX]) {
                sum += maps[nextY][nextX] - '0';
                visited[nextY][nextX] = 1;
                bfsQ.push({ nextY,nextX });
            }
        }

    }

    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    int row = maps.size();
    int col = maps[0].size();


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maps[i][j] == 'X' || visited[i][j]) {
                continue;
            }

            int sum = bfs(maps, i, j);
            answer.push_back(sum);
        }
    }

    sort(answer.begin(), answer.end());

    return (answer.empty() ? vector<int>{-1} : answer);
}