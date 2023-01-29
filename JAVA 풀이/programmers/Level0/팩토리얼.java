class Solution {
    public int solution(int n) {
        int number=1;

        for(int i=2; i<=10; i++){
            number *= i;

            if(number>n){
                return i-1;
            }
        }
        
        return 10;
        
    }
}