class Solution {
    public String solution(String my_string, String alp) {
        return my_string.replace(alp ,alp.toUpperCase());
    }
}

//return my_string.replace(alp,String.format("%c",alp.charAt(0)-32));