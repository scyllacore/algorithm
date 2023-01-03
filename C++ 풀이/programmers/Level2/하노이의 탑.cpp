#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void hanoi(int n,int start,int via,int to){
    
    if(n==1){
       answer.push_back({start,to}); 
       return; 
    }
    
    hanoi(n-1,start,to,via);
    answer.push_back({start,to}); 
    hanoi(n-1,via,start,to);    
    
}

vector<vector<int>> solution(int n) {
    
    hanoi(n,1,2,3);
    return answer;
}