#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int solution(string dartResult) {
      
    int i,len=dartResult.length();
    vector<int> score;
    int sum=0;
    int size;
    
    for(i=0; i<len; i++){
        
        if(dartResult[i]>='0' && dartResult[i]<='9'){
            sum = sum*10 + (dartResult[i]-'0');
        }
        else if(dartResult[i]>='A' && dartResult[i]<='Z'){
            score.push_back(sum);
            sum =0;
            
            size=score.size();
            
            if(dartResult[i] == 'D'){
                score[size-1] = score[size-1]*score[size-1];     
            }
            else if(dartResult[i] == 'T'){
                score[size-1] = score[size-1]*score[size-1]*score[size-1];     
            }   
        }
        else{
            if(dartResult[i]=='*'){
                 score[size-1] *=2;
                
                if(size>=1){
                    score[size-2] *=2;
                }       
            }
            else if(dartResult[i]=='#'){  
                 score[size-1] *= -1;       
            }
        }
             
    }
    
    int answer = accumulate(score.begin(),score.end(),0);
    
    return answer;
}