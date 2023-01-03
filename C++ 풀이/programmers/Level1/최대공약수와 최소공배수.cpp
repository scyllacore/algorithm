#include <string>
#include <vector>

using namespace std;

int gcd(int a,int b){
    int tmp;
    
    while(b!=0){
        tmp = a%b;
        a=b;
        b=tmp;
    }
    
    return a;
    
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcdVal = gcd(n,m);
    int lcmVal = (n*m)/gcdVal;
    
    answer.push_back(gcdVal);
    answer.push_back(lcmVal);
    
    return answer;
}