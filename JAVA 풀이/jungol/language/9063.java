import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static final Integer size = 5;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        List<Integer> integerArray = new ArrayList<>(Collections.nCopies(size, 0));
        for (int i = 0; i < size; i++) {
            //integerArray.add(Integer.parseInt(stringTokenizer.nextToken()));
            integerArray.set(i,Integer.parseInt(stringTokenizer.nextToken()));
        }

        integerArray.forEach(Main::printNumber);

        return;
    }

    public static void printNumber(Integer number){
        System.out.printf("%d ",number);
    }
}
