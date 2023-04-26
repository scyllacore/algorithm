import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] num_list) {
        List<Integer> nums = Arrays.stream(num_list)
            .boxed().collect(Collectors.toList());
        
        Collections.sort(nums,new Comparator<Integer>(){
            @Override
            public int compare(Integer a,Integer b){
                return a-b;
            }
        });
        
              
        return nums.stream().limit(5).mapToInt(Integer::intValue).toArray();
    }
}