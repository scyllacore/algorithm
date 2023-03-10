#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {

    int answer = 0;

    for (int curIdx = 0; curIdx < section.size();) {

        int curSec = section[curIdx];

        int nextIdx = curIdx;
        for (; nextIdx < section.size(); nextIdx++) {
            int nextSec = section[nextIdx];

            if (nextSec >= curSec + m) {
                break;
            }
        }
        curIdx = nextIdx;
        answer += 1;
    }

    return answer;

}