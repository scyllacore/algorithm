import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class Main {

    public static final Pattern upperPattern = Pattern.compile("^[A-Z]$");
    public static final Pattern lowerPattern = Pattern.compile("^[a-z]$");

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer stringBuffer = new StringBuffer(bufferedReader.readLine());

        for (int i = 0; i < stringBuffer.length(); i++) {
            stringBuffer.setCharAt(i, convertCharacter(stringBuffer.substring(i, i + 1)).charAt(0));
        }

        System.out.printf(stringBuffer.toString());
    }

    public static String convertCharacter(String character) {
        if (upperPattern.matcher(character).matches()) {
            return character.toLowerCase();
        }
        if (lowerPattern.matcher(character).matches()) {
            return character.toUpperCase();
        }
        return character;
    }
}

