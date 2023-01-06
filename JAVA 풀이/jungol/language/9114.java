import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

public class Main {
    public static final Pattern numberPattern = Pattern.compile("^[0-9]$");
    public static final Pattern upperPattern = Pattern.compile("^[A-Z]$");
    public static final Pattern lowerPattern = Pattern.compile("^[a-z]$");

    /*public static final Set<String> outputMessage = new HashSet<>(Set.of(
            "숫자문자",
            "대문자",
            "소문자"
    ));*/

    public static final List<String> outputMessage = new ArrayList<>(List.of(
            "숫자문자",
            "대문자",
            "소문자"
    ));

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String character;

        for (; ; ) {
            character = bufferedReader.readLine();

            Integer resultNumber = confirmCharacter(character);

            if (resultNumber == -1) {
                System.out.printf("영문, 숫자 이외의 문자입니다.");
                return;
            }
            System.out.printf("%s입니다.\n", outputMessage.get(resultNumber));
        }
    }

    public static Integer confirmCharacter(String character) {
        if (numberPattern.matcher(character).matches()) {
            return 0;
        }
        if (upperPattern.matcher(character).matches()) {
            return 1;
        }
        if (lowerPattern.matcher(character).matches()) {
            return 2;
        }
        return -1;
    }
}

/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class Main {
    public static final Pattern numberPattern = Pattern.compile("^[0-9]$");
    public static final Pattern upperPattern = Pattern.compile("^[A-Z]$");
    public static final Pattern lowerPattern = Pattern.compile("^[a-z]$");

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String character;

        for (; ; ) {
            character = bufferedReader.readLine();

            if (numberPattern.matcher(character).matches()) {
                System.out.printf("숫자문자입니다.\n");
            } else if (upperPattern.matcher(character).matches()) {
                System.out.printf("대문자입니다.\n");
            } else if (lowerPattern.matcher(character).matches()) {
                System.out.printf("소문자입니다.\n");
            } else {
                System.out.printf("영문, 숫자 이외의 문자입니다.\n");
                return;
            }
        }
    }
}
* */
