#include <string>
#include <vector>
//#include <algorithm>

using namespace std;

bool solution(string s) { 
    
    bool answer = true;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            answer = false;
    }

    return s.size() == 4 || s.size() == 6 ? answer : false;
}

/*  
    sort(s.begin(),s.end());  
    
    bool answer = false;
    int len=s.length();
    
    if((len == 4 || len == 6) && (s[0]>='0' && s[0]<='9') && (s[len-1]>='0' && s[len-1]<='9'))
    {
        answer = true;
    }
   
    return answer;
}
*/