import java.util.*;

class Solution {
    public int solution(int[][] lines) {

        /*
        Arrays.sort(lines, new Comparator<int[]>(){
            @Override
            public int compare(int[] a,int[] b){
                if(a[0] == b[0]){
                    return a[1] - b[1];
                }
                return a[0] - b[0];
            }
        });

        //일반 배열은 Arrays로 wrapper 객체는 Collections으로, 간단하게 처리하는 방법(람다식 등) 찾아볼 것.
         */

        int overlap[] = new int[202];
        int answer=0;

        for(int[] line : lines){
            overlap[line[0]+101]++;
            overlap[line[1]+101]--;
        }

        for(int i = 1; i<202; i++){
            overlap[i] += overlap[i-1];
            
            if(overlap[i]>1){
                answer++;
            }
        }
        
        return answer;
    }
}


/*
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
 */