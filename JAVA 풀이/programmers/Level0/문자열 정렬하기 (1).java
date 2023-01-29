import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Solution {
    public int[] solution(String my_string) {
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < my_string.length(); i++) {
            Character ch = my_string.charAt(i);

            if (Character.isDigit(ch)) {
                answer.add(Integer.parseInt(ch.toString()));
            }
            
        }

        answer.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer n1, Integer n2) {
                return n1 - n2;
            }
        });

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}

/*
import java.util.*;

class Solution {
    public int[] solution(String myString) {
        return Arrays.stream(myString.replaceAll("[A-Z|a-z]", "").split("")).sorted().mapToInt(Integer::parseInt).toArray();
    }
}
*/