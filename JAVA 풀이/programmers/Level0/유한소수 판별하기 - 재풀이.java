class Solution {
    public int solution(int a, int b) {
        int gcdVal = getGcd(a,b);

        b/=gcdVal;

        for(;b>1;){

            if(b%2==0){
                b/=2;
                continue;
            }

            if(b%5==0){
                b/=5;
                continue;
            }

            return 2;

        }

        return 1;
    }
    
    private int getGcd(int a,int b){
        int tmp;

        for(;b!=0;){
            tmp = a%b;
            a = b;
            b = tmp;
        }

        return a;
    }
}