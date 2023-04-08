#include <string>
#include <vector>

using namespace std;

long long getFac(int n) {
    long long sum = 1;

    for (int i = 2; i <= n; i++) {
        sum *= i;
    }
    return sum;
}

vector<int> solution(int n, long long k) {

    vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    vector<int> answer;

    k--;
    for (; k != 0;) {
        n--;
        long long boundary = getFac(n);
        int idx = k / boundary;
        k = k % boundary;

        answer.push_back(permutation[idx]);
        permutation.erase(permutation.begin() + idx);
    }

    for (int i = 0; i < permutation.size(); i++) {
        answer.push_back(permutation[i]);
    }

    return answer;
}