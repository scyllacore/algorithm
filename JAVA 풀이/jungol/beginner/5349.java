import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String input = bufferedReader.readLine();

        List<String> words = Arrays.stream(input.split(" "))
                .collect(Collectors.toList());

        Integer wordsStart = words.size() % 2 == 0 ? words.size() - 1 : words.size() - 2;

        for (Integer i = wordsStart; i >= 0; i -= 2) {
            System.out.printf("%s ", words.get(i));
        }
    }
}