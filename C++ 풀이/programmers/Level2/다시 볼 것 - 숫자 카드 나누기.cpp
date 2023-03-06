#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int isDivided(vector<int>& arrayA, vector<int>& arrayB) {

    int size = arrayA.size();
    int minVal = arrayA[0];

    for (int i = minVal; i >= 1; i--) {

        bool check = 1;

        for (int j = 0; j < size; j++) {
            if (arrayA[j] % i == 0 && arrayB[j] % i != 0) {
                continue;
            }

            check = 0;
            break;
        }

        if (check) return i;
    }

    return 0;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    return max(isDivided(arrayA, arrayB), isDivided(arrayB, arrayA));
}

/* ^^^^^^^^^주석 해석 하세요^^^^^^^^^^^^^^^^^^^^^^
#include <bits/stdc++.h>
using namespace std;

int f(int a, int b){return a % b == 0 ? b : f(b, a % b);}
int f(vector<int> &a, vector<int> &b){
    int A = a[0];
    for (int x : a) A = f(max(A, x), min(A, x));
    for (int x : b)
    if (x % A == 0)
        return 0;
    return A;
}
int solution(vector<int> a, vector<int> b) {
    return max(f(a, b), f(b, a));
}

*/