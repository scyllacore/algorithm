#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    int arr[3] ={1,2,4};  
    
    string answer = "";  
    
    n--;
    while(n>-1){
     answer= to_string(arr[n%3])+answer; 
    n= n/3-1;
    }

    return answer;
}

/*
 int arr[3] ={1,2,4};
        
    vector<int> ternary;
    
    n--;
    
    while(n>-1){
       ternary.push_back(arr[n%3]); 
        n= n/3-1;
    }
    
    string answer = "";
    
    while(!ternary.empty()){
      answer +=to_string(ternary.back());
    ternary.pop_back();
    }
   
    
    return answer;
*/