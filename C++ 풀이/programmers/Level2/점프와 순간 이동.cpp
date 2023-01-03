#include <deque>

using namespace std;

int solution(int n)
{
    int ans = 0;
 
    for(;n>0;){
        ans+=n%2;
        n/=2;
    }
    
    return ans;
}

/*
#include <deque>

using namespace std;

int solution(int n)
{
    int ans = 0;
 
    for(;n>0;){
        if(n%2 != 0){
            n--;
            ans++;
        }
        n=n/2;
    }
    
    return ans;
}
*/