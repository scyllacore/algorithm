#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    unordered_set<int> us[9];
    
    int sum = 0;
    int i,j;
    
    for(i = 1; i <= 8; i++){
        sum = 10*sum + N;
        us[i].insert(sum);
    }
    
    for (i = 2; i <= 8; i++){
        for(j = 1; j < i; j++){
            for(int a : us[j]){
                for(int b : us[i-j]){
                    us[i].insert(a+b);
                    us[i].insert(a-b);
                    us[i].insert(a*b);
                    if(b != 0) us[i].insert(a/b);
                }
            }
        }
    }
    
    for(i = 1; i <= 8; ++i){
        if(us[i].find(number) != us[i].end()){
            return i;
        }  
    }
     
    return -1;  
}