#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int i,j,k;
    int size = land.size();
    
    for(i=1; i<size; i++){
        for(j=0; j<4; j++){
            int ijVal = land[i][j];
            for(k=0; k<4; k++){
                if(k!=j) land[i][j] = max(land[i-1][k] + ijVal, land[i][j]);
            }
        }   
    }      

    return *max_element(&land[size-1][0],&land[size-1][4]);
}