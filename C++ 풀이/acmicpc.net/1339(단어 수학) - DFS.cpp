#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string word[10];
bool visited[11];
int n, maxSum;

map<char, int> alphaMap;

void calSum() {
    int totalSum = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = 0; j < word[i].length(); j++) {
            sum = sum * 10 + alphaMap[word[i][j]];
        }
        totalSum += sum;
    }

    /*
    for (i = 0; i < n; i++) {
        powTmp = 1;
        for (j = word[i].length() - 1; j >= 0; j--) {
            sum += powTmp * alphaMap[word[i][j]];
            powTmp *= 10;
        }
    }
    */

    maxSum = max(maxSum, totalSum);
}

void dfs(map<char, int>::iterator idx) { //매개변수에 auto타입을 쓸 수 없다.


    if (idx == alphaMap.end()) {
        calSum();
        return;
    }

    for (int i = 10 - alphaMap.size(); i < 10; i++) {

        if (visited[i]) {
            continue;
        }

        alphaMap[idx->first] = i;

        ++idx;
        visited[i] = true;

        dfs(idx); // idx가 iterator값이기에 idx+1 같은 연산을 할 수 없다.

        --idx;
        visited[i] = false;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    int i, j;

    for (i = 0; i < n; i++) {
        cin >> word[i];
        for (j = 0; j < word[i].length(); j++) {
            alphaMap[word[i][j]] = 0;
        }
    }

    dfs(alphaMap.begin());

    cout << maxSum;
    return 0;
}