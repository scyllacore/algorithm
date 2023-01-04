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

        List<String> words = Arrays.stream(stringInput.split(" ")).collect(Collectors.toList());

        System.out.printf("%s\n",words.get(1).substring(0, 3) + words.get(0).substring(3));
        System.out.printf("%s",words.get(1) + words.get(0).substring(0, 3));
    }
}

