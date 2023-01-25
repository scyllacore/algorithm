import java.util.*;

class Solution {
    public int[] solution(int n, int[] numlist) {
        return Arrays.stream(numlist).filter(number -> number%n==0).toArray();
    }
}