import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] date1, int[] date2) {
        for(int i=0; i<3; i++){            
            if(date1[i] < date2[i]){
                return 1;
            }else if(date1[i] > date2[i]){
                return 0;
            }
            
            // 같은 경우는 건너뜀. 이런 문제 풀때는 되도록이면 날짜를 일로 환산해서 풀이하자.
        }
        
        return 0;
    }
}

/*
   for(int i=0; i<3; i++){
            if(date1[i] >= date2[i]){
                return 0;
            }
        }
        
        return 1;
    }
    
    
    for(int i=0; i<3; i++){            
            if(date1[i] < date2[i]){
                return 1;
            }
        }
        
        return 0;
    
*/


/*
 String date1S = Arrays.stream(date1).boxed().map(String::valueOf).collect(Collectors.joining());
        String date2S = Arrays.stream(date2).boxed().map(String::valueOf).collect(Collectors.joining());
        
        if(date1S.compareTo(date2S) < 0){
            return 1;
        }
        
        return 0;  
        
9 이하의 숫자가 사용된다면 비교가 제대로 되지 않는 문제가 있음.
*/