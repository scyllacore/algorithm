#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(vector<string>& s1,vector<string>& s2){
    return s1.size() < s2.size();
}

vector<int> solution(string s) {
    
    vector<vector<string>> tuple(1,vector<string>(0));
    
    int i,j;
    string tmp="";
    
    for(i=2; i<s.length()-1; i++){
        if(isdigit(s[i])){
            tmp+= s[i];
        }
        else if(s[i] == '}' || (s[i] == ',' && s[i+1] != '{')){   
            tuple[tuple.size()-1].push_back(tmp);
            tmp = "";        
            if(s[i] == '}') tuple.push_back(vector<string>(0));     
        }
    } 
    tuple.pop_back();
    
    sort(tuple.begin(),tuple.end(),cmp);

    vector<int> answer;
    set<string> order;
    
   for(i=0; i<tuple.size(); i++){
        for(j=0; j<tuple[i].size(); j++){
            if(order.find(tuple[i][j]) == order.end()){
                answer.push_back(stoi(tuple[i][j]));
                order.insert(tuple[i][j]);
            }
        }
    }
    
    return answer;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";

    int st[101010] = {};
    vector<int> answer;
    string tmp;
    for (char i : s) {
        if (i - '0' >= 0 && i - '0' <= 9) {
            tmp += i;
        }
        else {
            if (tmp.length())
                st[stoi(tmp)]++, tmp.clear(); // 나온 숫자들의 개수를 셈
        }
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < 101010; i++)
        if (st[i])
            v.push_back({ st[i], i });

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << '\n'; 
    }

    // 제일 많이 나온 값이 제일 처음에 나온 값임.

    sort(v.begin(), v.end(),greater<>()); // 숫자 빈도를 기준으로 정렬.
    // 제일 많이 나온 숫자가 튜플의 시작이다.
    for (auto it : v) answer.push_back(it.second);

    for (auto val : answer) {
        cout << val << ' ';
    }

}
*/