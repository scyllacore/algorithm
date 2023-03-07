#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int tmpCol;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[tmpCol - 1] == b[tmpCol - 1]) {
        return a[0] > b[0];
    }

    return a[tmpCol - 1] < b[tmpCol - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    tmpCol = col;
    sort(data.begin(), data.end(), cmp);

    int answer = 0;

    for (int i = row_begin; i <= row_end; i++) {

        int sum = 0;
        for (int val : data[i - 1]) {
            sum += (val % i);
        }

        answer ^= sum;

    }

    return answer;
}