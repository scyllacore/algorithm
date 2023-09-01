class Solution {
    public int solution(int[] common) {

        int len = common.length;
        
        if(common[1]-common[0] == common[2]-common[1]){
            return common[len-1] + common[1]-common[0];
        }
        
        return common[2]/common[1] * common[len-1];

    }
}


/*
class Solution {
    public int solution(int[] common) {
        Integer number1 = common[0];
        Integer number2 = common[1];
        Integer number3 = common[2];
        
        if(number2-number1 == number3-number2){
            return common[common.length-1] + number2-number1;
        }
        
        return number3/number2 * common[common.length-1];

    }
}
 */