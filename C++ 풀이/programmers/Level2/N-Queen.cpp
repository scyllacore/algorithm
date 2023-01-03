#include <string>
#include <vector>
#include <cmath>

int col[13],n;
int answer = 0;

bool check(int x,int depth){
    
    for(int i=1; i<depth; i++){
        if(x == col[i] || depth-i == abs(x-col[i])) return 0;
    }

    return 1;
}

void nQueenDFS(int depth){
    
    if(depth > n){
        answer++;
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(check(i,depth)){
            col[depth] = i;
            nQueenDFS(depth+1);
        }
    }
       
}

using namespace std;

int solution(int a) {
    n = a;
    nQueenDFS(1);
    
    return answer;
}