#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    int i;
    int size = absolutes.size();
    
    for(i=0; i<size; i++){
        if(signs[i] == 1){
            answer += absolutes[i];
        }else{
             answer += (absolutes[i]*-1);
        }
    }
    
    
    return answer;
}