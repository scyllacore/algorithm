#include <string>
#include <vector>

using namespace std;

vector<int> answer;
vector<vector<int>> arr;

bool isSame(int y,int x,int size){

    int i,j;
    
    for(i=y; i<y+size; i++){
        for(j=x; j<x+size; j++){
            if(arr[y][x] != arr[i][j]) return 0;
        }
    }

    return 1;
}


void DFS(int y,int x, int size){
    
    if(isSame(y,x,size)){
        answer[arr[y][x]]++;
        return;   
    }
    
    DFS(y,x,size/2);
    DFS(y,x+size/2,size/2);
    DFS(y+size/2,x,size/2);
    DFS(y+size/2,x+size/2,size/2);
        
}

vector<int> solution(vector<vector<int>> a) {
    arr = a;
    answer.assign(2,0);
    
    DFS(0,0,arr.size());
    
    return answer;
}