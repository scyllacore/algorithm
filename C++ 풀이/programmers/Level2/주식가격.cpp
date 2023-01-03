#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int i,j;
    int size = prices.size();
    int sec;
    
    for(i=0; i<size; i++){
        sec = 0;
        for(j=i+1; j<size; j++){
            sec++;
            if(prices[i] > prices[j]) break;
        }
        answer.push_back(sec);
    }
    
    return answer;
}
*/