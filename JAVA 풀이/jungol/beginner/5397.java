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
        Integer number = 0;

        Integer y = 0, x = size;


        for (; countOfInsert > 0; ) {
            //left
            for (Integer loop = 0; loop < countOfInsert; loop++) {
                x--;
                number++;
                numberSqaure.get(y).set(x, number);
            }
            countOfInsert--;

            //up
            for (Integer loop = 0; loop < countOfInsert; loop++) {
                y++;
                number++;
                numberSqaure.get(y).set(x, number);
            }

            //right
            for (Integer loop = 0; loop < countOfInsert; loop++) {
                x++;
                number++;
                numberSqaure.get(y).set(x, number);
            }
            countOfInsert--;

            //down
            for (Integer loop = 0; loop < countOfInsert; loop++) {
                y--;
                number++;
                numberSqaure.get(y).set(x, number);
            }
        }

        for (Integer i = 0; i < size; i++) {
            for (Integer j = 0; j < size; j++) {
                System.out.printf("%d ", numberSqaure.get(i).get(j));
            }
            System.out.printf("\n");
        }
    }
}