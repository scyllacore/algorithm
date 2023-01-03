#include <algorithm>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.length();
    int move = n - 1;
    
    for (int i1 = 0; i1 < n; i1++) {
        if (name[i1] - 'A' < 14) answer += name[i1] - 'A';
        else answer += 'Z' - name[i1] + 1;

        int i2 = i1 + 1;
        for (;i2 < n && name[i2] == 'A';) i2++;

        move = min(move, i1 + n - i2 + min(i1, n - i2));
    }

    answer += move;
    return answer;
}
//https://4z7l.github.io/2021/03/12/algorithms-prg-42860.html