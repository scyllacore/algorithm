class Solution {
    public int solution(String my_string) {
        String[] symbol = my_string.split(" ");
        
        int answer = Integer.parseInt(symbol[0]);
        
        for(Integer i=2; i<symbol.length; i+=2){
            Integer number = Integer.parseInt(symbol[i]);
             answer += (symbol[i-1].equals("+") ? 1 : -1) * number;
        }
        
        return answer;
    }
}