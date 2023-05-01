import java.math.*;

class Solution {
    public int solution(int a, int b, int c, int d) {
        int[] numCnt = new int[7];
        
        numCnt[a]++;
        numCnt[b]++;
        numCnt[c]++;
        numCnt[d]++;
        
        int size=0;
        
        for(int cnt : numCnt){
            if(cnt > 0){
                size++;
            }
        }
        
        if(size == 1){
            for(int i=1; i<=6; i++){
                if(numCnt[i] == 4 ){
                    return 1111 * i;
                }
            }
        }
        
        if(size == 2){
            for(int i=1; i<=6; i++){
                if(numCnt[i] == 3){
                    for(int j=1; j<=6; j++){
                        if(numCnt[j] == 1){
                            return (10 * i + j) * (10 * i + j);
                        }
                    }
                }
            }
            
            for(int i=1; i<=6; i++){
                if(numCnt[i] == 2){
                    for(int j=1; j<=6; j++){
                        if(i!=j && numCnt[j] == 2){
                            return (i+j) * Math.abs(i-j);
                        }
                    }
                }
            }
        }
        
        if(size==3){
             for(int i=1; i<=6; i++){
                if(numCnt[i] == 1){
                    for(int j=1; j<=6; j++){
                        if(i!=j && numCnt[j] == 1){
                            return i*j;
                        }
                    }
                }
            }
        }
        
        
        for(int i=1; i<=6; i++){
            if(numCnt[i] > 0){
                return i;
            }
        }
    
        return -1;
        
    }
}