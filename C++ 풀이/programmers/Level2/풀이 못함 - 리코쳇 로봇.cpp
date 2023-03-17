#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int row;
int col;
vector<string> tmpBoard;

int answer = 999;

void dfs(int y, int x, int preD, int move) {

    if (move > 15) {
        return;
    }

    if (tmpBoard[y][x] == 'G') {
        answer = min(move, answer);
        return;
    }

    for (int i = 0; i < 4; i++) {

        if (i == preD) {
            continue;
        }

        int cnt;

        for (cnt = 1; ; cnt++) {
            int nextY = y + dy[i] * cnt;
            int nextX = x + dx[i] * cnt;

            if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col) {
                break;
            }

            if (tmpBoard[nextY][nextX] == 'D') {
                break;
            }
        }

        dfs(y + dy[i] * (cnt - 1), x + dx[i] * (cnt - 1), i, move + 1);
    }


}


int solution(vector<string> board) {

    tmpBoard = board;

    row = board.size();
    col = board[0].size();

    int ry, rx;
    int gy, gx;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'R') {
                ry = i;
                rx = j;
            }
            if (board[i][j] == 'G') {
                gy = i;
                gx = j;
            }
        }
    }

    int dotCnt = 0;
    int dCnt = 0;
    int notRangeCnt = 0;

    for (int i = 0; i < 4; i++) {
        int nextY = gy + dy[i];
        int nextX = gx + dx[i];

        if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col) {
            notRangeCnt++;
            continue;
        }

        if (board[nextY][nextX] == '.') {
            dotCnt++;
        }

        if (board[nextY][nextX] == 'D') {
            dCnt++;
        }
    }

    if ((dotCnt == 4) || (4 - dCnt == notRangeCnt)) {
        return -1;
    }


    dfs(ry, rx, -1, 0);

    return answer == 999 ? -1 : answer;
}