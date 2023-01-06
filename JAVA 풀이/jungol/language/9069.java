import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    
    public static void main(String[] args) throws IOException {
        //int[] lastDayOfMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
        List<Integer> lastDayOfMonth = new ArrayList<>(Arrays.asList(31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        for (; ; ) {
            System.out.printf("YEAR = ");
            Integer year = Integer.parseInt(bufferedReader.readLine());

            System.out.printf("MONTH = ");
            Integer month = Integer.parseInt(bufferedReader.readLine());

            if (month.equals(0)) {
                return;
            }

            lastDayOfMonth.set(1, 28);
            if ((year % 400 == 0) || (year % 4 == 0 && year != 100)) {
                lastDayOfMonth.set(1, 29);
            }

            try {
                System.out.printf("입력하신 달의 날 수는 %d일입니다.", lastDayOfMonth.get(month-1));
            } catch (Exception e) {
                System.out.print("잘못 입력하였습니다.");
            }

            System.out.printf("\n\n");
        }
    }
}
