#include <string>
using namespace std;


int solution(string dirs) {
    
    bool visited[11][11][11][11] = {0};    
    int answer = 0;  
    
    int curY=5,curX=5;
    int preY,preX;
    
    for(auto dir : dirs){
        preY=curY , preX=curX;
        
        if(curY<=9 && dir == 'U') curY++;
        else if(curY>=1 && dir == 'D') curY--;
        else if(curX<=9 && dir == 'R') curX++;
        else if(curX>=1 && dir == 'L') curX--;
        else{ continue; }
      
        if(!visited[preY][preX][curY][curX] && !visited[curY][curX][preY][preX]){
            visited[preY][preX][curY][curX] = 1;
            visited[curY][curX][preY][preX] = 1;
            answer++;
        }
        
    }
    
    return answer;
}


/*
int solution(string dirs) {
    
    bool visited[11][11] = {0};
    
    int answer = 0;  
    
    int curY=5,curX=5;
    int preY,preX;
    
    for(auto dir : dirs){
        preY=curY , preX=curX;
        
        if(curY<=9 && dir == 'U') curY++;
        else if(curY>=1 && dir == 'D') curY--;
        else if(curX<=9 && dir == 'R') curX++;
        else if(curX>=1 && dir == 'L') curX--;
        else{ continue; }
      
        if(!visited[curY][curX] && !visited[preY][preX]){
            visited[preY][preX] = 1;
            answer++;
        }
        else if(visited[curY][curX] && !visited[preY][preX]){
            visited[preY][preX] = 1;
            answer++;
        }   
        else if(!visited[curY][curX]){
            answer++;
        } 
    }
    
    return answer;
}
*/