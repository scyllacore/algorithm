import java.util.*;

class Solution {
    public int solution(int[] num_list) {
        if(num_list.length >= 11){
            return Arrays.stream(num_list).reduce(0,(sum,i) -> sum + i);
        }
        
        return Arrays.stream(num_list).reduce(1,(sum,i) -> sum * i);
    }
}