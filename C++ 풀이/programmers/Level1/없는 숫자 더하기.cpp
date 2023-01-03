#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    
    bool check[10] = {0};
    
    int i;
    
    int size = numbers.size();
    
    for(i=0; i<size; i++){
        check[numbers[i]]=1;
    }
    
    int answer = 0;
    
    for(i=0; i<10; i++){
        if(check[i] == 0){
            answer+=i;   
        }
    }
    
    
    return answer;
}