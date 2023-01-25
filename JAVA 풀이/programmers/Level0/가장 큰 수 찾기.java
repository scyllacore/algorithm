class Solution {
    public int[] solution(int[] array) {
        Integer maxValue = array[0];
        Integer maxIndex = 0;
        
        for(Integer i=1; i<array.length; i++){
            if(array[i] > maxValue){
                maxValue = array[i];
                maxIndex = i;
            }
        }
        
        int[] answer = new int[2];
        answer[0] = maxValue;
        answer[1] = maxIndex;
        
        
        return answer;
    }
}