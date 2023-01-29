import java.util.Arrays;

class Solution {
    public int[] solution(String[] strlist) {
        return Arrays.stream(strlist).map(str -> str.length()).mapToInt(Integer::intValue).toArray();
    }
}