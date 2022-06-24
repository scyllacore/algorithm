#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end(),less<>());
    sort(B.begin(),B.end(),greater<>());
    
    for(int i=0; i<A.size(); i++){
        answer += (A[i]*B[i]);
    }
    
    return answer;
}