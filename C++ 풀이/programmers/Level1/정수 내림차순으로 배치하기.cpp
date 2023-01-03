#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
   
    vector<int> tmp;
    
    for(;n>0;n/=10){
        tmp.push_back(n%10);
    }
    
    sort(tmp.begin(),tmp.end());
        
    long long answer = 0;
    
    for(;!tmp.empty();){
        answer = answer*10 + tmp.back();
        tmp.pop_back();
    }

    return answer;
}

/*
string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);*/