#include <string>
#include <vector>

using namespace std;

int mulArr(vector<vector<int>>& arr1,vector<vector<int>>& arr2,int row,int col){
    
    int i,val=0;
    
    for(i=0; i<arr2.size(); i++){ // arr1[i].size()
        val += (arr1[row][i] * arr2[i][col]);
    }
    
    return val;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int i,j;
    
    int row = arr1.size() , col = arr2[0].size();
    
    for(i=0; i<row; i++){   
        answer.push_back(vector<int>(0));
        for(j=0; j<col; j++){
            int val = mulArr(arr1,arr2,i,j);
            answer[i].push_back(val);
        }
        
    }
    
    return answer;
}