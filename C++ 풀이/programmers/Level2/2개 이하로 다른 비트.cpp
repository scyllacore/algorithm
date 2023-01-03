#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0; i<numbers.size();i++){
        if(numbers[i]%2==0){
            answer.push_back(numbers[i]+1);
        }
        else{
           long long LSB = (numbers[i]+1) & -(numbers[i]+1); // 2의 보수화 사용
            // 9 예시
            // (0000 1001 -> 0000 1010 & 0000 1010 -> 1111 0101 -> 1111 0110) -> 0000 0010
            answer.push_back((numbers[i] | LSB) & (~(LSB>>1)));
            // (0000 1001 | 0000 0010 -> 0000 1011) & (0000 0010 -> 0000 0001 -> 1111 1110) -> 1010
        }
    }
    return answer;
}