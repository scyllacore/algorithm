#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    char category[4][2]= {{'R','T'},{'C','F'},{'J','M'},{'A','N'}};
    int score[26] ={0};
    int i;
    
    for(i=0; i<choices.size(); i++){
        char pick=0;
        
        if(choices[i]<4){pick = survey[i][0];}
        else if(choices[i]>4){pick = survey[i][1];}
        
        if(pick!=0){ score[pick-'A'] += abs(4-choices[i]);}   
    }
    
    for(i=0; i<4; i++){
        if(score[category[i][0]-'A']<score[category[i][1]-'A']){
            answer += category[i][1];
        }
        else{
            answer += category[i][0];
        }
    }
    
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int score[4][2]= {{0}};
    int i;
    
    for(i=0; i<choices.size(); i++){
        char pick;
        
        if(choices[i]<4){pick = survey[i][0];}
        else if(choices[i]>4){pick = survey[i][1];}
        
        if(pick == 'R'){
            score[0][0] += abs(choices[i]-4);
        }
        else if(pick == 'T'){
            score[0][1] += abs(choices[i]-4);
        }
         else if(pick == 'C'){
            score[1][0] += abs(choices[i]-4);
        }
         else if(pick == 'F'){
            score[1][1] += abs(choices[i]-4);
        }
         else if(pick == 'J'){
            score[2][0] += abs(choices[i]-4);
        }
         else if(pick == 'M'){
            score[2][1] += abs(choices[i]-4);
        }
         else if(pick == 'A'){
            score[3][0] += abs(choices[i]-4);
        }
         else if(pick == 'N'){
            score[3][1] += abs(choices[i]-4);
        }   
    }
    
    if(score[0][0] < score[0][1]){
         answer += "T";
    }
    else{
        answer += "R";
    }

     if(score[1][0] < score[1][1]){
         answer += "F";
    }
    else{
        answer += "C";
    }
    
     if(score[2][0] < score[2][1]){
         answer += "M";
    }
    else{
        answer += "J";
    }
    
    if(score[3][0] < score[3][1]){
         answer += "N";
    }
    else{
        answer += "A";
    }
    
    
    
    return answer;
}

*/