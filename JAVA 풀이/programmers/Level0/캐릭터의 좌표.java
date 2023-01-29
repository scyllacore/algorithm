import java.util.List;
import java.util.Map;

class Solution {
    public int[] solution(String[] keyinput, int[] board) {
        Map<Character, List<Integer>> command = Map.of(
                'l', List.of(-1, 0)
                , 'r', List.of(1, 0)
                , 'd', List.of(0, -1)
                , 'u', List.of(0, 1)
        );

        int[] answer = {0, 0};

        for (String input : keyinput) {
            List<Integer> direction = command.get(input.charAt(0));

            if (Math.abs(answer[0] + direction.get(0)) <= board[0] / 2) {
                answer[0] += direction.get(0);
            }

            if (Math.abs(answer[1] + direction.get(1)) <= board[1] / 2) {
                answer[1] += direction.get(1);
            }
        }
        return answer;
    }
}