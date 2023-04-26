class Solution {
    public int solution(String binomial) {
        String[] term = binomial.split(" ");
        
        if(term[1].equals("+")){
            return Integer.parseInt(term[0]) + Integer.parseInt(term[2]);
        }
        
        if(term[1].equals("-")){
            return Integer.parseInt(term[0]) - Integer.parseInt(term[2]);
        }
        
        return Integer.parseInt(term[0]) * Integer.parseInt(term[2]);
    }
}