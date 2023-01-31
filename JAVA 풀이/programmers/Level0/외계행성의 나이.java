import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public String solution(int age) {
        return Arrays.stream(String.valueOf(age).split("")).map(n -> String.valueOf((char)(n.charAt(0)-'0'+'a'))).collect(Collectors.joining());
    }
}