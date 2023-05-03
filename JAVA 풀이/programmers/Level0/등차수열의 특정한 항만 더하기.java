import java.util.stream.IntStream;

class Solution {
    public int solution(int a, int d, boolean[] included) {
        return IntStream.iterate(0, i -> i<included.length, i -> i+1)
            .filter(i -> included[i] == true)
            .map(i -> a+d*i)
            .sum();
    }
}