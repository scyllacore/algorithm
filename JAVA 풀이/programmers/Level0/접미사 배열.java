import java.util.stream.IntStream;

class Solution {
    public String[] solution(String my_string) {
        return IntStream.range(0,my_string.length())
            .mapToObj(i -> my_string.substring(i)) // map으로 할 수 없음 convert 불가 할때 obj형으로 바꾸도록 할 것. String cannot be converted to int. mapToObj 분석할 것.
            .sorted((s1,s2) -> s1.compareTo(s2))
            .toArray(String[]::new);
    }
}

/*
class Solution {
    public String[] solution(String my_string) {
        Set<String> strSet = new HashSet<>();
        
        
        for(int i=0; i<my_string.length(); i++){
            strSet.add(my_string.substring(i));
        }
        
        return strSet.stream()
            .sorted((s1,s2) -> s1.compareTo(s2))
            .toArray(String[]::new);
    }
}
*/


/*
Set<String> strSet = new HashSet<>();
        
        int len = my_string.length();
        
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                strSet.add(my_string.substring(j));
            }
        }
        
        return strSet.stream()
            .sorted((s1,s2) -> s1.compareTo(s2))
            .toArray(String[]::new);
                
*/

