import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String stringInput = bufferedReader.readLine();

        System.out.printf("입력받은 문자열의 길이는 %d입니다.\n",stringInput.length());

        StringBuffer reversedString = new StringBuffer(stringInput);
        System.out.printf("%s",reversedString.reverse().toString());
    }

}
