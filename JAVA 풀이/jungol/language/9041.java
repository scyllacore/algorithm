import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        for (; ; ) {
            System.out.printf("점수를 입력하세요. ");
            Integer score = Integer.parseInt(bufferedReader.readLine()); // 정상 입력을 받았을 시 버퍼가 비기 때문에 다시 입력을 받음.

            if (score < 0 || score > 100) {
                return;
            } else if (score >= 80) {
                System.out.println("축하합니다. 합격입니다.");
            } else {
                System.out.println("죄송합니다. 불합격입니다.");
            }
        }
    }

}
