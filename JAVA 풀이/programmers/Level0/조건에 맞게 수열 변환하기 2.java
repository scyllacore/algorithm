class Solution {
    public int solution(int[] arr) {
        int answer;
        
        for(answer=0; ; answer++){
            
            boolean flag = false;
            
            for(int j=0; j<arr.length; j++){
                if(arr[j]>=50 && arr[j] % 2 == 0){
                    arr[j] /= 2;
                    flag = true;
                }
                else if(arr[j]<50 && arr[j] % 2 == 1){
                    arr[j] = arr[j]*2 + 1;
                    flag = true;
                }
            }
            
            if(flag == false){
                break;
            }
        }
     
        
        return answer;
    }
}

/*
class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        
        int maxVal = 0;
        int minVal = 100;
        
        for(int i=0; i<arr.length; i++){
            if(arr[i] % 2 == 0){
                maxVal = Math.max(arr[i],maxVal);
            }
            
            if(minVal % 2 == 1){
                minVal = Math.min(arr[i],minVal);
            }
        }
        
        for(;;){
            
            if(maxVal >= 50 && maxVal % 2 == 0){
                maxVal /= 2;
            }
            else if(maxVal < 50 && maxVal % 2 == 1){
                maxVal = maxVal * 2 + 1;
            }
            
            if(minVal >= 50 && minVal % 2 == 0){
                maxVal /= 2;
            }
            else if(minVal < 50 && minVal % 2 == 1){
                minVal = minVal * 2 + 1;
            }
            
            answer++;
            
            if((maxVal >= 50 && maxVal % 2 == 1 || maxVal < 50 && maxVal % 2 == 0)
              && (minVal >= 50 && minVal % 2 == 1 || minVal < 50 && minVal % 2 == 0)
              ){
                break;
            }
        
        }
        
        return answer;
    }
}
*/