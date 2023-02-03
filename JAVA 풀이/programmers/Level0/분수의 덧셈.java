class Solution {
    private int getGcd(int a, int b) {
        int tmp;
        for (; b != 0; ) {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int lcm = denom1 * denom2 / getGcd(denom1, denom2);
        
        int denom = lcm/denom1 * numer1 + lcm/denom2 * numer2;
        int numer = lcm;
        
        int gcd = getGcd(denom,numer);
        
        denom /= gcd;
        numer /= gcd;    
        
        return new int[]{denom,numer};
    }
}