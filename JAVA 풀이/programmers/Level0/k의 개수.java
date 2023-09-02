class Solution {
    public int solution(int i, int j, int k) {
        int answer = 0;

        for(; i<=j; i++){
            int n = i;
            
            for(;n>0;){
                if(n%10 == k){
                    answer++;
                }
                n/=10;
            }
        }
        
        return answer;
    }
}

/*
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
 */