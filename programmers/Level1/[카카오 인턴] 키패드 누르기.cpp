#include <string>
#include <cmath>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    
    string answer = "";
    
    int ly=3,lx=0,ry=3,rx=2;
    int cenX,cenY;
    int disL,disR;
   
    int i;
    
    for(i=0; i<numbers.size(); i++){
        numbers[i]--;
        if(numbers[i]%3 == 0){
            answer += 'L';
            ly = numbers[i]/3 , lx = numbers[i]%3;
        }
        else if(numbers[i]%3 == 2){
            answer += 'R';
            ry = numbers[i]/3 , rx = numbers[i]%3;
        }
        else {
            
            if(numbers[i]!= -1){
                cenY = numbers[i]/3 ,cenX = numbers[i]%3;
            }
            else{
                cenY = 3 , cenX=1;
            }
            
            disL = abs(cenY - ly) + abs(cenX - lx);
            disR = abs(cenY - ry) + abs(cenX - rx);
            
            
             if(disL<disR){
                answer += 'L';
                ly = cenY , lx = cenX;       
            }
            else if(disL>disR){
                answer += 'R';
                ry = cenY , rx = cenX;       
            }else{
                answer += (hand[0]-32);
                if((hand[0]-32) == 'L'){     
                     ly = cenY , lx = cenX;   
                }
                else{
                     ry = cenY , rx = cenX; 
                }
            }
         
        }
    }
    
     
    return answer;
}

/*
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    
    string answer = "";
    
    int ly=3,lx=0,ry=3,rx=2;
    int cenX,cenY;
    int disL,disR;
   
    int i;
    
    for(i=0; i<numbers.size(); i++){
        numbers[i]--;
        if(numbers[i]%3 == 0){
            answer += 'L';
            ly = numbers[i]/3 , lx = numbers[i]%3;
        }
        else if(numbers[i]%3 == 2 && numbers[i] != -1){
            answer += 'R';
            ry = numbers[i]/3 , rx = numbers[i]%3;
        }
        else {
            
            if(numbers[i]!= -1){
                cenY = numbers[i]/3 ,cenX = numbers[i]%3;
            }
            else{
                cenY = 3 , cenX=1;
            }
            
            disL = abs(cenY - ly) + abs(cenX - lx);
            disR = abs(cenY - ry) + abs(cenX - rx);
            
            
             if(disL<disR){
                answer += 'L';
                ly = cenY , lx = cenX;       
            }
            else if(disL>disR){
                answer += 'R';
                ry = cenY , rx = cenX;       
            }else{
                if((hand[0]-32) == 'L'){
                    answer += 'L';
                      ly = cenY , lx = cenX;   
                }
                else{
                    answer += 'R';
                 ry = cenY , rx = cenX; 
                }
            }
            
                       
            
        }
    }
    
    
  
    return answer;
}
*/