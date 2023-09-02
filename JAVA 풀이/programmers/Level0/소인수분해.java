import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int n) {
        List<Integer> answer = new ArrayList<>();

        for(int i=2; i<=n/i; i++){

            for(;n%i == 0;) {
                answer.add(i);
                n/=i;
            }
        }

        if(n!=1){
            answer.add(n);
        }

        return answer.stream().distinct().mapToInt(Integer::intValue).toArray();
    }
}