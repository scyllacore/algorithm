import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(String[] s1, String[] s2) {
        int answer = 0;
        
        Set<String> s1Set = new HashSet<>(
            Arrays.stream(s1).collect(Collectors.toList())
        );

        for(String s : s2){
            if(s1Set.contains(s)){
                answer++;
            }
        }
        
        return answer;
    }
}

/*
import java.util.*;
class Solution {
    public int solution(String[] s1, String[] s2) {
        Set<String> set = new HashSet<>(Arrays.asList(s1));
        return (int)Arrays.stream(s2).filter(set::contains).count();
    }
}
*/