import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        Queue<Integer> q = new LinkedList<>();

        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        System.out.println(Arrays.asList(q.toArray()));
        System.out.println(q.toString());

        String stringTest = "";

        for(Integer number : q){
            stringTest += number.toString();
        }

        System.out.println(stringTest);

        q.remove();
        q.remove();
        System.out.println(Arrays.asList(q.toArray()));
    }
}

