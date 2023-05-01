import java.math.*;
import java.util.*;

class Solution {
    public int solution(String number) {      
    //return Arrays.stream(number.split("")).mapToInt(Integer::parseInt).sum() % 9;
       return new BigInteger(number).mod(BigInteger.valueOf(9)).intValue();
    }
}