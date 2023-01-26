class Solution {
    public int solution(int i, int j, int k) {
        int answer = 0;
        int end = j;
        
        //String str = n+"";

        for(int number=i; number<=j; number++){
            int tmp = number;
            
            for(;tmp>0;){
                if(tmp%10 == k){
                    answer++;
                }
                tmp/=10;
            }
        }
        
        return answer;
    }
}