import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        List<Double> numbers = Arrays.stream(bufferedReader.readLine().split(" "))
                .map(Double::parseDouble)
                .collect(Collectors.toList());

        getRoundedNumbers(numbers);

        String RoundedNumbersString = "";

        for (Double number : numbers) {
            RoundedNumbersString += String.format("%.2f", number);
        }

        //System.out.printf(RoundedNumbersString);

        Arrays.stream(RoundedNumbersString.split("\\.")).forEach( // 정규식 패턴에 따라 \\.으로 처리.
                number -> System.out.printf("%s\n", number)
        );
    }

    public static void getRoundedNumbers(List<Double> numbers) {
        for (Integer i = 0; i < numbers.size(); i++) {
            Double roundedNumber = (double) Math.round(numbers.get(i) * 100) / 100;
            numbers.set(i, roundedNumber);
        }
    }
}

