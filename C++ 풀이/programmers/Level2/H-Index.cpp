#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
    sort(citations.begin(),citations.end());
    
    int answer = 0,i;
    
    for(i=0; i<citations.back(); i++){
        int pos = lower_bound(citations.begin(),citations.end(),i) - citations.begin();     
        
        /*
         if( citations.size()-pos >= i && pos + 1 <= i ){
            answer = i;
        }     
        */
        
        if( citations.size()-pos >= i){
            answer = i;
        }
        else{
            break;
        }
    }
    
    
    return answer;
}