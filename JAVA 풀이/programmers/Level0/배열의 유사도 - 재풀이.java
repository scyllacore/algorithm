import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

class Solution {
    public int solution(String[] s1, String[] s2) {
       Set<String> s1Set = new HashSet<>(
                Arrays.stream(s1).collect(Collectors.toList())
                );
        
        int answer =0;
        
        for(String s : s2){
            if(s1Set.contains(s)) {
                answer++;
            }
        }
        
        return answer;
    }
}