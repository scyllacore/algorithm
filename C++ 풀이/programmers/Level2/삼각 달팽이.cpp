#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> triangle(n);
    
    int i,j;
    
    for(i=1; i<=n; i++){
        triangle[i-1] = vector<int>(i,0); // 이것도 가능하다.      
    }
    
    int len = n;
    int y=-1,x=0;
    int cnt = 1;
    
    for(;len>0;){
        
        for(i=0; i<len; i++){
            triangle[++y][x] = cnt++;
        }
        
        len--;
        
         for(i=0; i<len; i++){
            triangle[y][++x] = cnt++;
        }
        
        len--;
        
         for(i=0; i<len; i++){
            triangle[--y][--x] = cnt++;
        }   
        
        len--;
    }
    
   vector<int> answer;
    
     for(i=0; i<triangle.size(); i++){
        for(j=0; j<triangle[i].size(); j++){
            answer.push_back(triangle[i][j]);
        }
    }
  
    return answer;
}