#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string,int> menuPick;

int maxDepth;

void DFS(string order,string combi){
    if(combi.size() >= maxDepth) { menuPick[combi]++; }
    else{
        for(int i=0; i<order.size(); i++){
            DFS(order.substr(i+1),combi+order[i]);
        }
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(string& order:orders){
        sort(order.begin(),order.end());
    }
    
     vector<string> answer;
    
    for(int curNum:course){
        
        maxDepth = curNum;
        
        for(string& order:orders){
            DFS(order,"");
        }
        
        int maxPick=0; 
        for(auto pickCnt : menuPick){
            maxPick = max(pickCnt.second,maxPick);
        }
        
        for(auto pickCombi : menuPick){
            if(pickCombi.second >=2 &&pickCombi.second==maxPick){
                answer.push_back(pickCombi.first);
            }
        }
        
        menuPick.clear();
        
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}


/*
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> guest;
vector<char> menu;    
unordered_map<string,int> menuMap;

string combi;
int maxDepth;
int maxMenu[11];

void DFS(int start,int depth){
    
    int i,j;
    
    if(depth >= maxDepth){// 단품 요리가 원하는 개수만큼 조합되어 코스 요리가 완성됐을 때.     
               
        int orderSum=0;
        bool flag;
        
        // 그 코스요리가 포함된 단품 메뉴를 주문한 손님을 찾음.
        for(i=0; i<guest.size(); i++){
            flag=1;
            for(j=0; j<depth; j++){
                if(!guest[i][combi[j]-65]) {flag=0; break;} 
            }     
            if(flag){ orderSum++;}
        } 
        
        if(orderSum >=2){ // 만약 주문한 손님 수가 2명 이상이라면
            menuMap.insert({combi,orderSum}); // 그 코스요리 조합과 주문 횟수를 같이 저장해둠.
            maxMenu[depth] = max(orderSum,maxMenu[depth]); // 추가로 코스요리의 단품 메뉴 개수에 따른 최대 주문 횟수 저장.
        }
        
        return;       
    }
    
    //단품 메뉴를 조합하여 코스요리를 만듬.
    for(i=start; i<menu.size(); i++){
        combi.push_back(menu[i]);
        DFS(i+1,depth+1);
        combi.pop_back();       
    }
        
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    guest.assign(orders.size(),vector<int>(26,0)); 
    fill_n(maxMenu,10,0);
    
    int i,j;
    bool menuCheck[26]={0};
    
    //각 손님의 주문 메뉴 확인
    for(i=0; i<orders.size(); i++){
        for(j=0; j<orders[i].size(); j++){
            guest[i][orders[i][j]-65]++;
            menuCheck[orders[i][j]-65] = 1;
        }
    }
    
    //모든 손님을 통틀어서 최소 한 번씩 주문한 메뉴 저장
      for(i=0; i<26; i++){
        if(menuCheck[i]) menu.push_back(i+65);
    }
    
    //원하는 코스요리의 단품 조합만 따짐.
     for(i=0; i<course.size(); i++){
        maxDepth = course[i];
        DFS(0,0);
    }
    
    vector<string> answer;
    
    //최대 주문 횟수와 해당 코스요리의 주문 횟수가 같다면 그 코스요리 조합을 저장
    for(auto iter:menuMap){
        if (maxMenu[iter.first.length()] == iter.second){
            answer.push_back(iter.first);
        }
    }
    
    sort(answer.begin(),answer.end());

    return answer;
}
*/