class Solution {
    public int solution(int[] numbers, int n) {
        int answer = 0;
        
        for(int val : numbers){
            answer += val;
            
            if(answer > n){
                break;
            }
        }
        
        return answer;
    }
}