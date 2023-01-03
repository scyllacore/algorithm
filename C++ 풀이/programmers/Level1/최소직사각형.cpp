#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    vector<int> firstMax;
    vector<int> secondMax;
    
    int size=sizes.size(),i;
    
    for(i=0; i<size; i++){
       if(sizes[i][0] > sizes[i][1]){
           firstMax.push_back(sizes[i][0]);
           secondMax.push_back(sizes[i][1]); 
       }
        else{
            firstMax.push_back(sizes[i][1]);
            secondMax.push_back(sizes[i][0]); 
        }
    }
     
    int maxW= *max_element(firstMax.begin(),firstMax.end());
    int maxH=*max_element(secondMax.begin(),secondMax.end());
    
    int answer = maxW*maxH;
    return answer;
}


/*

    int answer=0;

    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));
        h=max(h,max(sizes[i][0],sizes[i][1]));
    }
    answer=w*h;

    return answer;
*/