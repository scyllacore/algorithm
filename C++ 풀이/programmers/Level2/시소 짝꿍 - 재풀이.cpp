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
            // w1�� w2�� ������ �ݴ�� �ٲ�� ��Ȳ�� �����Ѵ�. �� w1�� ������ w2�� ���ϴ� ��Ȳ�� w2�� ������ w1�� ���ϴ� ��Ȳ�� ��� �ݿ��Ѵ�.
            answer += weightMap[anotherWeight] * weightCount;
        }
    }

    return answer;

}