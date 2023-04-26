import java.util.*;

class Solution {
    public int[] solution(int[] arr, int k) {
        int[] answer = new int[k];
        Arrays.fill(answer,-1);
        
        arr = Arrays.stream(arr).distinct().toArray();
        
        int len = Math.min(arr.length,k);
        System.arraycopy(arr,0,answer,0,len);
        
        return answer;
    }
}