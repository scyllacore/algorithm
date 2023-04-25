import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] arr, int[] delete_list) {      
        Set<Integer> numSet = Arrays.stream(delete_list).boxed().collect(Collectors.toSet());
        
        //Set<Integer> numSet = new HashSet<>(Arrays.stream(arr).boxed().collect(Collectors.toSet()));
        
        List<Integer> answer = new ArrayList<>();
        
        for(int val : arr){
            if(!numSet.contains(val)){
                answer.add(val);
            }
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
        
        //return answer.toArray(Integer[]::new);
    }
}