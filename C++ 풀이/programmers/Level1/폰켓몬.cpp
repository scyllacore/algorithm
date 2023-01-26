#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    return min(nums.size() / 2, s.size());
}

/*
#include <bits/stdc++.h>

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



*/