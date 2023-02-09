#include <string>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int solution(string dartResult) {

    int i, len = dartResult.length();
    vector<int> score;
    int sum = 0;
    int size;

    for (i = 0; i < len; i++) {

        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            sum = sum * 10 + (dartResult[i] - '0');
        }
        else if (dartResult[i] >= 'A' && dartResult[i] <= 'Z') {
            score.push_back(sum);
            sum = 0;

            size = score.size();

            if (dartResult[i] == 'D') {
                score[size - 1] = score[size - 1] * score[size - 1];
            }
            else if (dartResult[i] == 'T') {
                score[size - 1] = score[size - 1] * score[size - 1] * score[size - 1];
            }
        }
        else {
            if (dartResult[i] == '*') {
                score[size - 1] *= 2;

                if (size > 1) {
                    score[size - 2] *= 2;
                }
            }
            else if (dartResult[i] == '#') {
                score[size - 1] *= -1;
            }
        }

    }

    int answer = accumulate(score.begin(), score.end(), 0);

    return answer;
}

/*
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:

        https://deukyu.tistory.com/48

*/