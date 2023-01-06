import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String stringInput = bufferedReader.readLine();

        //List<String> words = Arrays.stream(stringInput.split(" ")).toList(); jdk 17이상.
        List<String> words = Arrays.stream(stringInput.split(" ")).collect(Collectors.toList());

        for (String word : words) {
            System.out.printf("%s\n", word);
        }
    }
}

