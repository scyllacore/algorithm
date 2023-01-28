class Solution {
    int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    public int solution(int[][] board) {
         int n = board.length;

        int[][] answerBoard = new int[n][n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                answerBoard[i][j] = board[i][j];
            }
        }
        
        
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (board[y][x] == 1) {
                    for (int k = 0; k < 8; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                            answerBoard[ny][nx] = 1;
                        }
                    }
                }
            }
        }

        int answer = 0;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (answerBoard[y][x] == 0) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
}