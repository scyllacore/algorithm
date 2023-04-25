class Solution {
    public String solution(String n_str) {
        int idx;
        for(idx=0; idx<n_str.length(); idx++){
            if(n_str.charAt(idx) != '0'){
                break;
            }
        }
        
        return n_str.substring(idx);  
        
        // return "" + Integer.parseInt(n_str);
    }
}