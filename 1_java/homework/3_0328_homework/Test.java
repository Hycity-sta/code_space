//继承与多态
public class Test {
    public static void main(String[] args) {
        Teacher th1 = new Teacher("miss li",30);
        Gra_Student st1 = new Gra_Student("111","li hua", th1.name);
        Gra_Student st2 = new Gra_Student("112","wu xian", th1.name);
        st1.print_info();
        st1.print_teacher();
        st2.print_info();
        st2.print_teacher();
    }
}

class Student {
    protected String id;
    protected String name;
    static int number = 0;

    Student(){
        this.id = null;
        this.name = null;
    }

    Student(String id, String name) {
        this.id = id;
        this.name = name;
        number++;
    }
    void print_info() {
        System.out.println("id is " + this.id);
        System.out.println("name is " + this.name);
        System.out.println("now have "+Student.number+"students");
    }
}

class Gra_Student extends Student {
    String teacher;
    Gra_Student(String id, String name, String teachername) {
        super(id,name);
        this.teacher = name;
    }
    void print_info() {
        super.print_info();
        System.out.println(super.name+"'s teacher is "+this.teacher);
    }
    void print_teacher() {
        System.out.println("\n"+this.name+"'s teacher is "+this.teacher);
    }
}

class Teacher {
    String name;
    int age;
    Teacher(String name, int age) {
        this.name = name;
        this.age = age;
    }
    void print_info() {
        System.out.println(this.name);
        System.out.println(this.age);
    }
}
