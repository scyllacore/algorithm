class Solution {
    public int solution(int num, int k) {
        Integer answer = String.valueOf(num).indexOf(String.valueOf(k));
        return answer != -1 ? answer+1 : -1;
    }
}