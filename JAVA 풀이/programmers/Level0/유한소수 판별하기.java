import java.util.ArrayList;
import java.util.List;

class Solution {
    public int solution(int a, int b) {
       int gcd = getGCD(a,b);

        b/=gcd;

        for(;b>1;){
            if(b%2 == 0){
                b/=2;
                continue;
            }

            if(b%5 == 0){
                b/=5;
                continue;
            }

            return 2;
        }

        return 1;
    }
    
     public int getGCD(int a, int b) {
        int tmp;

        for (; b != 0; ) {
            tmp = a % b;
            a = b;
            b = tmp;
        }

        return a;
    }
    
}


/*
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int solution(int a, int b) {
        List<Integer> aPrimeFactor = getPrimeFactor(a);
        List<Integer> bPrimeFactor = getPrimeFactor(b);

        for(int i=0; i<aPrimeFactor.size(); i++){
            if(bPrimeFactor.contains(aPrimeFactor.get(i))){
                bPrimeFactor.remove(bPrimeFactor.indexOf(aPrimeFactor.get(i)));
                //a.remove(i); size() 값이 변함으로 반복문 조건이 변함.
                aPrimeFactor.set(i,0);
            }
        }

        for(int index : bPrimeFactor){
            if(!(index == 2 || index == 5)){
                return 2;
            }
        }

        return 1;

    }
    
    public List<Integer> getPrimeFactor(int n) {
        List<Integer> primeFactor = new ArrayList<>();

        int quotient = n;

        for (int i = 2; i <= n / i; i++) {
            for (; quotient % i == 0; ) {
                primeFactor.add(i);
                quotient /= i;
            }
        }

        if (quotient != 1) {
            primeFactor.add(quotient);
        }

        return primeFactor;
    }
    
}
*/