import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[][] score) {
        List<Integer> avg = Arrays.stream(score).map(this::getSum).collect(Collectors.toList());
        List<Integer> ranking = new ArrayList<>(Collections.nCopies(avg.size(),1));

        for(int i=0; i<avg.size(); i++){
            for(int j=0; j<avg.size(); j++){
                if(avg.get(i) < avg.get(j)){
                    ranking.set(i,ranking.get(i)+1);
                }
            }
        }

       return ranking.stream().mapToInt(Integer::intValue).toArray();

    }
    
    public Integer getSum(int[] score){
        return Arrays.stream(score).sum();
    }
    
}