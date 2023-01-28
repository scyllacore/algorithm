import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public String solution(String polynomial) {
        List<String> variables  = Arrays.stream(polynomial.split(" \\+ ")).collect(Collectors.toList());

        int coefficient = 0;
        int constant = 0;


        for(String var : variables){
            if(var.contains("x")){
                if(var.length() >= 2){
                    coefficient += Integer.parseInt(var.substring(0,var.length()-1));
                }
                else{
                    coefficient += 1;
                }
            }
            else{
                constant += Integer.parseInt(var);
            }
        }

        String answer = "";

        if(coefficient==1){
            answer += "x";
        }
        else if(coefficient!=0){
             answer += String.format("%dx",coefficient);
        }

        if(coefficient!=0 && constant!=0){
            answer += " + ";
        }

        if(constant!=0){
            answer += String.format("%d",constant);
        }
        
        /*if(answer.isEmpty()){
            return "0";
        }*/

        return answer;
    }
}

/*
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        String polynomial = "x + 2 + 3 + 105";


        List<String> variables  = Arrays.stream(polynomial.split(" \\+ ")).collect(Collectors.toList());

        int coefficient = 0;
        int constant = 0;


        for(String var : variables){
            if(var.contains("x")){
                if(var.length() >= 2){
                    coefficient += Integer.parseInt(var.substring(0,var.length()-1));
                }
                else{
                    coefficient += 1;
                }
            }
            else{
                constant += Integer.parseInt(var);
            }
        }

        String answer = "";

        if(coefficient==1){
            answer += "x";
        }
        else if(coefficient!=0){
            answer += String.format("%dx",coefficient);
        }

        if(coefficient!=0 && constant!=0){
            answer += " + ";
        }

        if(constant!=0){
            answer += String.format("%d",constant);
        }

        if(answer.isEmpty()){
            answer = "0";
        }

        System.out.println(answer);

    }

}
*/