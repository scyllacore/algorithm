class Solution {
    public int solution(String my_string) {
        int answer = 0;
        int number = 0;

        for (int i = 0; i < my_string.length(); i++) {
            Character ch = my_string.charAt(i);

            if (Character.isDigit(ch)) {
                number = number * 10 + (int) (ch - '0');
            } else {
                answer += number;
                number = 0;
            }
        }
        answer += number;
        
        return answer;
    }
}