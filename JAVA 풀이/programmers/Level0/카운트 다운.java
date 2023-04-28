import java.util.stream.IntStream;

class Solution {
    public int[] solution(int start, int end) {
        return IntStream.iterate(start,i->i-1).limit(start-end+1).toArray();
    }
}

/*
class Solution {
    public int[] solution(int start, int end) {
        int[] answer = new int[start-end+1];
        
        for(int i=0; i<answer.length; i++){
            answer[i] = start - i;
        }
        
        return answer;
    }
}
*/