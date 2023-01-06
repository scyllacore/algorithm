import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        System.out.printf("단어 5개를 입력하세요.\n");
        List<String> words = new ArrayList<>();

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        for (Integer loop = 0; loop < 5; loop++) {
            String stringInput = bufferedReader.readLine();
            words.add(stringInput);
        }

        //words.sort(Comparator.naturalOrder());
        words.sort(Main::compareWord);

        for (String word : words) {
            System.out.printf("%s\n", word);
        }
    }

    public static Integer compareWord(String s1, String s2) {
        return s1.compareTo(s2); // 오름차순
        //return s2.compareTo(s1); 내림 차순
    }

}

