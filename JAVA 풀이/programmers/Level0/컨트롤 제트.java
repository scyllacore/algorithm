import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public int solution(String s) {
        List<String> value = Arrays.stream(s.split(" ")).collect(Collectors.toList());

        for(;;){
            int idx = value.indexOf("Z");

            if(idx == -1){
                break;
            }
            value.set(idx,"0");
            value.set(idx-1,"0");
        }
        
        return value.stream().mapToInt(Integer::parseInt).sum();
    }
}

/*
import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();

        for (String w : s.split(" ")) {
            if (w.equals("Z")) {
                stack.pop();
            } else {
                stack.push(Integer.parseInt(w));
            }
        }
        for (int i : stack) {
            answer += i;
        }
        return answer;
    }
}

*/