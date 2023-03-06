#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    for (long long x = 0; x * k <= d; x++) {
        double yDis = sqrt((long long)d * d - (x * k) * (x * k));
        //sqrtl도 있다. d*d가 int 형을 벗어나 형변환을 해줘야 하지만, 해주지 않아 오답이 났다. 
        answer += (long long)(yDis / k) + 1; // floor나 강제형변환을 통해 소수 부분을 제거해줘야한다.
    }
    return answer;

}

//★ 형이 변경되어야 하는 계산 값들을 잘 확인하자.


/*
for(long long x=0; x*k<=d; x++){
    long long yDis = d*d - (x*k) * (x*k);

    answer += (long long)sqrt(yDis)/k + 1;
}
*/

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    for(long long x=0; x*k<=d; x++){
        for(long long y=0; y*k<=d ;y++){
            long long dis = (x*k) * (x*k) + (y*k) * (y*k);
            if(dis > (long long)d*d){
                break;
            }
            //cout << x << ' ' << y << '\n';
            answer++;
        }
    }

    return answer;

}
*/