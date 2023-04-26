import java.util.*;

class Solution {
    public int solution(int[] arr1, int[] arr2) {
        if(arr1.length != arr2.length){
            return arr1.length > arr2.length ? 1 : -1;
        }
        
        int sum1 = Arrays.stream(arr1).reduce(0,(total,n) -> total += n);
        int sum2 = Arrays.stream(arr2).reduce(0,(total,n) -> total += n);
     
        if(sum1 != sum2){
            return sum1 > sum2 ? 1 : -1;
        }
        
        return 0;
    }
}
//https://codechacha.com/ko/java8-stream-reduction/

/*
import java.util.Arrays;

class Solution {
    public int solution(int[] arr1, int[] arr2) {
        int compared = Integer.compare(arr1.length, arr2.length);

        if (compared == 0) {
            return Integer.compare(Arrays.stream(arr1).sum(), Arrays.stream(arr2).sum());
        }

        return compared;
    }
}
*/