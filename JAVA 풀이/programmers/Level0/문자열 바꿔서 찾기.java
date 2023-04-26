import java.util.*;

class Solution {
    public int solution(String myString, String pat) {
        StringBuffer sb = new StringBuffer(myString);
        
        for(int i=0; i<sb.length(); i++){
        sb.setCharAt(i,(char)('B'- sb.charAt(i) + 'A'));
        }
        
        return sb.toString().contains(pat) ? 1 : 0;
        
    }
}