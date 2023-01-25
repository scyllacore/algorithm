class Solution {
    public int solution(int n) {
        if(n % Math.sqrt(n) == 0){
            return 1;
        }
        
        return 2;
    }
}


/*
import java.util.*;

class Solution {
    public int solution(int n) {
        Set<Integer> squareNumbers = new HashSet<>();
        
        for(Integer number=1; number<=1000; number++){
            squareNumbers.add(number*number);
        }
        
        if(squareNumbers.contains(n)){
            return 1;
        }
        
        return 2;
    }
}
*/