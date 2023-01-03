#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct user{
    char cmdCh;
    string id;
};

vector<string> solution(vector<string> record) {
    
    int i,j;
    int size=record.size();
    
    unordered_map<string,string> userInfo;
    vector<user> resV;
    
    string cmd,id,name;
    
    for(i=0; i<size; i++){
        istringstream iss(record[i]);
        iss >> cmd>> id >> name;
                
        if(cmd[0] == 'E'){
            userInfo[id] = name; 
            
            /*
             if(userInfo.find(id) != userInfo.end()){
                userInfo[id] = name;
            }
            else{
            userInfo.insert({id,name});   
            }
            */
            
            resV.push_back({cmd[0],id});
            
        }
        else if(cmd[0] == 'L'){
            resV.push_back({cmd[0],id});
        }
        else if(cmd[0] == 'C'){
            userInfo[id] = name;
        }        
    }
    
    size = resV.size();
    vector<string> answer;
    
    char ch;
    
    for(i=0; i<size; i++){
       if(resV[i].cmdCh == 'E'){
           answer.push_back(userInfo[resV[i].id] + "님이 들어왔습니다.");
       } 
        else{
           answer.push_back(userInfo[resV[i].id] + "님이 나갔습니다."); 
        }      
    }
     
    return answer;
}