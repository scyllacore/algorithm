#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int idx;

bool cmp(const string&s1 ,const string&s2){
    if(s1[idx]!=s2[idx]){
        return s1[idx]<s2[idx];
    }
    else{
        return s1.compare(s2) < 0;
    }
    
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(),strings.end(),cmp);
    
    return strings;
}