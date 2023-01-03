#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
   string answer = "";
    
    int maxIdx = -1;
    for(int i=0; i<number.size()-k; i++){
        char maxN=0;
        for(int j=maxIdx+1; j<=k+i; j++){
            if(maxN < number[j]){
                maxN = number[j];
                maxIdx = j;
            }
        }
        answer += maxN;
    }
	return answer;
}