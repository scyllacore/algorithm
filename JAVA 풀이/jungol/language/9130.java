import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Person {
    private final String name;
    private final Integer age;

    public Person(String name, Integer age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public Integer getAge() {
        return age;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        System.out.printf("당신의 이름은 무엇입니까? ");
        String name = bufferedReader.readLine();
        System.out.printf("당신의 나이는 몇 살입니까? ");
        Integer age = Integer.parseInt(bufferedReader.readLine());

        Person person = new Person(name,age);

        System.out.printf("당신의 이름은 %s이고 나이는 %d세이군요.",person.getName(),person.getAge());

    }
}