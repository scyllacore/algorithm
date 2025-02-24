#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    unordered_map<string, int> um;
    
    vector<int> gift_degree(friends.size(), 0);
    vector<vector<int>> gift_graph(friends.size(), vector<int>(friends.size(), 0));
    
    for(int i=0; i< friends.size(); i++){
         um[friends[i]] = i;
    }    

    for(string g : gifts){
        istringstream iss(g);
        string a, b;
        iss >> a >> b;
        
        gift_degree[um[a]]++;
        gift_degree[um[b]]--;
        
        gift_graph[um[a]][um[b]]++;
    }
    
    
    for(int i=0; i<friends.size(); i++){
        int num = 0;
        
        for(int j=0; j< friends.size(); j++){
            if(i == j){
                continue;
            }
            
            if(gift_graph[i][j] > gift_graph[j][i]){
                num++;
            }
            else if(gift_graph[i][j] == gift_graph[j][i] && gift_degree[i] > gift_degree[j]){
                num++;
            } 
        }
        
        answer = max(num, answer);
    }
    
    return answer;
}


/*
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

struct info{
    string name;
    int idx;
    int give;
    int take;
    int exp;
};

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, info> um;
    
    vector<vector<int>> v1;
    v1.assign(friends.size(), vector<int>(friends.size(),0));
    
    for(int i=0; i< friends.size(); i++){
         um[friends[i]] = {"",i,0,0,0};
    }
    
    for(string g : gifts){
        istringstream iss(g);
        string a,b;
        iss >> a >> b;
        um[a].give++;
        um[b].take++;
        
        v1[um[a].idx][um[b].idx]++;
    }
    
    for(auto& fi : um){
        fi.second.exp = fi.second.give - fi.second.take;
    }
    
    for(int i=0; i< friends.size()-1; i++){
        for(int j=i+1; j< friends.size(); j++){
            if(um[friends[i]].idx == um[friends[j]].idx){
                continue;
            }
            
            if(v1[um[friends[i]].idx][um[friends[j]].idx] > v1[um[friends[j]].idx][um[friends[i]].idx]){
                um[friends[i]].give++;
            }
            else if(v1[um[friends[i]].idx][um[friends[j]].idx] == v1[um[friends[j]].idx][um[friends[i]].idx]){
                if(um[friends[i]].exp > um[friends[j]].exp){
                    um[friends[i]].give++;
                }
            }
            else{
               um[friends[j]].give++;
            }
        } 
    }
    
    vector<info> v2;
    
    for(auto& fi : um){
        v2.push_back({fi.first, fi.second.idx, fi.second.give, fi.second.take, fi.second.exp});
    }
    
    sort(v2.begin(), v2.end(), [](info& i1, info& i2) -> bool{
        return i1.give > i2.give;
    });
    
    cout << v2[0].give;
    
    int answer = 0;
    return answer;
}
*/