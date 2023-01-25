class Solution {
    public int solution(int[] array) {
       int answer = 0;
        
        String numbers = "";
        
        for(Integer i=0; i<array.length; i++){
            Integer number = array[i];
            numbers += number.toString();
        }
        
        for(Integer i=0; i<numbers.length(); i++){
            if(numbers.charAt(i) == '7'){
                answer++;
            }
        }
        
    
        return answer;
    }
}

/*
class Solution {
    public int solution(int[] array) {
    
       int answer = 0;
        
        for(Integer i=0; i<array.length; i++){
            for(;array[i]>0;){
                if(array[i]%10 == 7){
                    answer++;
                }
                array[i]/=10;
            }  
        }
    
        return answer;
    }
}
*/

//https://junho85.pe.kr/1584