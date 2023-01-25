import java.util.Arrays;

class Solution {
    public int solution(int order) {     
        return (int)Arrays.stream(String.format("%s", order).split(""))
                .map(Integer::parseInt)
                .filter(number -> number == 3 || number == 6 || number == 9)
                .count();       
/*
        return (int)Arrays.stream(String.format("%s", order).split(""))
                .filter(ch -> ch.equals("3") || ch.equals("6") || ch.equals("9"))
                .count();
*/

    }
}