#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_time(int t){
    int hour = t/100;
    int minute = t%100;
    
    return hour*60 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for(int i=0; i<schedules.size(); i++){
        int end = get_time(schedules[i]) + 10;

        int day = startday - 1;
        bool check = 1;

        for(int j=0; j<timelogs[i].size(); j++,day++){
            if((day%7 + 1 == 6) || (day%7 + 1 == 7)){
                continue;
            }
 
            int t = get_time(timelogs[i][j]);

            if(t > end){
                check = 0;
                break;
            }
        }

        answer += (int)check;
    }

    return answer;
}
