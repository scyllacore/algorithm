import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] arr, String direction) {
        List<Integer> numbers = Arrays.stream(arr).boxed().collect(Collectors.toList()); 
        
        if(direction.charAt(0) == 'r'){
            numbers.add(0, numbers.get(numbers.size()-1));
            numbers.remove(numbers.size()-1);
        }
        else{
            numbers.add(numbers.get(0));
            numbers.remove(0);
        }
        
        return numbers.stream().mapToInt(Integer::intValue).toArray();
    }
}