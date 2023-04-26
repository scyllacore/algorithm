import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        List<Integer> stk = new ArrayList<>();
        
        for(int i=0; i<arr.length; i++){
            if(stk.isEmpty()){
                stk.add(arr[i]);
                continue;
            }
            
            if(stk.get(stk.size()-1) == arr[i]){
                stk.remove(stk.size()-1);
            }
            else{
                stk.add(arr[i]);
            }   
        }
        
        if(stk.isEmpty()){
            return new int[]{-1};
        }
        
        return stk.stream().mapToInt(Integer::intValue).toArray();
        
    }
}

/*
class Solution {
    public int[] solution(int[] arr) {
        Stack<Integer> stack = new Stack<>();

        for (int i : arr) {
            if (stack.size() == 0 || stack.peek() != i) {
                stack.add(i);
            } else {
                stack.pop();
            }

        }
        return stack.size() > 0 ? stack.stream().mapToInt(i -> i).toArray() : new int[] {-1};
    }
}
*/