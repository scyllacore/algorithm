class Solution {
    public static int gcd(int a,int b){
        int tmp;
        
        for(;b!=0;){
            tmp = a%b;
            a = b;
            b = tmp;
        }
        
        return a;
    }
    
    public static int lcm(int a,int b){
        return a*b / gcd(a,b);
    }
    
    public int solution(int number, int n, int m) {
        return number% lcm(n,m) == 0 ? 1 : 0;
    }
}