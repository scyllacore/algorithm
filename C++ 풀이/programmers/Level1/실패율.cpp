#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct userPercent{
    double percent;
    int idx;
};

bool cmp(const userPercent& u1 ,const userPercent& u2){
    if(u1.percent == u2.percent){
        return u1.idx < u2.idx;
    }
    else{
        return u1.percent > u2.percent;
    }
}

vector<int> solution(int N, vector<int> stages) {

    vector<int> arr(N+2,0);
    int i,size=stages.size();

   /* for(i=0; i<size; i++){
        arr[stages[i]]++;
    }*/

    for(int val : stages){
        arr[val]++;
    }

    vector<userPercent> user;

    for(i=1; i<=N; i++){
        size -= arr[i-1];

        if(size == 0){ // (arr[i] == 0) -> size가 0이 될 수 있다 이 경우를 생각하지 못했다..
            user.push_back({0,i});
        }
        else{
        user.push_back({(double)arr[i]/size,i});
        }
    }

    sort(user.begin(),user.end(),cmp);

    vector<int> answer;
    size = user.size();

    for(i=0; i<size; i++){
        answer.push_back(user[i].idx);
    }                 

    return answer;
}