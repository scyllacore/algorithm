#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {

    sort(targets.begin(), targets.end(), cmp);

    int answer = 1;
    int s = targets[0][0];
    int e = targets[0][1];

    for (int i = 1; i < targets.size(); i++) {
        if (targets[i][0] >= e) {
            answer++;
            e = targets[i][1];
        }
    }

    return answer;
}