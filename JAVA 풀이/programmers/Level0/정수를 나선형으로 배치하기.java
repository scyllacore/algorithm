class Solution {
    
    int[] dy = {0,1,0,-1};
    int[] dx = {1,0,-1,0};
    
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        
        int y=0,x=0;
        int dir=0;
        
        for(int i=1; i<= n*n; i++){
            answer[y][x] = i;
            
            if( y+dy[dir] < 0 || y+dy[dir] >= n || x+dx[dir] < 0 || x+dx[dir] >= n
                || answer[y+dy[dir]][x+dx[dir]] != 0){
                dir = (dir+1)%4;
            }
            
            y+= dy[dir];
            x+= dx[dir]; 
        }
        
        return answer;
    }
}