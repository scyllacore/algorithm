#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int n) {
    int i;
    vector<int> arr;
    
    for(i=1; i<=n/i; i++){  
        if(n%i == 0){
            arr.push_back(i);
            
            if(i != n/i){
                arr.push_back(n/i);
            }      
        }        
    }
    
    int answer = accumulate(arr.begin(),arr.end(),0); 
    return answer;
}