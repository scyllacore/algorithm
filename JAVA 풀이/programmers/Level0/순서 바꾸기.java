class Solution {
    public int[] solution(int[] num_list, int n) {
        int len = num_list.length;
        int[] answer = new int[len];
        
        for(int i=0; i<len; i++){
            answer[i] = num_list[(n+i)%len];
        }
        
        return answer;
    }
}

/*
class Solution {
    public int[] solution(int[] num_list, int n) {
        int[] answer = new int[num_list.length];
        
        System.arraycopy(num_list,n,answer,0,num_list.length-n);
        System.arraycopy(num_list,0,answer,num_list.length-n,n);
        
        return answer;
    }
}
*/

//https://hianna.tistory.com/601

/*
import java.util.stream.IntStream;

class Solution {
    public int[] solution(int[] num_list, int n) {
        return IntStream.range(0, num_list.length).map(i -> num_list[(i + n) % num_list.length]).toArray();
    }
}
*/