class Solution {
    public int solution(int[] array, int n) {
        int[] numberOf = new int[1000];

        for(int indexValue : array){
            numberOf[indexValue]++;
        }

        return numberOf[n];
    }
}

//return (int) Arrays.stream(array).filter(i -> i == n).count();