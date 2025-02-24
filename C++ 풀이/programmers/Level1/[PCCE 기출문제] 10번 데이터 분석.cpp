#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int ext_idx, sort_idx;

bool cmp(vector<int>& v1,vector<int>& v2){
    return v1[sort_idx] < v2[sort_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    
    unordered_map<char,int> attrMap;
    
    attrMap['c'] = 0;
    attrMap['d'] = 1;
    attrMap['m'] = 2;
    attrMap['r'] = 3;
    
    ext_idx = attrMap[ext[0]];
    sort_idx = attrMap[sort_by[0]];
    
    vector<vector<int>> answer;
    
    for(auto d : data){
        if(d[ext_idx] < val_ext){
            answer.push_back(d);
        }
    }
    
    sort(answer.begin(),answer.end(),cmp);
       
    return answer;
}