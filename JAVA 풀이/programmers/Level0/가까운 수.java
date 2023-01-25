import java.util.Arrays;

class Solution {
    public int solution(int[] array, int n) {
        int nearNumberIndex = 0;

       array = Arrays.stream(array).sorted().toArray();
        
        for (int i = 0; i < array.length; i++) {
            if (Math.abs(array[i] - n) < Math.abs(array[nearNumberIndex] - n))
            {
                nearNumberIndex = i;
            }
        }
        
        return array[nearNumberIndex];
    }
}