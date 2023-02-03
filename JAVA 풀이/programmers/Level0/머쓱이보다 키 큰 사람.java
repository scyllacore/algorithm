import java.util.Arrays;

class Solution {
    public int solution(int[] array, int height) {
         return (int)Arrays.stream(array).filter(other -> other > height).count();
    }
}

/*
List<Integer> reversedArray = Arrays.stream(array).boxed().sorted(Collections.reverseOrder()).collect(Collectors.toList());

       return -1 * Arrays.binarySearch(reversedArray.stream().mapToInt(Integer::intValue).toArray(), height) + 1;
*/