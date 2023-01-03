#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    bool check[1000][1000] ={{0}};
    unordered_map<string,int> nameInfo;
    
    int i,j;
    for(i=0; i<id_list.size(); i++){
        nameInfo.insert({id_list[i],i});
    }
    
     for(i=0; i<report.size(); i++){
         
        istringstream ss(report[i]); 
        string name1,name2;
         
        ss >> name1 >> name2;
        check[nameInfo[name1]][nameInfo[name2]] = 1;     
     }
    
    
    vector<int> answer(id_list.size(),0);
    
    for(i=0; i<id_list.size(); i++){
        
        int cnt=0;
        
        for(j=0; j<id_list.size(); j++){
            if(check[j][i] == 1) cnt++;
        }
        
        if(cnt>=k){
            for(j=0; j<id_list.size(); j++){
            if(check[j][i] == 1) answer[j]++;
        }
      }    
    }
       
    return answer;
}