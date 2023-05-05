import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        
        Arrays.stream(a.split("")).forEach(ch -> System.out.println(ch));
        // a.toCharArray();
    }
}