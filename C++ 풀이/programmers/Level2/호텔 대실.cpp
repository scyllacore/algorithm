#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1440+10
#define HOUR 60
#define CLEANING 10

int timeCounter[MAX] = { 0 };

int getMinute(string& _time) {
    int hour = stoi(_time.substr(0, 2));
    int minute = stoi(_time.substr(3));

    return hour * HOUR + minute;
}


int solution(vector<vector<string>> book_time) {
    int answer = 0;

    for (vector<string> _time : book_time) {
        int start = getMinute(_time[0]);
        int end = getMinute(_time[1]);

        timeCounter[start] += 1;
        timeCounter[end + CLEANING] += -1;
    }

    for (int i = 1; i < MAX; i++) {
        timeCounter[i] += timeCounter[i - 1];
        answer = max(timeCounter[i], answer);
    }

    return answer;
}

//https://ksb-dev.tistory.com/269