#include <vector>
#include <string>

using namespace std;

bool solution(string s)
{
    vector<char> VPSstack;
    
    for(auto ch : s){
        if(!VPSstack.empty() && VPSstack.back() == '(' && ch == ')'){
            VPSstack.pop_back();
        }
        else{ VPSstack.push_back(ch);}
       
    }
    
    
    return VPSstack.empty();
}