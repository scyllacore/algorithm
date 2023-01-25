class Solution {
    public String solution(String my_string) {
        StringBuffer sb = new StringBuffer(my_string);

        for(int i=0; i<sb.length(); i++){
            if (sb.charAt(i) >= 'A' && sb.charAt(i) <= 'Z') {
                sb.setCharAt(i, (char)(sb.charAt(i)+32)); // 아스키 코드값을 이용해 변환을 원할 때는 형변환을 해줘야한다.
            }
            else{
                sb.setCharAt(i, (char)(sb.charAt(i)-32));
            }
        }
        
        return sb.toString();
    }
}

/*
import java.util.stream.Collectors;

class Solution {
    public String solution(String myString) {
        return myString.chars().mapToObj(operand -> String.valueOf((char) (Character.isLowerCase(operand) ? Character.toUpperCase(operand) : Character.toLowerCase(operand)))).collect(Collectors.joining());
    }
}
* */