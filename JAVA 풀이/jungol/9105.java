import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static List<Integer> diceNumbers = new ArrayList<>();
    public static Integer numberOfThrows;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        numberOfThrows = Integer.parseInt(bufferedReader.readLine());

        getRecursiveDiceNumber();
    }

    public static void getRecursiveDiceNumber() {
        if (diceNumbers.size() == numberOfThrows) {
            printDiceNumbers();
            return;
        }

        for (int i = 1; i <= 6; i++) {
            diceNumbers.add(i);
            getRecursiveDiceNumber();
            diceNumbers.remove(diceNumbers.size() - 1);
        }
    }

    public static void printDiceNumbers() {
        diceNumbers.forEach(number -> System.out.printf("%d ", number));
        System.out.printf("\n");
    }
}
