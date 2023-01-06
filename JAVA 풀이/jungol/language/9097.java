import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static final Double PI = 3.14;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        Double radius = Double.parseDouble(bufferedReader.readLine());

        /*Double area = 2 * PI * radius * 100;
        Integer area1 = area.intValue();
        Double area2 = area1.doubleValue() / 100;*/

        /*Double area = 2 * PI * radius;
        Integer area1 = (int)(area * 100);
        Double area2 = (double)area1 / 100;*/

        Double area = 2 * PI * radius;
        Double areaRoundedDown = (double)((int)(area * 100))/100;

        System.out.printf("%.2f", areaRoundedDown);
    }
}
