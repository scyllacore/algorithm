import java.util.*;

class Solution {
    public String solution(int[] numLog) {
        StringBuffer sb = new StringBuffer();
        
        Map<Integer,Character> cmd = new HashMap<>(
            Map.of(
                1,'w'
                ,-1,'s'
                ,10,'d'
                ,-10,'a'
            )
        );
        
        for(int i=1; i<numLog.length; i++){
            sb.append(cmd.get(numLog[i]-numLog[i-1]));
        }
        
        return sb.toString();
    }
}