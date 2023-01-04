import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static final List<String> words = new ArrayList<>(Arrays.asList(
            "champion", "tel", "pencil", "jungol", "olympiad", "class", "information", "lesson", "book", "lion"
    ));

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        System.out.printf("문자를 입력하세요. ");
        printWords(findWords(bufferedReader.readLine()));

        System.out.printf("문자열을 입력하세요. ");
        printWords(findWords(bufferedReader.readLine()));
    }

    public static void printWords(List<String> foundWords) {
        if (foundWords.size() == 0) {
            System.out.printf("찾는 단어가 없습니다.\n\n");
            return;
        }

        for (String word : foundWords) {
            System.out.printf("%s\n", word);
        }
        System.out.printf("\n");
    }

    public static List<String> findWords(String stringInput) {
        List<String> foundWords = new ArrayList<>();

        for (String word : words) {
            if (word.contains(stringInput)) {
                foundWords.add(word);
            }
        }

        return foundWords;
    }
}

