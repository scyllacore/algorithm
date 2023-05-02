class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        for(int[] query : queries){
            
            int start = query[0]%query[2] != 0 ? query[0] - (query[0]%query[2]) + query[2] : query[0];
            
            for(int i=start; i<=query[1]; i+=query[2]){
                    arr[i]++;
            }
        }
        
        return arr;
    }
}

/*
class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        for(int[] query : queries){
            for(int i=query[0]; i<=query[1]; i++){
                if(i%query[2] == 0){
                    arr[i]++;
                }
            }
        }
        
        return arr;
    }
}
*/