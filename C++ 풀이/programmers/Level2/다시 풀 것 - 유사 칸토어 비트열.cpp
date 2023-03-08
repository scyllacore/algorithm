#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long countNumberOne(long long idx) {

    long long result = 0;
    int exp = 0; // exp는 규칙적인 범위를 지정할 때 사용된다. 위치가 아니다. 또 이를 통해 어떠한 n으로 비트열을 만들어 냈는지 알 수 있다.

    for (; (long long)(pow(5, exp + 1)) < idx; exp++) {} // idx 위치를 이용해 규칙적인 범위를 찾는다. 이를 위해 exp+1을 해줘서 idx의 범위를 벗어나는 경우로 규칙 범위를 찾는다.

    if (exp == 0) { // 규칙 범위가 없는 경우이다. 마지막 부분만 남았다.
        return idx < 3 ? idx : idx - 1;
    }

    long long quotient = idx / (long long)pow(5, exp);// n은 exp+1이다. exp(n-1)의 값을 이용해 n상태에서 처음부터 idx까지 규칙적으로 1이 나오는 구간과, 1이 어떠한 식으로 배치되어있는지 확인할 수 있다.  
    long long remainder = (quotient + 1 != 3 ? idx % (long long)pow(5, exp) : 0); // 규칙적이지 않은 구간이다. 다시 재귀를 돌릴 때 사용한다.

    if (quotient >= 3) {
        result += (quotient - 1) * (long long)pow(4, exp); // 범위 중간에 0이 끼어져 있는 경우로 0을 제외하고 1의 개수를 센다.
    }
    else {
        result += (long long)(quotient * pow(4, exp));
    }

    return result + countNumberOne(remainder);

}

int solution(int n, long long l, long long r) {
    return countNumberOne(r) - countNumberOne(l - 1);
}

//https://nxnaxx.github.io/algorithm/%EC%9C%A0%EC%82%AC-%EC%B9%B8%ED%86%A0%EC%96%B4-%EB%B9%84%ED%8A%B8%EC%97%B4/algorithm-solution/

//분할 정복