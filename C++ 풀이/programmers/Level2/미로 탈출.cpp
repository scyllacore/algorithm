#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 100

struct spotInfo {
    int y, x;
    bool lFlag;
    int move;
};

int dir[] = { -1,1,0,0 };

bool visited[MAX][MAX][2] = { {{0}} };

int n, m;

spotInfo bfs(vector<string>& maps, spotInfo& start, char des) {
    queue<spotInfo> bfsQ;
    bfsQ.push(start);
    visited[start.y][start.x][start.lFlag] = 1;

    for (; !bfsQ.empty();) {
        int curY = bfsQ.front().y;
        int curX = bfsQ.front().x;
        bool curFlag = bfsQ.front().lFlag;
        int curMove = bfsQ.front().move;
        bfsQ.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dir[i];
            int nextX = curX + dir[3 - i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) {
                continue;
            }

            if (maps[nextY][nextX] != 'X' && maps[nextY][nextX] != des
                && !visited[nextY][nextX][curFlag]) {
                // maps[nextY][nextX] != des 추가
                // !(maps[nextY][nextX] == 'X' || maps[nextY][nextX] == des) 드모르간 법칙 적용한 것이 해석하기 편함.
                visited[nextY][nextX][curFlag] = 1;
                bfsQ.push({ nextY,nextX,curFlag,curMove + 1 });
            }
            else if (maps[nextY][nextX] == des && !visited[nextY][nextX][1]) {
                visited[nextY][nextX][1] = 1;
                return { nextY,nextX,1,curMove + 1 };
            }
        }

    }

    return { 0,0,0,-1 };
}

int solution(vector<string> maps) {

    spotInfo start;

    n = maps.size();
    m = maps[0].length();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {
                start = { i,j,0,0 };
            }
        }
    }

    spotInfo via = bfs(maps, start, 'L');

    if (via.move == -1) {
        return -1;
    }

    spotInfo end = bfs(maps, via, 'E');

    if (end.move == -1) {
        return -1;
    }

    return end.move;
}

/*
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 100

struct spotInfo{
    int y,x;
    bool lFlag;
    int move;
};

int dir[] = {-1,1,0,0};

bool visited[MAX][MAX][2] = {{{0}}};

int solution(vector<string> maps) {

    spotInfo start,end;

    int n = maps.size();
    int m = maps[0].length();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j] == 'S'){
                start = {i,j,0,0};
            }
            else if(maps[i][j] == 'E'){
                end = {i,j,1,0};
            }
        }
    }

    queue<spotInfo> bfsQ;
    bfsQ.push(start);
    visited[start.y][start.x][start.lFlag] = 1;

    for(;!bfsQ.empty();){
        int curY = bfsQ.front().y;
        int curX = bfsQ.front().x;
        bool curFlag = bfsQ.front().lFlag;
        int curMove = bfsQ.front().move;
        bfsQ.pop();

        for(int i=0; i<4; i++){
            int nextY = curY + dir[i];
            int nextX = curX + dir[3-i];

            if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m){
                continue;
            }

            if(nextY == end.y && nextX == end.x && curFlag == end.lFlag){
                return curMove + 1;
            }

            if(maps[nextY][nextX] == 'O' && !visited[nextY][nextX][curFlag]){
                visited[nextY][nextX][curFlag] = 1;
                bfsQ.push({nextY,nextX,curFlag,curMove+1});
            }
            else if(maps[nextY][nextX] == 'L' && !visited[nextY][nextX][1]){
                visited[nextY][nextX][1] = 1;
                bfsQ.push({nextY,nextX,1,curMove+1});
            }
        }

    }

    return -1;
}
*/