import java.util.stream.IntStream;


class Solution {
    public int solution(int n) {
        return IntStream.iterate(n%2, i->i<=n, i->i+2).map(i -> (int)Math.pow(i,2-n%2)).sum();
    
    }
}