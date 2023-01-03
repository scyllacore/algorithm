#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const char& ch1,const char& ch2){
    return ch1>ch2;
}

string solution(string s) {
    sort(s.begin(),s.end(),cmp); 
    return s;
}