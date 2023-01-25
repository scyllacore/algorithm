class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
    
        for (Integer i = 0; i < quiz.length; i++) {
            String[] symbol = quiz[i].split(" ");

            Integer result = Integer.parseInt(symbol[0]) + Integer.parseInt(symbol[2]) * (symbol[1].equals("-") ? -1 : 1);
            
            answer[i] = result.equals(Integer.parseInt(symbol[4])) ? "O" : "X";

        }
     
        return answer;
    }
}

/*
import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
        
        List<String> symbol;
        String expression;
        String operator;
        Integer a;
        Integer b;
        Integer result;

        for (Integer i = 0; i < quiz.length; i++) {
            expression = quiz[i];
            symbol = Arrays.stream(expression.split(" "))
                .collect(Collectors.toList());

            operator = symbol.get(1);
            a = Integer.parseInt(symbol.get(0));
            b = Integer.parseInt(symbol.get(2));

            if (operator.equals("+")) {
                result = a + b;
            } else {
                result = a - b;
            }

            if(result.equals(Integer.parseInt(symbol.get(4)))){
                answer[i] = "O";
            }
            else{
                answer[i] = "X";
            }

        }
     
        return answer;
    }
}
*/