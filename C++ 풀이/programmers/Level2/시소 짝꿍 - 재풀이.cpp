#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int ratio1[] = { 2,1,3 };
int ratio2[] = { 3,2,4 };

long long solution(vector<int> weights) {
    long long answer = 0;

    unordered_map<int, int> weightMap;
    unordered_set<int> weightSet;

    for (int weight : weights) {
        weightMap[weight]++;
        weightSet.insert(weight);
    }

    for (int weight : weightSet) {
        long long weightCount = weightMap[weight];
        answer += weightCount * (weightCount - 1) / 2;

        for (int i = 0; i < 3; i++) {

            if (weight % ratio2[i]) {
                continue;
            }

            int anotherWeight = weight / ratio2[i] * ratio1[i];
            // r1 : r2 = w1 :w2 , r1 : r2 = w2 : w1
            // w1 = r1*w2/r2 , w2 = r1*w1/r2 
            // w1과 w2의 순서과 반대로 바뀌는 상황도 생각한다. 즉 w1을 가지고 w2를 구하는 상황과 w2를 가지고 w1를 구하는 상황을 모두 반영한다.
            answer += weightMap[anotherWeight] * weightCount;
        }
    }

    return answer;

}