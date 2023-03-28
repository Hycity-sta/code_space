import java.util.Scanner;
public class Test {
    public static void main(String[] args) {
        
    }
}

class Student {
    protected String id;
    protected String name;
    static int number = 0;

    Student(String id, String name) {
        this.id = id;
        this.name = name;
        number++;
    }
}
