import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

        List<Integer> numbers = new ArrayList<>();

        for (; stringTokenizer.hasMoreTokens(); ) {
            numbers.add(Integer.parseInt(stringTokenizer.nextToken()));
        }

        //Integer maxValue = numbers.stream().max(Integer::compareTo).get();
        //Integer maxValue = numbers.stream().reduce(Integer::max).get();
        //Integer maxValue = numbers.stream().reduce(-999, (x, y) -> x > y ? x : y); -999는 필요없다.
        Integer maxValue = numbers.stream().reduce(Main::compareTo).get();

        System.out.println(maxValue);

        return;
    }

    public static Integer compareTo(Integer x, Integer y) {
        if (x > y) {
            return x;
        }
        return y;
        //return x > y ? x : y;
    }
    //https://www.techiedelight.com/ko/java-8-stream-reduce-method-code-examples/
    //https://codechacha.com/ko/java8-stream-reduction/
}
