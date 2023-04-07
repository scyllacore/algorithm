#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

struct idxPairInfo {
    int start, end;
};

bool cmp(idxPairInfo& i1, idxPairInfo& i2) {
    if (i1.end - i1.start == i2.end - i2.start) {
        return i1.start < i2.start;
    }

    return i1.end - i1.start < i2.end - i2.start;
}

vector<int> solution(vector<int> sequence, int k) {

    unordered_map<int, int> sumMap;
    unordered_set<int> sumSet; // ����1�� ���� �ذ�. �̿� ���� set�� ����Ͽ� �������� sequence ���� ����� �� �ֵ��� �Ͽ���.

    int idx = 1;

    sumMap[0] = idx++;

    for (int i = 1; i < sequence.size(); i++) {
        sequence[i] += sequence[i - 1];
    }

    for (int i = 0; i < sequence.size(); i++) {
        sumMap[sequence[i]] = idx++;
        sumSet.insert(sequence[i]);
    }

    vector<idxPairInfo> idxPair;

    for (int sumInfo : sumSet) {
        int curVal = sumInfo;
        int curIdx = sumMap[sumInfo];

        if (curVal - k < 0) {
            continue;
        }

        int preIdx = sumMap[curVal - k]; // ����1. �����ϸ鼭 map�� �����Ͱ� �߰��ȴ�.

        if (preIdx) {
            idxPair.push_back({ preIdx - 1,curIdx - 2 });
        }
    }

    if (idxPair.empty()) {
        return vector<int>{};
    }

    sort(idxPair.begin(), idxPair.end(), cmp);

    return vector<int>{idxPair[0].start, idxPair[0].end};

}

//map ���� �� �˾� �� ��.
//�̺� Ž�� �������� �� ������ �ٽ� ���� �� ��.