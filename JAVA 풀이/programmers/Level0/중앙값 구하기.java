import java.util.Arrays;
//import java.util.stream.Collectors;

class Solution {
    public int solution(int[] array) {
        return Arrays.stream(array).sorted().toArray()[array.length/2];
    }
}

//Arrays.stream(array).sorted().boxed().collect(Collectors.toList()).get(array.length/2);