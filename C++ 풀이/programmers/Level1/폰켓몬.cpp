#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    
    int originSize = nums.size();
    
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    
    int changedSize = nums.size();
    
    int answer = changedSize;
    
    if( changedSize > originSize/2){
        answer = originSize/2;
    }
    
    return answer;
}