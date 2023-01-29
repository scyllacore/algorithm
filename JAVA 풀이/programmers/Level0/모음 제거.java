import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public String solution(String my_string) {
        
    return my_string.replaceAll("[aeiuo]","");
        

    }
}

/*
return Arrays.stream(my_string.replaceAll("[aeiuo]","").split("")).collect(Collectors.joining());
*/