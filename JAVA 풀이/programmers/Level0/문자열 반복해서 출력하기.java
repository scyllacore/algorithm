import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        
        StringBuffer sb = new StringBuffer(a);
        
        for(int i=0; i<sb.length(); i++){
            char ch =sb.charAt(i);
            
            if(Character.isUpperCase(ch)){
                System.out.print(Character.toLowerCase(ch));
            }else{
                System.out.print(Character.toUpperCase(ch));
            }
        }
        
    }
}