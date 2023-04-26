class Solution {
    public int[] solution(int[] arr, int n) {
        int start = 1 - arr.length%2;
        
        for(int i= start; i<arr.length; i+=2){
            arr[i] += n;
        }
        
        return arr;
    }
}