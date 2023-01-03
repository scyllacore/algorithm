#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int i,j;
    int rowSize=arr1.size(),colSize=arr1[0].size();
    for(i=0; i<rowSize; i++){
        for(j=0; j<colSize; j++){
            arr1[i][j] += arr2[i][j];
        }
    }
       
    return arr1;
}

/*
vector<vector<int>> answer;
    vector <int> Q;
    for(int i = 0 ; i< arr1.size();i++)
    {
        for(int j = 0; j< arr1[i].size();j++)
        {
            Q.push_back(arr1[i][j]+arr2[i][j]);
        }
         answer.push_back(Q);
        Q.clear();
    }
    return answer;
*/