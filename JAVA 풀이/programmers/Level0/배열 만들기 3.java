class Solution {
    public int[] solution(int[] arr, int[][] intervals) {
        int size1 = intervals[0][1] -  intervals[0][0] + 1;
        int size2 = intervals[1][1] -  intervals[1][0] + 1;
        
        int[] answer = new int[size1 + size2];
        
        System.arraycopy(arr,intervals[0][0],answer,0,size1);
        System.arraycopy(arr,intervals[1][0],answer,size1,size2);
        
        return answer;
    }
}

/*
import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] arr, int[][] intervals) {
        List<Integer> list = new ArrayList<Integer>();

        for(int i=0; i< intervals.length; i++) {

            list.addAll(Arrays.stream(Arrays
                    .copyOfRange(arr, intervals[i][0], intervals[i][1] + 1))
                .boxed()
                .collect(Collectors.toList()));
        }

        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
*/