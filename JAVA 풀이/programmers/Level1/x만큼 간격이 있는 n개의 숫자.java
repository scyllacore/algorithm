import java.util.stream.Stream;

class Solution {
    public long[] solution(int x, int n) {
        return Stream.iterate(1, i -> i <= n, i -> i + 1).mapToLong(value -> (long)value * x).toArray();
    }
}