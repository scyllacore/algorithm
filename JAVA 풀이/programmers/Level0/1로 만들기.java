class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        
        for(int i=0; i<num_list.length; i++){ 
            int n = num_list[i];
            
            for(;n > 1;){
                n /= 2;
                answer++;
            }
        }
        
        return answer;
    }
}