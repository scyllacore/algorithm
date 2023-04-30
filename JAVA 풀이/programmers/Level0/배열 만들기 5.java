import java.util.stream.IntStream;

class Solution {
    public int[] solution(String[] intStrs, int k, int s, int l) {
        return IntStream.range(0,intStrs.length)
            .map(i -> Integer.parseInt(intStrs[i].substring(s,s+l)))
            // IntStream을 썻음으로 mapToInt는 존재하지 않는다.
            .filter(val -> val > k)
            .toArray();
    }
}

/*
class Solution {
    public int[] solution(String[] intStrs, int k, int s, int l) {
        return Stream.of(intStrs).mapToInt(str -> Integer.parseInt(str.substring(s,s+l))).filter(i->i>k).toArray();
    }
}
*/

/*
return IntStream.range(0,intStrs.length)
            .mapToObj(i -> intStrs[i].substring(k,k+l))
            .filter(str -> String.valueOf(str).compareTo(k) > 0)
            .toArray(String[]::new);
*/