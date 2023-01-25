class Solution {
    public String[] solution(String my_str, int n) {
        
        Integer length = my_str.length();
        Integer wordCount = length/n;
        Integer start=0;
        String[] result;
        
        if(length % n == 0 ){
           result = new String[wordCount];
            
            for(Integer i=0; i<wordCount; i++){
                result[i] = my_str.substring(start,start+n);
                start += n;
            }
        }
         else{
            result = new String[wordCount+1];
            
            for(Integer i=0; i<wordCount; i++){
                result[i] = my_str.substring(start,start+n);
                start += n;
            }
             
         result[wordCount] = my_str.substring(start);
         }

    return result;    
    } 
}