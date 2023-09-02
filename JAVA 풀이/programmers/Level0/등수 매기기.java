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


/*
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] solution(int[][] score) {
         List<Integer> average = new ArrayList<>(Collections.nCopies(score.length,0));

        for(int i=0; i<score.length; i++){
            average.set(i,score[i][0]+score[i][1]);
        }

        List<Integer> rank = new ArrayList<>(Collections.nCopies(score.length,1));


        for(int i=0; i<average.size(); i++){
            for(int j=0; j< average.size(); j++){
                if(average.get(i) < average.get(j)){
                    rank.set(i, rank.get(i)+1);
                }
            }
        }

        return rank.stream().mapToInt(Integer::intValue).toArray();
    }
}
*/

/*
import java.util.*;
class Solution {
    public int[] solution(int[][] score) {
        List<Integer> scoreList = new ArrayList<>();
        for(int[] t : score){
            scoreList.add(t[0] + t[1]);
        }
        scoreList.sort(Comparator.reverseOrder());

        int[] answer = new int[score.length];
        for(int i=0; i<score.length; i++){
            answer[i] = scoreList.indexOf(score[i][0] + score[i][1])+1;
        }
        return answer;
    }
}
*/