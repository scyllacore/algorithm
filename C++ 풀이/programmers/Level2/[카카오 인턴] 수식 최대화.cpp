#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool operator3[3] = {0,0,0}; // + - *;
vector<long long> num;
vector<char> oper;

long long maxNum;
string operCombi;
int operCnt;


void calNum(){
    
    vector<long long> tmpNum(num);
    vector<char> tmpOper(oper);
    
    int i,j;
    
     for(i=0; i<operCombi.length(); i++){
         for(j=0; j<tmpOper.size(); j++){
             
             if(operCombi[i] == tmpOper[j]){
                 
               if(operCombi[i] == '+') { tmpNum[j] += tmpNum[j+1];}
               else if(operCombi[i] == '-') { tmpNum[j] -= tmpNum[j+1];}
               else if(operCombi[i] == '*') { tmpNum[j] *= tmpNum[j+1];} 
                 
                tmpNum.erase(tmpNum.begin()+j+1);
                tmpOper.erase(tmpOper.begin()+j);
                j--;
             }             
         }        
     }
    
    long long calNum = abs(tmpNum.back()); 
    maxNum = max(calNum,maxNum); 
    
}



void DFS(int depth){
    
    
    if(depth>=operCnt){
        calNum();
        return;
    }
    
    int i;
    
    for(i=0; i<3; i++){
        
        if(!operator3[i]) {continue;}
        
        operator3[i] = 0;
        
        if(i==0)  operCombi.push_back('+');
        else if(i==1)  operCombi.push_back('-');
        else if(i==2)  operCombi.push_back('*');

        
        DFS(depth+1);
        
        operator3[i] = 1;
        operCombi.pop_back();
              
    }
    
    
}

long long solution(string expression) {
    
    maxNum = 0;
    operCombi = "";
    operCnt = 0;
    
    int i;
    long long sum=0;
    
    for(i=0; i<expression.length(); i++){
        
        if(isdigit(expression[i])){
            sum = sum*10 + (expression[i]-'0');  
        }
        else{
            
            num.push_back(sum);
            sum = 0;
            
           if(expression[i] == '+') operator3[0]=1;
           else if(expression[i] == '-') operator3[1]=1;
           else if(expression[i] == '*') operator3[2]=1;
         
           oper.push_back(expression[i]);
        }
    }
    
     num.push_back(sum);
    
    for(i=0; i<3; i++){
        if(operator3[i]) operCnt++;
    }
      
    
    DFS(0);
      
    return maxNum;
}