import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        String answer = "";
        
        for(int val : arr){
            answer += String.format("%d,",val).repeat(val);
        }
        
        return Arrays.stream(answer.split(",")).mapToInt(Integer::parseInt).toArray();
    }
}

/*
class Solution {
    public List<Integer> solution(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for(int num : arr) {
            for(int i = 0; i < num; ++i) {
                list.add(num);
            }
        }
        return list;
    }
}
*/