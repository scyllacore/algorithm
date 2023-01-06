import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Person { // implements Comparator<Person> {
    private final String name;
    private final Integer height;
    private final Double weight;

    public Person(String name, Integer height, Double weight) {
        this.name = name;
        this.height = height;
        this.weight = weight;
    }

    public String getName() {
        return name;
    }

    public Integer getHeight() {
        return height;
    }

    public Double getWeight() {
        return weight;
    }

   /* @Override
    public int compare(Person p1, Person p2) {
        return p1.getHeight() - p2.getHeight();
    } 정렬 기준을 바꿔야할 때가 있기에 클래스 내부에 정렬 기준을 만들어두는 것은 그닥 좋지 않은 듯하다.*/
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String input;
        StringTokenizer stringTokenizer;

        List<Person> persons = new ArrayList<>();

        for (Integer loop = 0; loop < 5; loop++) {
            input = bufferedReader.readLine();
            stringTokenizer = new StringTokenizer(input);

            String name = stringTokenizer.nextToken();
            Integer weight = Integer.parseInt(stringTokenizer.nextToken());
            Double height = Double.parseDouble(stringTokenizer.nextToken());

            persons.add(new Person(name, weight, height));
        }

        Collections.sort(persons, new Comparator<Person>() {
            @Override
            public int compare(Person p1, Person p2) {
                return p1.getHeight() - p2.getHeight(); // 결과가 양수가 나왔을 때 swap이 일어나는 것 같음.
            }
        });

        persons.forEach(person ->
                System.out.printf("%s %d %.1f\n", person.getName(), person.getHeight(), person.getWeight())
        );

    }
    //https://velog.io/@juxn183/How-to-sort-in-Java-%EC%9E%90%EB%B0%94-%EC%A0%95%EB%A0%AC%EB%B0%A9%EB%B2%95-Collections.sort
    //https://st-lab.tistory.com/243
}