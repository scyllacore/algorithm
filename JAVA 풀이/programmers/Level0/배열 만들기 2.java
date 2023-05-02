import java.util.*;

class Solution {
    public int[] solution(int l, int r) {
        List<Integer> answer = new ArrayList<>();

        for(int bit = 0; bit< (1<<7); bit++){
           int num = Integer.parseInt(Integer.toBinaryString(bit).replace("1","5"));
            
            if(num>=l && num <=r){
                answer.add(num);
            }  
        }
        
        if(answer.size() == 0){
            return new int[]{-1};
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
        
    }

}
/*
import java.util.*;

class Solution {
    public int[] solution(int l, int r) {
        List<Integer> answer = new ArrayList<>();

        for(int bit = 0; bit< (1<<7); bit++){
           answer.add(Integer.parseInt(Integer.toBinaryString(bit).replace("1","5")));
        }

        int start = lower_bound(answer,l);
        int end = upper_bound(answer,r);

        answer = answer.subList(start,end);
        
        if(answer.size() == 0){
            return new int[]{-1};
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
        
    }
    
     private static int lower_bound(List<Integer> list,int target){
        int begin =0;
        int end = list.size();

        int mid;

        for(;begin < end;){
            mid = (begin+end)/2;

            if(list.get(mid) < target){
                begin = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return begin;
    }

    private static int upper_bound(List<Integer> list,int target){
        int begin =0;
        int end = list.size();

        int mid;

        for(;begin < end;){
            mid = (begin+end)/2;

            if(list.get(mid) <= target){
                begin = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return begin;
    }
    
}
*/