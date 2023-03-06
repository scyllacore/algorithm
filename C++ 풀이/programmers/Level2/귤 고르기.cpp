#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct tangerineInfo {
    int size;
    int count;
};

bool cmp(tangerineInfo& t1, tangerineInfo& t2) {
    return t1.count > t2.count;
}

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> sizeCount;

    for (int size : tangerine) {
        sizeCount[size]++;
    }

    vector<tangerineInfo> infoV;

    for (auto sc : sizeCount) {
        infoV.push_back({ sc.first,sc.second });
    }

    sort(infoV.begin(), infoV.end(), cmp);

    for (int i = 0; ; i++) {
        if (k - infoV[i].count <= 0) {
            return i + 1;
        }
        k -= infoV[i].count;
    }

    return 0;

}