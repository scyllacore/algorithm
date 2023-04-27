class Solution {
    public String[] solution(String[] strArr) {
        for(int i=0; i<strArr.length; i++){
            if(i%2==0){
                strArr[i] = strArr[i].toLowerCase();
            }
            else{
                strArr[i] = strArr[i].toUpperCase(); 
            }
        }
        
        return strArr;
    }
}

/*
import java.util.stream.IntStream;

class Solution {
    public String[] solution(String[] strArr) {
        return IntStream.range(0, strArr.length).mapToObj(i -> i % 2 == 0 ? strArr[i].toLowerCase() : strArr[i].toUpperCase()).toArray(String[]::new);
    }
}
*/