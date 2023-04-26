import java.util.*;

class Solution {
    public int[] solution(String myString) {
        myString += "x*";
        
        return Arrays.stream(myString.split("x"))
            .filter(str -> !str.equals("*"))
            .mapToInt(str -> str.length())
            .toArray();
    }
}

/*
import java.util.Arrays;

class Solution {
    public int[] solution(String myString) {
        return Arrays.stream(myString.split("x", -1))
                .mapToInt(String::length)
                .toArray();
    }
}
*/