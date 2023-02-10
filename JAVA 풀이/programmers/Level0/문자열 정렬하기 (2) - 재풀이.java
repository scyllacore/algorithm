import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public String solution(String my_string) {
        return  Arrays.stream(my_string.toLowerCase().split("")).sorted((o1, o2) -> o1.compareTo(o2)).collect(Collectors.joining());
    }
}