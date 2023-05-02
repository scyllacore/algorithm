class Solution {
    public static final int INF = (int)1e7;
    
    public int[] solution(int[] arr, int[][] queries) {
        int[] answer = new int[queries.length];
        
        for(int i=0; i<queries.length; i++){
            int minVal = INF;
            
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                if(arr[j] > queries[i][2]){
                    minVal = Math.min(arr[j],minVal);
                }
            }
            
            if(minVal == INF){
                answer[i] = -1;
            }else{
                answer[i] = minVal;
            }
            
        }
        
        return answer;
    }
}