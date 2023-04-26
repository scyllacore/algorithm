class Solution {
    public int[] solution(int[] arr) {
        int len;
        for(len=1; len < arr.length; len *= 2){}  
        
        int[] answer = new int[len]; 
        System.arraycopy(arr,0,answer,0,arr.length);
        
        return answer;
    }
}

/*
class Solution {
    public int[] solution(int[] arr) {
        int len;
        for(len=0; len<=10; len++){
            if(arr.length <= (int)Math.pow(2,len)){
                break;
            }
        }
        
        len = (int)Math.pow(2,len);
        
        int[] answer = new int[len];
        
        System.arraycopy(arr,0,answer,0,arr.length);
        
        return answer;
    }
}
*/