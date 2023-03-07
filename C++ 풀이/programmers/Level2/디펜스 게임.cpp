#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int& a, int& b) {
        return a > b;
    }
};

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, cmp> pq;

    int sum = 0;

    for (int i = 0; i < enemy.size(); i++) {

        int e = enemy[i];
        pq.push(e);
        // pq에는 무적권을 쓸 라운드에 대한 정보를 담는다.

        if (pq.size() > k) {
            // 만약 무적권을 쓸 수 있는 수량이 넘어가면 
            sum += pq.top(); //가장 적이 적은 라운드를 선택하여 병사를 소모하고.
            pq.pop();// 그 라운드를 무적권 pq에서 빼버린다.
        }
        // 결국 pq는 최적으로 무적권 라운드를 선택한다.

        if (sum > n) { // 이에 따라 sum은 최적의 병사 소모값을 가지고 있으며 만약 이값이 넘어갈 시
            return i; // 더 이상 소모할 수 있는 병사가 없는 것임으로 현재 라운드를 반환한다.
        }
    }

    return enemy.size();
}