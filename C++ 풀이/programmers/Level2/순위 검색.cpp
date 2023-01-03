#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

string tmpInfo[4];
string score; // int score로도 가능. iss 에서 입력 받을 때 바로 int형으로 변경됨. 그러나 46번 라인에서 재활용이 안돼서 string으로 냅둠.

unordered_map<string,vector<int>> infoList;

void getCombi(){
    int i,j;
    string concatInfo;
    
    for(i=0; i<(1<<4); i++){
        concatInfo ="";
        for(j=0; j<4; j++){ 
            concatInfo += (i & (1<<j)) ? tmpInfo[j] : "-"; 
        }
        infoList[concatInfo].push_back(stoi(score));
    }
    
}

vector<int> solution(vector<string> info, vector<string> query) {
    
    int i;
      
    for(auto &i : info){
        istringstream iss(i);
        iss >> tmpInfo[0] >> tmpInfo[1] >> tmpInfo[2] >> tmpInfo[3] >> score;
        getCombi();
    }
    
    for(auto &il : infoList){
        sort(il.second.begin(),il.second.end());
    }
    
    vector<int> answer;
    
    for(auto &q : query){
        istringstream iss(q);
        iss >> tmpInfo[0] >> score >> tmpInfo[1] >> score >> tmpInfo[2] >> score >> tmpInfo[3] >> score;
        
        string il = tmpInfo[0] + tmpInfo[1] + tmpInfo[2] + tmpInfo[3];
        vector<int>& scoreV = infoList[il];
        int cntP = scoreV.end() - lower_bound(scoreV.begin(),scoreV.end(),stoi(score));
        
        answer.push_back(cntP);
  
    }
    
    return answer;
    
}

/*
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

string tmpInfo[4];
string score;

unordered_map<string,vector<int>> infoList;

void getCombi(){
    int i,j;
    string concatInfo;

    for(i=0; i<(1<<4); i++){
        concatInfo ="";
        for(j=0; j<4; j++){
            if(i & (1<<j)){
                concatInfo += tmpInfo[j];
            }
            else{
                concatInfo += '-';
            }
        }
        infoList[concatInfo].push_back(stoi(score));
    }

}

vector<int> solution(vector<string> info, vector<string> query) {

    int i;

    for(auto &i : info){
        istringstream iss(i);
        iss >> tmpInfo[0] >> tmpInfo[1] >> tmpInfo[2] >> tmpInfo[3] >> score;
        getCombi();
    }

    for(auto &il : infoList){
        sort(il.second.begin(),il.second.end());
    }

    vector<int> answer;

    for(auto &q : query){
        istringstream iss(q);
        iss >> tmpInfo[0] >> score >> tmpInfo[1] >> score >> tmpInfo[2] >> score >> tmpInfo[3] >> score;

        vector<int> scoreV = infoList[tmpInfo[0] + tmpInfo[1] + tmpInfo[2] + tmpInfo[3]];
         if(!scoreV.empty()){
             int intScore = stoi(score), size = scoreV.size();   
             int cntP = size - (lower_bound(scoreV.begin(),scoreV.end(),intScore) - scoreV.begin());
              answer.push_back(cntP);
         }
         else{
             answer.push_back(0);
         }

    }

    return answer;

}
*/