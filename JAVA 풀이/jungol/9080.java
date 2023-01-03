import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static final Integer SIZE = 5;

    public static void main(String[] args) throws IOException {

        /* List<List<Integer>> pascalArray = new ArrayList<>(
                Collections.nCopies(SIZE, new ArrayList<>(Collections.nCopies(SIZE+1, 0)))
       );*/

        /*List<List<Integer>> pascalArray = new ArrayList<>(
                Collections.nCopies(SIZE, initialize())
        );*/

        //pascalArray.forEach(Main::initialize);
        // pascalArray.forEach(integerList -> integerList = new ArrayList<>(Collections.nCopies(SIZE + 1, 0)));


        List<List<Integer>> pascalArray = new ArrayList<>(
                Collections.nCopies(SIZE, null)
        );

        for (int i = 0; i < SIZE; i++) {
            pascalArray.set(i, new ArrayList<>(Collections.nCopies(SIZE + 1, 0)));
        }


        pascalArray.get(0).set(1, 1);

       /* for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE + 1; j++) {
                System.out.printf("%d ", pascalArray.get(i).get(j));
            }
            System.out.println();
        }*/


        for (int i = 1; i < SIZE; i++) {
            for (int j = 1; j <= i + 1; j++) {
                Integer diagonal = pascalArray.get(i - 1).get(j - 1);
                Integer up = pascalArray.get(i - 1).get(j);

                pascalArray.get(i).set(j, diagonal + up);
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 1; j <= i + 1; j++) {
                System.out.printf("%d ", pascalArray.get(i).get(j));
            }
            System.out.println();
        }
    }

    public static void initialize(List<Integer> integerList) {
        integerList = new ArrayList<>(Collections.nCopies(SIZE + 1, 0));
    }

    /*public static List<Integer> initialize() {
        return new ArrayList<>(Collections.nCopies(SIZE + 1, 0));
    }*/
}
