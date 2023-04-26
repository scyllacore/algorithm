import java.util.*;

class Solution {
    public int solution(String[] strArr) {
        int[] lenArr = new int[31]; 
        Arrays.fill(lenArr,0);
        
        for(String str : strArr){
            lenArr[str.length()]++;
        }
        
        return Arrays.stream(lenArr).max().getAsInt();
    }
}

//https://www.delftstack.com/ko/howto/java/java-find-max-in-array/