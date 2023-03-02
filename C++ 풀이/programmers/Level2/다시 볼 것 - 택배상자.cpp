#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> order) {

    queue<int> orig;
    vector<int> sub;

    int size = order.size();

    for (int i = 0; i < size; i++) {
        orig.push(i + 1);
    }

    int answer = 0;

    for (int i = 0; i < size;) { //i++ 를 쓰면 안된다.
        int cnt = 0;

        for (; !orig.empty() && order[i] != orig.front(); ) {
            sub.push_back(orig.front());
            orig.pop();
        }

        if (!orig.empty() && order[i] == orig.front()) {
            sub.push_back(orig.front());
            orig.pop();
        }


        for (; !sub.empty() && order[i] == sub.back();) { // &&i<size 
            sub.pop_back();
            cnt++;
            i++;
        }

        if (cnt < 1) {
            break;
        }

        answer += cnt;
    }

    return answer;

}


/*
        if(!orig.empty() && orig.front() != order[i]){
             sub.push_back(orig.front());
             orig.pop();

             continue;
        }

        int cnt=1;

        i++;
        for(;!sub.empty() && order[i] == sub.back();){
            sub.pop_back();
            cnt++;
            i++;
        }

        if(cnt < 1){
            break;
        }

        answer += cnt;
        */
