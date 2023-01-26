import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] numlist, int n) {
         List<Integer> list = Arrays.stream(numlist).boxed().collect(Collectors.toList());
        Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                if(Math.abs(n - a) == Math.abs(n - b)){
                    return b-a;
                }
                return Math.abs(n - a) - Math.abs(n - b);
            }
        });

        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}

//https://hianna.tistory.com/552

/*
Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return Math.abs(n - b) - Math.abs(n - a);
            }
        });
        Collections.reverse(list);
*/

/*
Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                if(Math.abs(n - b) - Math.abs(n - a) > 0){
                    return 1;
                }
                if(Math.abs(n - b) == Math.abs(n - a)){
                    return b-a;
                }

                return -1;
            }
        });

        Collections.reverse(list);
*/

//https://hianna.tistory.com/552