#include <string>
#include <vector>

using namespace std;

vector<int> numbers;
int answer,target,cnt;

void DFS(int depth,int sum){
    
    if(depth>=cnt){       
        if(target== sum){answer++;}
        return;
    }
    
   DFS(depth+1,sum+numbers[depth]);
   DFS(depth+1,sum-numbers[depth]);        
    
}

int solution(vector<int> n, int t) {
    numbers =n,target=t;
    cnt = numbers.size();
    answer = 0;
    
    DFS(0,0);
    
    return answer;
}

//비트 마스크 풀이 가능