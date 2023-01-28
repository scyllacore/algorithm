class Solution {
    public int solution(int[] numbers) {
        int maxValue=Integer.MIN_VALUE;

        int length = numbers.length;

        for(int i=0; i<length-1; i++){
            for(int j=i+1; j<length; j++){
                maxValue = Math.max(numbers[i] * numbers[j] , maxValue);
            }
        }
        
        return maxValue;
    }
}