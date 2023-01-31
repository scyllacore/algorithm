import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int[] numbers, int num1, int num2) {
        List<Integer> answer = new ArrayList<>();
        
        for(int i=num1; i<=num2; i++){
            answer.add(numbers[i]);
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
        //return Arrays.copyOfRange(numbers, num1, num2 + 1);
        
    }
}