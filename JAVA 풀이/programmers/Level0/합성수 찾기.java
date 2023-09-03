class Solution {
    
    boolean[] prime = new boolean[101];
    
    public void eratos(){
        
        for(int i=2; i<=100/i; i++){
            if(prime[i] == false){
                for(int j = i*i; j<=100; j+=i){
                    prime[j] = true;
                }
            }
        }
        
    }
    
    public int solution(int n) {
        eratos();

        int answer = 0;
        
        for(int i=4; i<=n; i++){
            if(prime[i] == true){
                answer++;
            }
        }
        
        return answer;
    }
    
}