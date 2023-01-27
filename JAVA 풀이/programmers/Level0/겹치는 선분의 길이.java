import java.util.Arrays;

class Solution {
    public int solution(int[][] lines) {
        int[] vertical = new int[200];
        Arrays.fill(vertical,0);

        for(int[] line : lines){
            for(int i=line[0]+100; i<line[1]+100; i++) { // i<=line[1]-99
                vertical[i] += 1;
            }
        }

        int answer = 0;

        for(int line : vertical){
            if(line > 1){
                answer++;
            }
        }
        
        return answer;
    }
}

// index -3에 1이 들어갔다면 -3~-2 구간에 선분이 존재함을 의미.
