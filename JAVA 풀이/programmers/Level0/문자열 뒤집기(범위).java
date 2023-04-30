class Solution {
    public String solution(String my_string, int s, int e) {
        StringBuffer sb = new StringBuffer(my_string.substring(s,e+1))
            .reverse();
        
        return my_string.substring(0 , s) 
            + sb.toString() // sb.substring(s , e + 1) 전체를 먼저 바꾸면 사용해야할 인덱스도 같이 변해서 부분을 떼어내고 reverse 처리. 
            + my_string.substring(e + 1);
    }
}