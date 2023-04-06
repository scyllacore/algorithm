#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int ratioA[] = { 2,1,3 };
int ratioB[] = { 3,2,4 }; // 1. 2,3 2,4 3,4 �ε� 2,4�� 1,2�� �ٲ�. �������� �������� 1,2�� ǥ���� ���� ������, ���� �� �̷��� �ؾ��ϴ����� ��.

long long solution(vector<int> weights) {

    unordered_map<int, int> pairMap;
    unordered_set<int> weightSet; // 2. set�� Ȱ���Ͽ� map���� �߻��Ǵ� ���� �ذ�

    for (int weight : weights) {
        pairMap[weight]++;
        weightSet.insert(weight);
    }

    long long answer = 0;

    for (int weightA : weightSet) {
        long long weightCount = pairMap[weightA]; // 3. ��� �ڷ����� ��� �Ʒ����� ������ ���������� �� �� �ִ��� �����Ͽ� �ڷ����� ���ؾ��Ѵ�.
        answer += (weightCount * (weightCount - 1) / 2); // 4. nCr�� r�� 2�� ���� �������� n(n-1)/2���� �ϼ���

        for (int i = 0; i < 3; i++) {
            if (weightA % ratioA[i] != 0) { // 5-1.  �̰� �����ؾ�
                continue;
            }

            int weightB = (weightA / ratioA[i]) * ratioB[i];
            // 5-2. 180(weightA) * 4(ratioB) = 360(weightB) * 2(ratioA) �� ������ ���������� �� �� �ִ�.
            answer += weightCount * pairMap[weightB];
        }

        // 6. ������ ���� weightA�� weightB�� �ٲ� ���Ǵ� ��쵵 �ݵ�� ����� �� ����ص���. 360(weightA) * 4(ratioB) = 180(weightB) * 2(ratioA)

    }
    return answer;
}


/*
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int ratio1[] = {2,1,3};
int ratio2[] = {3,2,4}; // 23 24 34 �ε� 24�� 12�� �ٲ�. �������� �������� 12�� ǥ���� ���� ������, ���� �� �̷��� �ؾ��ϴ����� ��.

long long solution(vector<int> weights) {

    unordered_map<int,int> pairMap;

    for(int weight : weights){
        pairMap[weight]++;
    }

    long long answer = 0;

    for(auto pairInfo : pairMap){
        int weightA = pairInfo.first;
        int weightCount = pairInfo.second;
        answer += weightCount * (weightCount-1)/2; // nCr�� r�� 2�� ���� �������� n(n-1)/2���� �ϼ���

        cout << weightA <<  ' ';

        for(int i=0; i<3; i++){
            if(weightA % ratio1[i] != 0){
                continue;
            }

            int weightB = (weightA / ratio1[i]) * ratio2[i];
            cout << weightB <<  '\n';

            answer += weightCount * pairMap[weightB] * 1LL;

            * pairMap[weightB]���� ���� map�� �����Ͱ� �߰� ������ �������� ������ �� �� ����.
        }
        cout << '\n';

    }
    return answer;
}
*/