import java.util.List;

class Solution {
    public long solution(String numbers) {
        
        List<String> numberWords = List.of("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine");

        for (int i = 0; i < numberWords.size(); i++) {
            numbers = numbers.replaceAll(numberWords.get(i), String.format("%s",i));
        }
 
        return Long.parseLong(numbers);
    }
}