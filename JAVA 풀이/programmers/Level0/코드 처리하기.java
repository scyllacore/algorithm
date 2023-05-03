class Solution {
    public String solution(String code) {
        StringBuffer ret = new StringBuffer();
        int mode = 0;
        
        for(int i=0; i<code.length(); i++){
            char ch = code.charAt(i);
            
            if(ch == '1'){
               mode = 1-mode;
            }   
            else if(mode == 0 && i%2 == 0 
               || mode == 1 && i%2 ==1){
                ret.append(ch);
            }            
        }
        
        return ret.length() == 0 ? "EMPTY" : ret.toString();
    }
}

/*
class Solution {
    public String solution(String code) {
        StringBuffer ret = new StringBuffer();
        int mode = 0;
        
        for(int i=0; i<code.length(); i++){
            char ch = code.charAt(i);
            
            if(ch != '1' &&
                (mode == 0 && i%2 == 0 //mode앞에서 괄호로 ||를 묶어줘야한다.
               || mode == 1 && i%2 ==1)){ 
                ret.append(ch);
            }else if(ch == '1'){
               mode = 1-mode;
            }               
        }
        
        return ret.length() == 0 ? "EMPTY" : ret.toString();
    }
}
*/