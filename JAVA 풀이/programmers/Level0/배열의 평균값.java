import java.util.Arrays;

class Solution {
    public double solution(int[] numbers) {      
        //return Arrays.stream(numbers).asDoubleStream().average().getAsDouble();
        
        return Arrays.stream(numbers).average().getAsDouble();
        
    }
}

//return  Arrays.stream(numbers).average().orElse(0); orElse는 좀 탐구해볼 것.