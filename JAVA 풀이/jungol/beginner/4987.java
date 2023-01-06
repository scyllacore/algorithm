import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String stringS = bufferedReader.readLine();
        String stringT = bufferedReader.readLine();

        Integer tLength = stringT.length();
        Integer indexT;


        //System.out.printf("%d\n",stringS.indexOf(stringT));

        for (; ; ) {
            indexT = stringS.indexOf(stringT);

            if (indexT == -1) {
                break;
            }

            stringS = stringS.substring(0, indexT) + stringS.substring(indexT + tLength);
            //System.out.printf("%s\n",stringS);
        }

        System.out.printf("%s", stringS);
    }
}