#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

struct carInfo{
    string carNum;
    int t;
};

bool cmp(const carInfo& c1,const carInfo& c2){
    return c1.carNum < c2.carNum;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    unordered_map<string,vector<int>> carList;
    
    for(auto& record : records){   
        int t = stoi(record.substr(0,2))*60 + stoi(record.substr(3,2));
        string carNum = record.substr(6,4);  
        carList[carNum].push_back(t);
    }
      
    for(auto& car : carList){
        
        int sum=0;
        
        if(car.second.size()%2 == 1){
             car.second.push_back(23*60+59);
         }

        for(int i=0; i<car.second.size(); i+=2){
             sum += car.second[i+1] - car.second[i];
        }            
   
        car.second.push_back(sum);
    }
    
    vector<carInfo> carFeeList;
    
    for(auto& car : carList){
        
        int fee = car.second.back();
        
        if(fee>fees[0]){
            fee = fees[1] + ceil((double)(fee-fees[0])/fees[2]) * fees[3];
        }
        else{
            fee = fees[1];
        }
        
        carFeeList.push_back({car.first,fee});
    }
    
    sort(carFeeList.begin(),carFeeList.end(),cmp);
    
    vector<int> answer;
    
    for(auto& car : carFeeList){
        answer.push_back(car.t);
    }
      
    return answer;
}