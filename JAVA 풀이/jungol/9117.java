import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String stringInput = bufferedReader.readLine();

        //  StringBuffer stringBuffer = new StringBuffer(stringInput);
        //  System.out.printf("%s\n",stringBuffer.append(stringBuffer.charAt(0)).substring(1));

        for (int loop = 0; loop < stringInput.length(); loop++) {
            stringInput += stringInput.substring(0,1);
            stringInput = stringInput.substring(1);
            System.out.printf("%s\n", stringInput);
        }
    }
}

