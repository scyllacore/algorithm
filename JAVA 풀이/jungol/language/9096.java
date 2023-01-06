import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        System.out.printf("원의 반지름 : ");
        Double radius = Double.parseDouble(bufferedReader.readLine());
        Double area = getArea(radius);


        System.out.printf("원의 넓이\n");
        System.out.printf("버림 : %d\n", getRoundDown(area));
        System.out.printf("반올림 : %d\n", getRound(area));
        System.out.printf("올림 : %d", getRoundUp(area));
    }

    public static Double getArea(Double radius) {
        return radius * radius * Math.PI;
    }

    public static Integer getRoundDown(Double area) {
        return area.intValue();
    }

    public static Long getRound(Double area) {
        return Math.round(area);
    }

    public static Integer getRoundUp(Double area) {
        Double tmpArea = Math.ceil(area);
        return tmpArea.intValue();
    }
}
