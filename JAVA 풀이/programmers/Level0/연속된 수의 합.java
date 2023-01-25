import java.util.*;

class Solution {
    public int[] solution(int num, int total) {
        
        int[] result = new int[num];
        Integer middle = total / num;
        Integer start = middle + (1-num)/2; // -(num-1)이며 1을 뺀 것은 홀짝을 구분하기 위함.
        
        for(Integer i=0; i<num; i++){
            result[i] = start+i;
        }

     return result;
    }
}

/*
 List<Integer> resultNumbers = new ArrayList<>();

        if (num % 2 == 1) {
            resultNumbers.add(start);
            for (Integer operand = 1; operand <= num / 2; operand++) {
                resultNumbers.add(start - operand);
                resultNumbers.add(start + operand);
            }
        } else {
            for (Integer operand = 0; operand < num / 2; operand++) {
                resultNumbers.add(start - operand);
                resultNumbers.add(start + operand + 1);
            }
        }

        resultNumbers.sort(Comparator.naturalOrder());
        
        return resultNumbers.stream().mapToInt(Integer::intValue).toArray();
*/
