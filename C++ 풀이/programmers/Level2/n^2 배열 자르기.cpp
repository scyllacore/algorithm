#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i=left; i<=right; i++){
        int row = i/n+1;
        int col = i%n+1;
        if(col<=row){answer.push_back(row);}
        else{answer.push_back(col);}
        // 규칙 다시 정리하고 max사용해서 풀이하는 법 분석 할 것
    }
    
    return answer;
}