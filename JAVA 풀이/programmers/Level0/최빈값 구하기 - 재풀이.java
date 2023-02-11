import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] array) {
        Map<Integer, Integer> numberOf = new HashMap<>();

        for (int n : array) {
            numberOf.put(n , numberOf.getOrDefault(n,0)+1);
        }

        int maxValue = 0;
        int maxKey = 0;

       for(Map.Entry<Integer,Integer> m : numberOf.entrySet()){
           if(m.getValue() > maxValue){
               maxValue = m.getValue();
               maxKey = m.getKey();
           }
       }
        numberOf.remove(maxKey);

        for(Map.Entry<Integer,Integer> m : numberOf.entrySet()){
            if(m.getValue() == maxValue ){
                return -1;
            }
        }

        return maxKey;
    }
}