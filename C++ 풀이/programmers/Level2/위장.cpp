#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map <string,int> categoryMap;
    
    for(auto category : clothes){categoryMap[category[1]]++; }
    
    int answer = 1;  
    for(auto combi : categoryMap){ answer *= (combi.second+1);}
        
    return answer-1;
}