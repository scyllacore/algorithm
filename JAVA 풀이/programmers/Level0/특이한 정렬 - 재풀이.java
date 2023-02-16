import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] numlist, int n) {
         List<Integer> numbers = Arrays.stream(numlist).boxed().collect(Collectors.toList());

        Collections.sort(numbers, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) { // a는 뒷자리 수, b는 앞자리 수이다 이유는 모르겠다
                //System.out.println(b + " " + a);
                if (Math.abs(n - a) == Math.abs(n - b)) {
                    return b - a; // 좀 헷갈리는 요소가 있기에 그냥 -를 가운데 두고 정렬되기 원하는 형태를 적는다.
                    // ex 원래 a(1),b(2)였는데 내림 차순해서 b,a가 되길 원한다면 b-a를 쓰면된다.
                }
                return Math.abs(n - a) - Math.abs(n - b); // 음수값이 반환되면 swap이 일어난다.

            }
        });

        return numbers.stream().mapToInt(i->i).toArray();
    }
}