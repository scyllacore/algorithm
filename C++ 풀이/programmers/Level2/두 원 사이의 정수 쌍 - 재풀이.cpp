#include <cmath>

using namespace std;

bool isInteger(double val) {
    return val == (long long)val;
}

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int x = 1; x < r2; x++) { // x<=r2 x가 r2가 되도 cnt가 0이 나와서 상관은 없음
        double inner = sqrt(powl(r1, 2) - powl(x, 2));
        double outer = sqrt(powl(r2, 2) - powl(x, 2));
        long long ySpotCnt = (long long)outer - (long long)inner;

        if (isInteger(inner)) {
            ySpotCnt++;
        }

        answer += 4 * ySpotCnt;
    }

    return answer + 4 * (r2 - r1);
}