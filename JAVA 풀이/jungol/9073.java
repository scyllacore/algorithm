import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        List<Integer> numbers = new ArrayList<>(Arrays.asList(50, 75, 85, 95, 100));

        //numbers.sort(Comparator.naturalOrder());
        numbers.sort(Main::compareInt);
        
        numbers.forEach(Main::printNumber);
    }

    public static void printNumber(Integer number) {
        System.out.printf("%d ", number);
    }

    public static Integer compareInt(Integer a, Integer b) {
        return a-b; // 오름차순
        // return b-a; 내림 차순
        // 0과 같은 경우, 0보다 큰 경우 , 0보다 작은 경우로 비교. compareTo 를 따른다.
    }

    //https://codechacha.com/ko/java-sort-list/
    //https://ttl-blog.tistory.com/148
}
