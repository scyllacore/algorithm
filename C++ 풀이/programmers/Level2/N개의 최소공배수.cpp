#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a,int b){
    
    int tmp;
    
    while(b!=0){
        tmp = a%b;
        a= b;
        b = tmp;
    }
    
    return a;
    
}

int solution(vector<int> arr) {
    
    int lcmVal = arr[0];
    
    for(int i=1; i<arr.size(); i++){
        lcmVal = (lcmVal*arr[i])/gcd(lcmVal,arr[i]); 
    }

    return lcmVal;
}