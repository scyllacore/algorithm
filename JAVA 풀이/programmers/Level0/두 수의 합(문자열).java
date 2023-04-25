import java.math.BigInteger;

class Solution {
    public String solution(String a, String b) {
        BigInteger intA = new BigInteger(a);
        BigInteger intB = new BigInteger(b);
          
        return String.valueOf(intA.add(intB));
    }
}

/*

        int maxLen = Math.max(a.length(),b.length());
        a = "0".repeat(maxLen-a.length()) + a;
        b = "0".repeat(maxLen-b.length()) + b;
        
        String answer = "";

        int carry = 0;
        for(int i=maxLen-1; i>=0; i--){
            int sum = a.charAt(i) - '0' + b.charAt(i) - '0' + carry;
            answer = String.valueOf(sum%10) + answer;
            carry = sum / 10;
        }

        if(carry == 1){
            answer = "1" + answer;
        }
        
        return answer;
*/