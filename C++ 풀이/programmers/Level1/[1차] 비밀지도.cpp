#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    string tmp;
    int i,j;
    
    for(i=0; i<n; i++){   
        tmp="";
        arr1[i] = arr1[i] | arr2[i];
        for(j=0; j<n; j++){
           if(arr1[i] & 1){
               tmp = "#" + tmp;
           }
            else{
                tmp = ' ' + tmp;
            }
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(tmp);     
    }
    
    return answer;
}

/* 
    int i,j;
    
    bool mapNN[16][16]= {{0}};
    
    for(i=0; i<n; i++){      
        for(j=0; j<n; j++){
            if(arr1[i] & (1<<j)){
                mapNN[i][n-1-j] = 1;
            }
            else if(arr2[i] & (1<<j)){
                mapNN[i][n-1-j] = 1;
            }
        }
        
    }
    
        
    vector<string> answer;
    string tmp;
    
     for(i=0; i<n; i++){     
         tmp="";
        for(j=0; j<n; j++){
            if(mapNN[i][j]){ tmp += '#';}
            else{tmp += ' ';}
        }
         answer.push_back(tmp);
     }
    
    return answer;
*/