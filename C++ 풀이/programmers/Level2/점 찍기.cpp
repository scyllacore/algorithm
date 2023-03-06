#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    for (long long x = 0; x * k <= d; x++) {
        double yDis = sqrt((long long)d * d - (x * k) * (x * k));
        //sqrtl�� �ִ�. d*d�� int ���� ��� ����ȯ�� ����� ������, ������ �ʾ� ������ ����. 
        answer += (long long)(yDis / k) + 1; // floor�� ��������ȯ�� ���� �Ҽ� �κ��� ����������Ѵ�.
    }
    return answer;

}

//�� ���� ����Ǿ�� �ϴ� ��� ������ �� Ȯ������.


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