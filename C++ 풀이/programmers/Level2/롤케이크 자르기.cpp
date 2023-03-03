#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

#define MAX (int)1e6

int leftCount[MAX + 1] = { 0 };
int rightCount[MAX + 1] = { 0 };

int solution(vector<int> topping) {

    unordered_set<int> leftSet;
    unordered_set<int> rightSet;

    int size = topping.size();
    int i;

    for (i = 1; i <= size; i++) {
        leftSet.insert(topping[i - 1]);
        leftCount[i] = leftSet.size();
    }

    for (i = size; i >= 1; i--) {
        rightSet.insert(topping[i - 1]);
        rightCount[i] = rightSet.size();
    }

    int answer = 0;

    for (i = 1; i <= size - 1; i++) {
        if (leftCount[i] == rightCount[i + 1]) {
            answer++;
        }
    }

    return answer;
}