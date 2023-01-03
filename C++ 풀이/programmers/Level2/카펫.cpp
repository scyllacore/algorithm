#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
     for(int i=sqrt(yellow); i>0; i--){
        
        if(yellow%i == 0 &&  (yellow/i+2) * (i+2) - yellow  == brown){     
            answer.push_back(yellow/i+2);
            answer.push_back(i+2);
            break;
        }
        
    }
    
    return answer;
}


/*
  
    int sumBlock = brown + yellow;
    
    for(int i=sqrt(sumBlock); i>0; i--){
        
        if(sumBlock%i == 0){
            answer.push_back(sumBlock/i);
            answer.push_back(i);
            break;
        }
        
    }
*/