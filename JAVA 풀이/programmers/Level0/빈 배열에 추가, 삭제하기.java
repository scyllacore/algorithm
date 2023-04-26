import java.util.*;

class Solution {
    public int[] solution(int[] arr, boolean[] flag) {
        String answer = "";
        
        int len = arr.length;
        
        for(int i=0; i<len; i++){
            if(flag[i]){
                answer += String.valueOf(arr[i]).repeat(arr[i] * 2);
            }else{
                answer = answer.substring(0,answer.length()-arr[i]);
            }
        }
            
        return Arrays.stream(answer.split("")).mapToInt(Integer::parseInt).toArray();
    }
}

/*
import java.util.*;

class Solution {
    public int[] solution(int[] arr, boolean[] flag) {
        List<Integer> answer = new ArrayList<>();
        
        int len = arr.length;
        
        for(int i=0; i<len; i++){
            if(flag[i]){
                for(int j=0; j<arr[i]*2; j++){
                    answer.add(arr[i]);
                }
            }else{
                answer = answer.subList(0,answer.size()-arr[i]);
            }
        }
            
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
*/