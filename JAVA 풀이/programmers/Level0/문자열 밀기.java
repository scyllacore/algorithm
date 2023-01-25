class Solution {
    public int solution(String A, String B) {
        
        //return B.repeat(2).indexOf(A);
        
        String pushedA = A;
        Integer length = A.length();
        
        for(Integer loop=0; loop<length; loop++){
            if(pushedA.equals(B)){
                return loop;
            }
            pushedA = pushedA.substring(length-1) + pushedA.substring(0,length-1);
        }
        
        return -1;
    }
}