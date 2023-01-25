import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int n) {
        List<Integer> numberList = new ArrayList<>();
        
        for(Integer number=1; number<=n/number; number++){
            if(n%number == 0){
                numberList.add(number);
                
                if(n/number != number){
                     numberList.add(n/number);
                } 
            }
            
        }
        
        numberList.sort(Comparator.naturalOrder());
        return numberList.stream().mapToInt(Integer::intValue).toArray();
    }
}