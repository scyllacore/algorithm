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
            if(m.getValue() == maxValue ){ // && m.getKey() != maxKey
                return -1;
            }
        }

        return maxKey;
    }
}

/*
class Solution {
    public int solution(int[] array) {
        int[] numberOf = new int[1000];

        for(int n : array){
            numberOf[n]++;
        }

        int maxIdx=0;
        
        for(int i=1; i<1000; i++){
            if(numberOf[i] > numberOf[maxIdx]){
                maxIdx = i;
            }
        }
        
        for(int i=0; i<1000; i++){
            if(numberOf[i] == numberOf[maxIdx] && i != maxIdx){
                return -1;
            }
        }
        
        return maxIdx;
    }
}


*/

//https://junghn.tistory.com/entry/JAVA-Map-getOrDefault-%EC%9D%B4%EB%9E%80-%EC%82%AC%EC%9A%A9%EB%B2%95-%EB%B0%8F-%EC%98%88%EC%A0%9C
//https://tychejin.tistory.com/31