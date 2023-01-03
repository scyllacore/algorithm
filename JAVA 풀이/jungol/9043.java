import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        Integer summation = 0;
        Integer count = 0;

        for (; ; ) {
            Integer number = Integer.parseInt(stringTokenizer.nextToken());

            if (number.equals(0)) {
                break;
            }

            if (number % 2 == 1) {
                summation += number;
                count++;
            }
        }

        Integer average = summation / count;

        System.out.printf("홀수의 합 = %d\n", summation);
        System.out.printf("홀수의 평균 = %d", average);
    }

}
