class Solution {
    public String solution(String myString) {
        myString = myString.toLowerCase();
        return myString.replace("a","A");
    }
}

/*
class Solution {
    public String solution(String myString) {
        StringBuffer sb = new StringBuffer(myString);
        
        for(int i=0; i<sb.length(); i++){
            if(sb.charAt(i) == 'A'){
                continue;
            }
            
            if(sb.charAt(i) == 'a'){
                sb.setCharAt(i,'A');
            }
            else if(Character.isUpperCase(sb.charAt(i))){
                sb.setCharAt(i,(char)(sb.charAt(i) + 32));
            }
        }
        
        return sb.toString();
    }
}
*/