import java.util.*;

class Solution {
    public int[] solution(int n) {
        List<Integer> answer = new ArrayList<>();
        
        answer.add(n);
        
        for(;n>1;){
            if(n%2==0){
                n/=2;
            }else{
                n = 3 * n + 1;
            }
            
            answer.add(n);
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}

/*
import java.util.stream.IntStream;

class Solution {
    public int[] solution(int n) {
        return IntStream.concat(
                        IntStream.iterate(n, i -> i > 1, i -> i % 2 == 0 ? i / 2 : i * 3 + 1),
                        IntStream.of(1))
                .toArray();
    }
}
*/