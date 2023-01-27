import java.util.ArrayList;
import java.util.List;

class Solution {
    public int solution(int n) {
        List<Integer> village3X = new ArrayList<>();

        village3X.add(0);

        for(int i=1; village3X.size()<=100; i++){
            if(!String.format("%s",i).contains("3") && i%3 != 0){
                village3X.add(i);
            }
        }

        return village3X.get(n);
    }
}