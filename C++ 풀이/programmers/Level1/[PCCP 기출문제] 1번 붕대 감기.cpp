#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    int attackIdx = 0;
    int count = 0;
    int hp = health;
    
    for(int i=1; attackIdx<attacks.size(); i++){
        
        int atkTime = attacks[attackIdx][0];
        
        if(i == atkTime){
            count = 0;
        
            hp -= attacks[attackIdx][1];
            attackIdx++;
            
            if(hp <= 0){
                hp = -1;
                break;
            }
            
            continue;
        }
        
        count++;
        
        hp += bandage[1];
        
        if(count == bandage[0]){
            hp += bandage[2];
            count = 0;
        }
        
        if(hp > health){
            hp = health;
        }
        
    }
    
    return hp;
}