import java.util.stream.Stream;

class Solution {
    public int[] solution(int n) {
        return Stream.iterate(1, i -> i <= n, i -> i + 2).mapToInt(Integer::intValue).toArray();
    }
}

//https://www.daleseo.com/java9-stream-iterate/