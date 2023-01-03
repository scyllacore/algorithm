#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    int i,j;
    int size=numbers.size();
    
    vector<int> answer;
    
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            answer.push_back(numbers[i]+numbers[j]);
        }
    }
    
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    
    return answer;
}