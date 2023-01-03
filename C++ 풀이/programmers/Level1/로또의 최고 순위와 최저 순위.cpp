#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    int lottoCnt[46] ={0};
    int winCnt[46] ={0};
    int i;
    
    for(i=0; i<6; i++){
        lottoCnt[lottos[i]]++;
        winCnt[win_nums[i]]++;
    }
    
    vector<int> answer(2,0);
    
    for(i=1; i<=45; i++){
        if(lottoCnt[i]==1 &&winCnt[i] == 1){
            answer[1]++;
        }
    }
    
    answer[0] += answer[1]+lottoCnt[0];
    
    for(i=0; i<2; i++){
        if(answer[i]>=2){
            answer[i] = 7-answer[i];
        }
        else{
            answer[i] = 6;
        }
    }
    
    
    
    return answer;
}