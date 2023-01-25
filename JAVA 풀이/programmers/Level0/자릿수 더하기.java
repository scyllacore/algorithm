class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for(;n>0;){
            answer += n%10;
            n/=10;
        }
        
        return answer;
        //return Arrays.stream(String.valueOf(n).split("")).mapToInt(Integer::parseInt).sum();
    }
}
