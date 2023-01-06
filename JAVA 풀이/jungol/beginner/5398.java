import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        Integer size = Integer.parseInt(bufferedReader.readLine());

        List<List<Integer>> numberSqaure = new ArrayList<>();
        for (Integer loop = 0; loop < size; loop++) {
            numberSqaure.add(new ArrayList<>(Collections.nCopies(size, 0)));
        }

        Integer countOfInsert = size;
        Integer number = -1;

        Integer y = -1, x = 0;


        for (; countOfInsert > 0; ) {
            //up
            for (Integer loop = 0; loop < countOfInsert; loop++) {
                y++;
                number++;
                numberSqaure.get(y).set(x, number);
            }
            countOfInsert--;

            //right
            for (Integer loop = 0; loop < countOfInsert; loop++) {
                x++;
                number++;
                numberSqaure.get(y).set(x, number);
            }
            countOfInsert--;

            //left-down
            for (Integer loop = 0; loop < countOfInsert; loop++) {
                y--;
                x--;
                number++;
                numberSqaure.get(y).set(x, number);
            }
            countOfInsert--;
        }

        for (Integer i = 0; i < size; i++) {

            System.out.printf("%s", " ".repeat(size - i - 1));

            for (Integer j = 0; j <= i; j++) {
                System.out.printf("%d ", numberSqaure.get(i).get(j) % 10);
            }
            System.out.printf("\n");
        }
    }
}