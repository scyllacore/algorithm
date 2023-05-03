import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        for(int[] query : queries){
            int tmp = arr[query[0]];
            arr[query[0]] = arr[query[1]];
            arr[query[1]] = tmp;
        }
        
        return arr;
    }
}

/*
import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        List<Integer> answer = new ArrayList<>(Arrays.stream(arr).boxed().collect(Collectors.toList()));
        
        for(int i=0; i<queries.length; i++){
            List<Integer> tmp = new ArrayList<>();
            
            tmp.addAll(answer.subList(0,queries[i][0]));
            
            List<Integer> rev = new ArrayList<>(answer.subList(queries[i][0],queries[i][1] + 1));
            Collections.reverse(rev);
            tmp.addAll(rev);
            
            tmp.addAll(answer.subList(queries[i][1]+1,arr.length)); 
            
            answer = tmp;
            
            System.out.println(answer);
        }
                                               
        return answer.stream().mapToInt(Integer::intValue).toArray();                                        
    }
}
*/