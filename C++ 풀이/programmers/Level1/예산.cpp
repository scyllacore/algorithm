#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    
    sort(d.begin(),d.end());
    
    int answer = 0;
    
    int i;
    int size=d.size();
    
    for(i=0; i<size && (budget-d[i])>=0; i++){
        answer++;
        budget -= d[i];
    }
    
    return answer;
}