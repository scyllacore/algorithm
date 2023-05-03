class Solution {
    public int solution(int a, int b, int c) {
        int[] dice = new int[7];
        dice[a]++;
        dice[b]++;
        dice[c]++;
        
        int size=0;
        
        for(int n : dice){
            if(n>0){
                size++;
            }
        }
        
        int answer=1;
        
        for(int i=size-1; i<3; i++){
            answer *= (int)Math.pow(a,3-i)+(int)Math.pow(b,3-i)+(int)Math.pow(c,3-i);
        }
        
        return answer;
    }
}