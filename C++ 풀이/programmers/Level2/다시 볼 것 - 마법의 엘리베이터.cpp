#include <string>
#include <vector>

using namespace std;

int solution(int storey) {

    int answer = 0;

    for (; storey > 0;) {

        int cur = storey % 10;
        int next = (storey / 10) % 10;

        if (cur > 5) { // 1. 현재 자리가 5보다 클 경우, 10으로 접근했을 때 가까움.
            answer += 10 - cur;
            storey += 10;
        }
        else if (cur == 5) { //2. 현재 5일 경우 현재 자리만 봤을 때는 0,10 둘중 아무데나 접근해도 상관 없지만, 5를 더하여 다음 자리가 6 이상이 됐을 경우는 다음 자리는 10으로 접근했을 때 더 가깝게 접근할 수 있음. 이를 생각하여 위치 접근.   
            answer += 5;
            storey += next >= 5 ? 5 : 0; // 다음 자리인 next는 cur이 어떤 방향으로 위치를 선택했는지에 따라 가깝게 접근할 수 있는 위치가 변함으로 이를 염두해두어야한다. 현재 자리 5에 5를 더하는 경우와 더하지 않는 경우를 따져 다음 자리가 최대한 이득 볼 수 있는 경우를 따져야 한다.
        }
        else { // 3. 현재 자리가 5보다 작은 경우, 0으로 접근 했을 때 가까움.
            answer += cur;
        }

        storey /= 10;
    }

    return answer;

}