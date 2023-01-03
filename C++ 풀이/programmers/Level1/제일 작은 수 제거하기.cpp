#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    int size=arr.size();
    int i,minIdx=0;
    
    for(i=1; i<size; i++){
        if(arr[i]<arr[minIdx]){
            minIdx=i;
        }
    }

    arr.erase(arr.begin()+minIdx);

    if(arr.empty()){arr.push_back(-1);}
    
    return arr;
}