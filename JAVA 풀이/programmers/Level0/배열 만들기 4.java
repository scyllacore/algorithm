import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        List<Integer> stk = new ArrayList<>();
        
        for(int i=0; i<arr.length;){
            if(stk.isEmpty()){
              stk.add(arr[i]);
                i++;
            }else if(!stk.isEmpty() && stk.get(stk.size()-1) < arr[i]){
                stk.add(arr[i]);
                i++;
            }else if(!stk.isEmpty() && stk.get(stk.size()-1) >= arr[i]){
                stk.remove(stk.size()-1);
            }
        }
        
        return stk.stream().mapToInt(Integer::intValue).toArray();
    }
}

/*
import java.util.*;
class Solution {
    public int[] solution(int[] arr) {
        Stack<Integer> stack = new Stack();
        for(int i : arr ){
            if(stack.isEmpty()){
                stack.push(i);
                continue;
            }
            while(!stack.isEmpty() && i <= stack.peek()) {
                stack.pop();
            }
            stack.push(i);
        }
        int[] answer = new int[stack.size()];
        for(int i=0; i<answer.length; i++) {
            answer[answer.length - 1 - i] = stack.pop();
        }
        return answer;
    }
}
*/