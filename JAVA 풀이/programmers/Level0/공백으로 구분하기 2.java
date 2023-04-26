import java.util.*;

class Solution {
    public String[] solution(String my_string) {
        return Arrays.stream(my_string.split(" "))
            .filter(str -> !str.isEmpty())
            .toArray(String[]::new);
    }
}

/*
class Solution {
    public String[] solution(String my_string) {
        return my_string.trim().split("[ ]+");
    }
}
https://coding-factory.tistory.com/129
https://sooftware.io/regex/
*/