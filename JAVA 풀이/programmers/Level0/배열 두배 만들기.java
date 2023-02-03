import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {
        
        return Arrays.stream(numbers).map(i->i*2).toArray();
        //return Arrays.stream(numbers).boxed().map(n -> n*2).mapToInt(Integer::intValue).toArray();

        
        //Arrays.stream(numbers).map(n -> n*2); 값을 하나씩 처리하고 처리한 값들을 어떻게 할지 정해주는 것이 없음.
    }
}