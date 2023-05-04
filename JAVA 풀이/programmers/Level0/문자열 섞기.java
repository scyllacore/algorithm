import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public String solution(String str1, String str2) {
        return IntStream.range(0,str1.length()).mapToObj(i -> String.valueOf(str1.charAt(i)) + str2.charAt(i)).collect(Collectors.joining());
    }
}
/*
import java.util.*;

class Solution {
    public String solution(String str1, String str2) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0;i < str1.length();i++)
            sb.append(str1.charAt(i)).append(str2.charAt(i));
        return sb.toString();
    }
}
*/