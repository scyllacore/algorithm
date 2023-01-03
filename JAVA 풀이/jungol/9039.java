import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        Character alphabet = 'A';
    
           /* for (Integer i = 0; i < 26; i++) {
                System.out.printf("%c", alphabet + i);
            }*/

        for (Integer asciiIndex = 65; asciiIndex <= 90; asciiIndex++) {
            System.out.printf("%c", asciiIndex);
        }

    }
    //https://charliecharlie.tistory.com/319
}
