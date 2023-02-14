class Solution {
    public int solution(int[][] lines) {
        int overlap[] = new int[200];


        for(int[] line : lines){
            for(int i = line[0]+100; i<line[1]+100; i++){
                overlap[i]++;
            }
        }

        int answer=0;

        for(int overlapCnt : overlap){
            if(overlapCnt > 1){
                answer++;
            }
        }
        
        return answer;
    }
}