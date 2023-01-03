#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    bool lostStu[31]={0};
    bool lendable[31]={0};
    int i;
    
    int size = lost.size();
    
    for(i=0; i<size; i++){
        lostStu[lost[i]] =1;
    }
    
    size = reserve.size();
    
    for(i=0; i<size; i++){
        lendable[reserve[i]] =1;
    }
    
    for(i=1; i<=n; i++){
        if(lostStu[i] && lendable[i]){
             lostStu[i] = lendable[i] = 0;  
        }
    }
    
    for(i=1; i<=n; i++){
        
        
        /* if(lostStu[i] && lendable[i]){
             lostStu[i] = lendable[i] = 0;  
        } --> 빌려주지 못하는 경우를 먼저 처리해야 한다.*/
        if(i>1 && lostStu[i] && lendable[i-1]){
             lostStu[i] =lendable[i-1] = 0;  
        }
        else if(i<30 && lostStu[i] && lendable[i+1]){
           lostStu[i] = lendable[i+1] =0;  
        }
    }
    

    int answer = 0;
    
    for(i=1; i<=n; i++){
        if(!lostStu[i]){
            answer++;
        }
    }

    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    bool lostStu[32]={0};
    bool lendable[32]={0};
    int i;
    
    int size = lost.size();
    
    for(i=0; i<size; i++){
        lostStu[lost[i]] =1;
    }
    
    size = reserve.size();
    
    for(i=0; i<size; i++){
        lendable[reserve[i]] =1;
    }
    
    for(i=1; i<=n; i++){
        if(lostStu[i] && lendable[i]){
             lostStu[i] = lendable[i] = 0;  
        }
    }
    
    for(i=1; i<=n; i++){
        if(lostStu[i] && lendable[i-1]){
             lostStu[i] =lendable[i-1] = 0;  
        }
        else if(lostStu[i] && lendable[i+1]){
           lostStu[i] = lendable[i+1] =0;  
        }
    }
    

    int answer = 0;
    
    for(i=1; i<=n; i++){
        if(!lostStu[i]){
            answer++;
        }
    }

    return answer;
}
*/