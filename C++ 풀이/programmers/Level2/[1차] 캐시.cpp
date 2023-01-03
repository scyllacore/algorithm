#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int i;
    
    deque<string> LRU;
    
    for(i=0; i<cities.size(); i++){
        transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::tolower);
    }
    
    for(i=0; i<cities.size(); i++){
        
        auto pos = find(LRU.begin(),LRU.end(),cities[i]);
        
        if(pos != LRU.end()){
            LRU.erase(pos);
            LRU.push_back(cities[i]);
            answer++;
        }
        else{
            if(LRU.size() == cacheSize){
                LRU.push_back(cities[i]);
                LRU.pop_front();
            }
            else if(cacheSize!=0){
                LRU.push_back(cities[i]);
            }
            answer+=5;
        }
    }
    
    return answer;
}