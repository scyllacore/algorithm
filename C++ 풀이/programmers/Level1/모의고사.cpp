#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    int supo1[5] = {1, 2, 3, 4, 5};
    int supo2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int supo3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int scoreCnt[3]= {0};
    
    int i;
    int size= answers.size();
    
    for(i=0; i<size; i++){
        if(answers[i] == supo1[i%5] ) scoreCnt[0]++;
        if(answers[i] == supo2[i%8] ) scoreCnt[1]++;
        if(answers[i] == supo3[i%10] ) scoreCnt[2]++;
    }    
    
    int maxVal = *max_element(scoreCnt,scoreCnt+3);
    
    vector<int> answer;
    
    for(i=0; i<3; i++){
        if(maxVal == scoreCnt[i])
            answer.push_back(i+1);
    }
    
    return answer;
}