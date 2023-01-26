import java.util.Arrays;

class Solution {
    public String solution(String my_string) {
        boolean[] checker = new boolean[128];
        Arrays.fill(checker, false);
        
        String answer = "";
        
         for (int i = 0; i < my_string.length(); i++) {
            Character ch = my_string.charAt(i);

            if (checker[ch] == false) {
                answer += ch.toString();
                checker[ch] = true;
            }
        }
        
        return answer;
        
        // return Arrays.stream(myString.split("")).distinct().collect(Collectors.joining());
        
    }
}