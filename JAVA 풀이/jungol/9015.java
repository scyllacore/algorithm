import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Integer a, b;
        System.out.print("두 수를 입력하시오. ");

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(reader.readLine());

        a = Integer.parseInt(stringTokenizer.nextToken());
        b = Integer.parseInt(stringTokenizer.nextToken());

        System.out.println(String.format("%d + %d = %d", a, b, a + b));
        System.out.println(String.format("%d * %d = %d", a, b, a * b));

        return;
    }
    //scanner bufferedreader 차이
}
