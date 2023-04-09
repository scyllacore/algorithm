#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define MAX (int)1e6

struct rangeInfo {
    int start, end;
};

bool cmp(rangeInfo r1, rangeInfo r2) {
    if (r1.end - r1.start == r2.end - r2.start) {
        return r1.start < r2.start;
    }

    return r1.end - r1.start < r2.end - r2.start;
}

int dp[MAX + 1] = { 0 };

vector<int> solution(vector<int> sequence, int k) {
    int size = sequence.size();

    dp[1] = sequence[0];
    for (int i = 1; i < size; i++) {
        sequence[i] += sequence[i - 1];
        dp[i + 1] = sequence[i];
    }

    unordered_map<int, int> sequenceMap;
    unordered_set<int> sequenceSet;

    vector<rangeInfo> answer;

    sequenceMap[0] = 1;
    int idx = 2;
    for (int i = 1; i <= size; i++) {
        sequenceMap[dp[i]] = idx++;
        sequenceSet.insert(dp[i]);
    }

    for (int val : sequenceSet) {
        if (val - k < 0) {
            continue;
        }
        
        int end = sequenceMap[val];
        int start = sequenceMap[val - k];

        if (start) {
            answer.push_back({ start - 1,end - 2 });
        }
    }

    sort(answer.begin(), answer.end(), cmp);

    return vector<int>{answer[0].start, answer[0].end};
}