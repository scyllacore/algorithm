import java.math.BigInteger;

class Solution {
    public int solution(int balls, int share) {
  
        BigInteger nPr = new BigInteger("1");
        BigInteger rFac = new BigInteger("1");

        for (int i = balls; i > balls - share; i--) {
            nPr = nPr.multiply(new BigInteger(String.valueOf(i)));
        }

        System.out.println(nPr);

        for (int i = share; i > 1; i--) {
            rFac = rFac.multiply(new BigInteger(String.valueOf(i)));
        }

        return nPr.divide(rFac).intValue();
    }
}