class Solution {
    public String solution(String my_string, int[][] queries) {
        StringBuffer sb = new StringBuffer(my_string);
        
        for(int i=0; i<queries.length; i++){
            StringBuffer revStr = new StringBuffer(sb.substring(queries[i][0],queries[i][1]+1)).reverse();
            
            sb = new StringBuffer(sb.substring(0,queries[i][0]) + revStr.toString() + sb.substring(queries[i][1]+1));    
        }
        
        return sb.toString();
    }
}