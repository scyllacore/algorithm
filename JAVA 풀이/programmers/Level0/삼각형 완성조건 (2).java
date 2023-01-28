import java.util.Arrays;

class Solution {
    public int solution(int[] sides) {
        return 2 * Arrays.stream(sides).boxed().mapToInt(Integer::intValue).min().getAsInt() - 1;
    }
}