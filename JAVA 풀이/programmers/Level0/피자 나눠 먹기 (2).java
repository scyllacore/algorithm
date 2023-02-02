class Solution {
    private int getGcd(int n,int m){
        int tmp;
        
        while(m != 0){
            tmp = n%m;
            n = m;
            m = tmp;
        }        
        
        return n;
    } 
    
    private int getLcm(int n,int m){
        return n*m / getGcd(n,m);
    }
    
    
    public int solution(int n) {
        return getLcm(n,6) / 6;
    }
}

/*
class Solution {
    public int solution(int n) {
        for(int i=1; ;i++){
            if((i*6)% n == 0){
                return i;
            }
        }
    }
}
*/

//다시 생각해볼 것.