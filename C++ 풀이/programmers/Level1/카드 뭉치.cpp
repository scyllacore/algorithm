#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

    int idx1 = 0, idx2 = 0;

    for (int i = 0;; i++) {

        if (i >= goal.size()) {
            return "Yes";
        }

        if (idx1 < cards1.size() && cards1[idx1] == goal[i]) {
            idx1++;
        }
        else if (idx2 < cards2.size() && cards2[idx2] == goal[i]) {
            idx2++;
        }
        else {
            break;
        }
    }

    return "No";
}

/*
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {

    int idx1=0,idx2=0;

    for(int i=0;;i++){

        if(i >= goal.size()){
            return "Yes";
        }

        if(idx1 < cards1.size()){
            if(cards1[idx1] == goal[i]){
                idx1++;
                continue;
            }
        }
        if(idx2 < cards2.size()){
            if(cards2[idx2] == goal[i]){
                idx2++;
                continue;
            }
        }

        break;
    }

    return "No";
}
*/