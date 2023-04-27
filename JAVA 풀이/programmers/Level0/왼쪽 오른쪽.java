import java.util.*;

class Solution {
    public String[] solution(String[] str_list) { 
        for(int i=0; i<str_list.length; i++){
            if(str_list[i].equals("l")){
                return Arrays.copyOfRange(str_list,0,i);
            }
            else if(str_list[i].equals("r")){
                return Arrays.copyOfRange(str_list,i+1,str_list.length); 
            }
        }
        
        return new String[]{};
    }
}

/*
import java.util.*;

class Solution {
    public String[] solution(String[] str_list) {
        String answer;
        
        int idx;
        
        for(idx=0; idx<str_list.length; idx++){
            if(str_list[idx].equals("l") || str_list[idx].equals("r")){
                break;
            }
        }
        
        if(idx == str_list.length){
            return new String[]{};
        }
        
        if(str_list[idx].equals("l")){
            return Arrays.copyOfRange(str_list,0,idx);
        }
        
        return Arrays.copyOfRange(str_list,idx+1,str_list.length); 
    }
}
*/