class Solution {
    public String solution(String my_string, int[] indices) {
        StringBuffer sb = new StringBuffer(my_string);
        
        for(int idx : indices){
            sb.setCharAt(idx,' ');
        }
        
        return sb.toString().replace(" ","");
        
    }
}