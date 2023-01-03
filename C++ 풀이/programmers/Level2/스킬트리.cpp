#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    
    int skillOrder[27]= {0};
    int i;
    
    skillOrder[skill[0] - 64] = -1;
    for(i=1; i<skill.length(); i++){
        skillOrder[skill[i] - 64] = skill[i-1] - 64;
    }
    
    int answer = 0;
    bool flag;
        
    for(auto userSkill : skill_trees){
        flag=1;
        bool orderMap[27] = {0};
        
         for(char us : userSkill){
            if(skillOrder[us-64]){
                int next=us-64;
                for(;skillOrder[next] != -1;){
                 if(!orderMap[skillOrder[next]]){
                    flag = 0; break;
                 } 
                 next = skillOrder[next];
                } 
            } 
          if(!flag) break;   
          orderMap[us-64] = 1;   
         }
        
        
        if(flag){
            cout << userSkill << '\n';
            answer++;
        }
        
    }
    
    return answer;
    
    //다시 볼 것
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    
    int skillOrder[26]= {0};
    int order=1;
    
    for(char s : skill){
        skillOrder[s -'A'] = order++;
    }
    
    int answer = 0;
    bool flag;
    
    vector<int> orderMap;
    for(auto userSkill : skill_trees){
        flag=1;
        orderMap.clear();
        
         for(char us : userSkill){
         if(skillOrder[us-'A']){orderMap.push_back(skillOrder[us-'A']);}
         }
        
        for(int i=1; i<orderMap.size(); i++){
            if(orderMap[i-1] > orderMap[i]){flag=0; break;}
        }
        
        if(flag){
            cout << userSkill << '\n';
            answer++;
        }
        
    }
    
    return answer;
}
*/