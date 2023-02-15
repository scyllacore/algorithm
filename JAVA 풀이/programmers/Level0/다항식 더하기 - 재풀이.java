import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public String solution(String polynomial) {
        List<String> variables = Arrays.stream(polynomial.split(" \\+ ")).collect(Collectors.toList());

        int coefficient = 0;
        int constant = 0;

        for (String var : variables) {
            if (var.contains("x")) {
                if (var.length() > 1) {
                    coefficient += Integer.parseInt(var.substring(0, var.length() - 1));
                } else {
                    coefficient += 1;
                }
            } else {
                constant += Integer.parseInt(var);
            }
        }

        String answer = "";

        if (coefficient > 1) {
            answer += String.format("%dx", coefficient);
        } else if (coefficient == 1) {
            answer += "x";
        }

        if (coefficient > 0 && constant > 0) {
            answer += " + ";
        }

        if(constant > 0 ){
            answer += String.valueOf(constant);
        }

        return answer;
    }
}