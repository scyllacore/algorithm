import java.util.Arrays;

class Solution {
    public int solution(int[] sides) {
        sides = Arrays.stream(sides).sorted().toArray();
        return sides[0] + sides[1] > sides[2] ? 1 : 2;
    }
}