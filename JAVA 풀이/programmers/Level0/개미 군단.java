class Solution {
    public int solution(int hp) {
        int answer = 0;
        int[] ants = {5, 3, 1};
        
        for (int i = 0; i < 3; i++) {
            if (hp / ants[i] > 0) {
                answer += hp / ants[i];
                hp %= ants[i];
            }

        }
        
        return answer;
    }
}