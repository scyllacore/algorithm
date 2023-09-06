import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] array) {
       Arrays.sort(array);

        Map<Integer, List<Integer>> numberOf = new HashMap<>();

        int cnt = 0;
        int start = 0;
        int end;

        for (end = 0; end < array.length; end++) {
            if (array[end] != array[start]) {
                List<Integer> list = numberOf.getOrDefault(end - start, new ArrayList<>());
                list.add(array[start]);
                numberOf.put(end - start, list);

                start = end;
            }
        }

        List<Integer> list = numberOf.getOrDefault(end - start, new ArrayList<>());
        list.add(array[start]);
        numberOf.put(end - start, list);


        int maxKey = 0;

        for (Map.Entry<Integer, List<Integer>> m : numberOf.entrySet()) {
            if (m.getKey() > maxKey) {
                maxKey = m.getKey();
            }
        }


        if (numberOf.get(maxKey).size() > 1) {
           return -1;
        }

        return numberOf.get(maxKey).get(0);
    }
    //중복되는 코드만 없애면 전보다 효율에서는 괜찮은 코드.
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