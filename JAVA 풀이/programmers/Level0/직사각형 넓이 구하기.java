import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int solution(int[][] dots) {
        Arrays.sort(dots, new Comparator<int[]>() {
            @Override
            public int compare(int[] pos1, int[] pos2) {
                if (pos1[0] == pos2[0]) {
                    return pos1[1] - pos2[1];
                }
                return pos1[0] - pos2[0];
            }
        });
    
        return Math.abs(dots[1][1]-dots[0][1]) * Math.abs(dots[2][0]-dots[0][0]);
    
    }
    
    
}