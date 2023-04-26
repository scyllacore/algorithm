import java.util.*;

class Solution {
    public String[] solution(String myString) {
        return Arrays.stream(myString.split("x"))
            .filter(s -> !s.isEmpty())
            .sorted((s1,s2) -> s1.compareTo(s2))
            .toArray(String[]::new);
    }
}