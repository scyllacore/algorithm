import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static final Integer size = 10;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        List<Integer> units = new ArrayList<>(Collections.nCopies(size, 0));

        for (; ; ) {
            Integer number = Integer.parseInt(stringTokenizer.nextToken());

            if (number.equals(0)) {
                break;
            }

            Integer placeValue = number % 10;
            units.set(placeValue, units.get(placeValue) + 1);
        };

        for(int i=0; i<size; i++){
            Integer count = units.get(i);

            if(count !=0){
                System.out.printf("%d : %d개\n",i,count);
            }
        }
    }

}
