class Solution {
    public int solution(int n, int t) {
        int result=n;
        
        for(Integer loop=0; loop<t; loop++){
            result *=2;
        }
        
        return result;
      
    }
}