class Solution {
    public int solution(int a, int b) {
        int joinNum = Integer.parseInt(""+a+b);
        int abNum = 2*a*b;
        return joinNum >= 2*a*b ? joinNum : abNum;
    }
}