#include <string>
#include <vector>

using namespace std;

vector<string> originBoard;

char spot[2] = { 'O','X' };

bool same(vector<string>& tmpBoard) {

    int cntDia = 0;
    int cntRevDia = 0;

    for (int i = 0; i < 3; i++) {
        int cntRow = 0;
        int cntCol = 0;

        for (int j = 0; j < 3; j++) {
            if (tmpBoard[i][0] != '.' && tmpBoard[i][j] == tmpBoard[i][0]) {
                cntRow++;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (tmpBoard[0][i] != '.' && tmpBoard[j][i] == tmpBoard[0][i]) {
                cntCol++;
            }
        }

        if (cntRow == 3 || cntCol == 3) {
            return 1;
        }

        if (tmpBoard[0][0] != '.' && tmpBoard[i][i] == tmpBoard[0][0]) {
            cntDia++;
        }

        if (tmpBoard[0][2] != '.' && tmpBoard[i][2 - i] == tmpBoard[0][2]) {
            cntRevDia++;
        }


    }

    if (cntDia == 3 || cntRevDia == 3) {
        return 1;
    }

    return 0;
}

bool check(vector<string>& tmpBoard) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tmpBoard[i][j] != originBoard[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int dfs(vector<string>& tmpBoard, int depth) {

    if (check(tmpBoard)) {
        return 1;
    }

    if (same(tmpBoard)) {
        return 0;
    }

    for (int i = 0; i < 9; i++) {
        int y = i / 3;
        int x = i % 3;

        if (tmpBoard[y][x] == '.') {
            tmpBoard[y][x] = spot[depth % 2];
            if (dfs(tmpBoard, depth + 1)) {
                return 1;
            }
            tmpBoard[y][x] = '.';
        }
    }

    return 0;
}

int solution(vector<string> board) {
    originBoard = board;

    vector<string> tmpBoard = {
        "...",
        "...",
        "..."
    };

    return dfs(tmpBoard, 0);
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> originBoard;

char spot[2] = {'O','X'};

bool same(vector<string>& tmpBoard){
    for(int i=0; i<3; i++){
        int cnt = 0;

        for(int j=0; j<3; j++){
            if(tmpBoard[i][0] != '.' && tmpBoard[i][j] == tmpBoard[i][0]){
                cnt++;
            }
        }

        if(cnt == 3){
            return 1;
        }
    }

    for(int i=0; i<3; i++){
        int cnt = 0;

        for(int j=0; j<3; j++){
            if(tmpBoard[0][i] != '.' && tmpBoard[j][i] == tmpBoard[0][i]){
                cnt++;
            }
        }

        if(cnt == 3){
            return 1;
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;

     for(int i=0; i<3; i++){


         if(tmpBoard[0][0] != '.' && tmpBoard[i][i] == tmpBoard[0][0]){
             cnt1++;
         }

         if(tmpBoard[0][2] != '.' && tmpBoard[i][2-i] == tmpBoard[0][2]){
             cnt2++;
         }
    }

    if(cnt1 == 3 || cnt2 == 3){
           return 1;
     }

    return 0;
}

bool check(vector<string>& tmpBoard){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tmpBoard[i][j] != originBoard[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

int dfs(vector<string>& tmpBoard,int start,int depth){

    if(check(tmpBoard)){
        return 1;
    }

    if(same(tmpBoard)){
        return 0;
    }

    for(int i=start; i<9; i++){
        int y = i/3;
        int x = i%3;

        if(tmpBoard[y][x] == '.'){
            tmpBoard[y][x] = spot[depth%2];
            if(dfs(tmpBoard,i+1,depth+1)){
                return 1;
            }#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> originBoard;

char spot[2] = {'O','X'};

bool same(vector<string>& tmpBoard){
    for(int i=0; i<3; i++){
        int cnt = 0;

        for(int j=0; j<3; j++){
            if(tmpBoard[i][0] != '.' && tmpBoard[i][j] == tmpBoard[i][0]){
                cnt++;
            }
        }

        if(cnt == 3){
            return 1;
        }
    }

    for(int i=0; i<3; i++){
        int cnt = 0;

        for(int j=0; j<3; j++){
            if(tmpBoard[0][i] != '.' && tmpBoard[j][i] == tmpBoard[0][i]){
                cnt++;
            }
        }

        if(cnt == 3){
            return 1;
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;

     for(int i=0; i<3; i++){


         if(tmpBoard[0][0] != '.' && tmpBoard[i][i] == tmpBoard[0][0]){
             cnt1++;
         }

         if(tmpBoard[0][2] != '.' && tmpBoard[i][2-i] == tmpBoard[0][2]){
             cnt2++;
         }
    }

    if(cnt1 == 3 || cnt2 == 3){
           return 1;
     }

    return 0;
}

bool check(vector<string>& tmpBoard){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tmpBoard[i][j] != originBoard[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

int dfs(vector<string>& tmpBoard,int start,int depth){

    if(check(tmpBoard)){
        return 1;
    }

    if(same(tmpBoard)){
        return 0;
    }

    for(int i=start; i<9; i++){
        int y = i/3;
        int x = i%3;

        if(tmpBoard[y][x] == '.'){
            tmpBoard[y][x] = spot[depth%2];
            if(dfs(tmpBoard,i+1,depth+1)){
                return 1;
            }
            tmpBoard[y][x] = '.';
        }
    }

    return 0;
}

int solution(vector<string> board) {
    originBoard = board;

    vector<string> tmpBoard= {
        "...",
        "...",
        "..."
    };

    return dfs(tmpBoard,0,0);
}
            tmpBoard[y][x] = '.';
        }
    }

    return 0;
}

int solution(vector<string> board) {
    originBoard = board;

    vector<string> tmpBoard= {
        "...",
        "...",
        "..."
    };

    return dfs(tmpBoard,0,0);
}


#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> originBoard;

char spot[2] = {'O','X'};

bool same(vector<string>& tmpBoard){
    for(int i=0; i<3; i++){
        int cnt = 0;

        for(int j=0; j<3; j++){
            if(tmpBoard[i][0] != '.' && tmpBoard[i][j] == tmpBoard[i][0]){
                cnt++;
            }
        }

        if(cnt == 3){
            return 1;
        }
    }

    for(int i=0; i<3; i++){
        int cnt = 0;

        for(int j=0; j<3; j++){
            if(tmpBoard[0][i] != '.' && tmpBoard[j][i] == tmpBoard[0][i]){
                cnt++;
            }
        }

        if(cnt == 3){
            return 1;
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;

     for(int i=0; i<3; i++){


         if(tmpBoard[0][0] != '.' && tmpBoard[i][i] == tmpBoard[0][0]){
             cnt1++;
         }

         if(tmpBoard[0][2] != '.' && tmpBoard[i][2-i] == tmpBoard[0][2]){
             cnt2++;
         }
    }

    if(cnt1 == 3 || cnt2 == 3){
           return 1;
     }

    return 0;
}

bool check(vector<string>& tmpBoard){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tmpBoard[i][j] != originBoard[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

int dfs(vector<string>& tmpBoard,int start,int depth){

    if(check(tmpBoard)){
        return 1;
    }

    if(same(tmpBoard)){
        return 0;
    }

    for(int i=start; i<9; i++){
        int y = i/3;
        int x = i%3;

        if(tmpBoard[y][x] == '.'){
            tmpBoard[y][x] = spot[depth%2];
            if(dfs(tmpBoard,i+1,depth+1)){
                return 1;
            }
            tmpBoard[y][x] = '.';
        }
    }

    return 0;
}

int solution(vector<string> board) {
    originBoard = board;

    vector<string> tmpBoard= {
        "...",
        "...",
        "..."
    };

    return dfs(tmpBoard,0,0);
}*/