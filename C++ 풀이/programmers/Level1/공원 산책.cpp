#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[] = { 0,0,1,-1 }; // 0,0,-1,1·Î ¾¸
int dx[] = { 1,-1,0,0 }; // µ¿¼­³²ºÏ Çò°¥¸²

int cmd[26] = { 0 };

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> cur(2, 0);

    int row = park.size();
    int col = park[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (park[i][j] == 'S') {
                cur[0] = i;
                cur[1] = j;
                break;
            }
        }
    }

    cmd['E' - 'A'] = 0;
    cmd['W' - 'A'] = 1;
    cmd['S' - 'A'] = 2;
    cmd['N' - 'A'] = 3;

    for (int i = 0; i < routes.size(); i++) {
        char dir = routes[i][0] - 'A'; // -'A'¸¦ ¾È¾¸
        int move = stoi(routes[i].substr(2));

        int j;
        for (j = 1; j <= move; j++) {
            int nextY = cur[0] + dy[cmd[dir]] * j;
            int nextX = cur[1] + dx[cmd[dir]] * j;

            if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col) {
                break;
            }

            if (park[nextY][nextX] == 'X') {
                break;
            }
        }

        if (move + 1 == j) {
            cur[0] += dy[cmd[dir]] * move;
            cur[1] += dx[cmd[dir]] * move;
        }

    }


    return cur;
}