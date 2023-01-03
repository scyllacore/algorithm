#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& s1,const string& s2){
    return (s1+s2).compare(s2+s1) > 0;  
}

string solution(vector<int> numbers) {
    
    vector<string> numStr; 
    
    for(auto iter : numbers){
        numStr.push_back(to_string(iter));
    }
    
    sort(numStr.begin(),numStr.end(),cmp);
  
    string answer = "";
    
    for(auto iter : numStr){
        answer += iter;
    }
    
     if (answer[0] == '0')
        answer = '0';
    
    return answer;
}