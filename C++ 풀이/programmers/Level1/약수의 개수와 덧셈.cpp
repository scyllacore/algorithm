#include <string>
#include <vector>

using namespace std;

int divisor(int n){
    
    int i;
    int cnt=0;
    
    for(i=1; i<=n/i; i++){
        if(n%i == 0){
           cnt++;    
            if(n/i != i){  // 속도를 줄이고 싶다면 반드시 이 형태로 쓸 것.
                cnt++;
            }
            
        }
    }
    
    return cnt;
    /*
    int i;
    int cnt = 0;
    int n = 10;

    for (i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            cnt += 2;
        }
    }

    i--;

    if (n / i == i) {
        cnt--;
    }

    cout << cnt; 안 되는 코드
    */
    
}


int solution(int left, int right) {
    
    int i;
    int answer=0;
    int tmp;
    
    for(i=left; i<=right; i++){
        tmp = divisor(i);
        
        if(tmp%2==0){
            answer += i;
        }
        else{
            answer -= i;
        }
        
        
    }
    
    return answer;
}