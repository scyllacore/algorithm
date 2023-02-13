class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];

        for(int i=0; i< quiz.length; i++){

            String[] symbol = quiz[i].split(" ");

            int result = Integer.parseInt(symbol[0]) + Integer.parseInt(symbol[2]) * (symbol[1].equals("+") ? 1 : -1);

            answer[i] = (result == Integer.parseInt(symbol[4]) ? "O" : "X");
        }
        
        return answer;
    }
}