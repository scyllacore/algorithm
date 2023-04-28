import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] arr) {
        List<Integer> answer = Arrays.stream(arr)
            .boxed().collect(Collectors.toList());
        
        int start = answer.indexOf(2);
        int end = answer.lastIndexOf(2);
        
        if(start + end < 0){
            return new int[]{-1};
        }
        
        return Arrays.copyOfRange(answer.stream().mapToInt(Integer::intValue).toArray(),start,end+1);
    }
}