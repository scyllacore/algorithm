import java.util.*;

class Solution {
    public int[] solution(String my_string) {
        int[] answer = new int[52];
        
        Arrays.fill(answer,0);
        
        for(int i=0; i<my_string.length(); i++){
            char ch = my_string.charAt(i);
            
            if(Character.isUpperCase(ch)){
            answer[my_string.charAt(i) - 'A']++;
            }
            else{
            answer[my_string.charAt(i) - 71]++;
            }
        }
        
        return answer;
        
    }
}