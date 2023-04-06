#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int ratioA[] = { 2,1,3 };
int ratioB[] = { 3,2,4 }; // 1. 2,3 2,4 3,4 인데 2,4는 1,2로 바꿈. 비율적인 값임으로 1,2로 표현할 수는 있지만, 굳이 왜 이렇게 해야하는지는 모름.

long long solution(vector<int> weights) {

    unordered_map<int, int> pairMap;
    unordered_set<int> weightSet; // 2. set을 활용하여 map으로 발생되는 버그 해결

    for (int weight : weights) {
        pairMap[weight]++;
        weightSet.insert(weight);
    }

    long long answer = 0;

    for (int weightA : weightSet) {
        long long weightCount = pairMap[weightA]; // 3. 어떠한 자료형을 써야 아래에서 연산을 정상적으로 할 수 있는지 생각하여 자료형을 정해야한다.
        answer += (weightCount * (weightCount - 1) / 2); // 4. nCr에 r이 2로 고정 값임으로 n(n-1)/2식이 완성됨

        for (int i = 0; i < 3; i++) {
            if (weightA % ratioA[i] != 0) { // 5-1.  이게 가능해야
                continue;
            }

            int weightB = (weightA / ratioA[i]) * ratioB[i];
            // 5-2. 180(weightA) * 4(ratioB) = 360(weightB) * 2(ratioA) 이 연산을 정상적으로 할 수 있다.
            answer += weightCount * pairMap[weightB];
        }

        // 6. 루프를 돌며 weightA와 weightB가 바껴 계산되는 경우도 반드시 생기는 걸 기억해두자. 360(weightA) * 4(ratioB) = 180(weightB) * 2(ratioA)

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
int ratio2[] = {3,2,4}; // 23 24 34 인데 24는 12로 바꿈. 비율적인 값임으로 12로 표현할 수는 있지만, 굳이 왜 이렇게 해야하는지는 모름.

long long solution(vector<int> weights) {

    unordered_map<int,int> pairMap;

    for(int weight : weights){
        pairMap[weight]++;
    }

    long long answer = 0;

    for(auto pairInfo : pairMap){
        int weightA = pairInfo.first;
        int weightCount = pairInfo.second;
        answer += weightCount * (weightCount-1)/2; // nCr에 r이 2로 고정 값임으로 n(n-1)/2식이 완성됨

        cout << weightA <<  ' ';

        for(int i=0; i<3; i++){
            if(weightA % ratio1[i] != 0){
                continue;
            }

            int weightB = (weightA / ratio1[i]) * ratio2[i];
            cout << weightB <<  '\n';

            answer += weightCount * pairMap[weightB] * 1LL;

            * pairMap[weightB]으로 인해 map에 데이터가 추가 됨으로 정상적인 연산을 할 수 없다.
        }
        cout << '\n';

    }
    return answer;
}
*/