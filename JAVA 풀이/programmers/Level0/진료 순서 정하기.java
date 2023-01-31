import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] solution(int[] emergency) {
        List<Integer> priority = new ArrayList<>(Collections.nCopies(emergency.length, 1));

        int size = priority.size();

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(emergency[i] < emergency[j]){
                    priority.set(i, priority.get(i)+1);
                }
            }
        }
        
       return priority.stream().mapToInt(Integer::intValue).toArray();
//return Arrays.stream(e).map(i -> Arrays.stream(e).boxed().sorted(Comparator.reverseOrder()).collect(Collectors.toList()).indexOf(i) + 1).toArray();
    }
}