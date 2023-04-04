import java.text.DecimalFormat;

public class test2 {
    public static void main(String[] args) {
        Company meidi = new Company("meidi"); //美的公司
        Company geli = new Company("geli"); //格力公司

        Employee em1 = new Employee("lihua",12,true,2000.4,meidi);
        Employee em2 = new Employee("lihua",12,true,2000.4,meidi);
        System.out.println(em1.equals(em2)); //判断两个职员是不是同一个人
        System.out.println(em1.isSameCampany(em2)); //判断两个职员是不是同一个人
        Employee em = new Employee();
        System.out.println(em.company.name);
        Student st1 = new Student("zhangsan",12,true,"No.123","class 2");
        Student st2 = new Student("wanwu",12,true,"No.123","class 1");
        st1.Hello(st2);
    }
}

class Person {
    protected String name;
    protected int age;
    protected boolean gender; //性别,true为男

    public Person() {
        this.name = "未知的名字";
        this.age = 0;
        this.gender = true;
    }
    public Person(String name, int age, boolean gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
    public String toString() {
        String str = String.format("%s-%d-%b",this.name,this.age,this.gender); //格式化字符串
        return str;
    }
    public boolean equals(Person obj) {
        if (obj == null)
            return false;
        if (this.age == obj.age && this.name.equals(obj.name) && this.gender == obj.gender)
            return true;
        else
            return false;
    }
}

class Student extends Person {
    protected String stuNo;
    protected String clazz;

    public Student() {
        super();
        this.stuNo = "未知的学号";
        this.clazz = "未知的班级";
    }

    public Student(String name, int age, boolean gender, String stuNo, String clazz) {
        super(name, age, gender);
        this.stuNo = stuNo;
        this.clazz = clazz;
    }

    public String toString() {
        String str = super.toString();
        String str2 = String.format("-%s-%s",this.stuNo,this.clazz);//格式化字符串
        return str+str2;
    }

    public boolean equals(Student obj) {
        if (obj == null)
            return false;
        boolean bbb = super.equals(obj);
        if (bbb && this.stuNo.equals(obj.stuNo) && this.clazz.equals(obj.clazz))
            return true;
        else
            return false;
    }

    public boolean isSameClass(Student obj) {
        if (this.clazz.equals(obj.clazz))
            return true;
        else
            return false;
    }

    public void Hello(Student obj) {
        if (this.isSameClass(obj))
            System.out.println("hello, "+obj.name+", 我们的同班同学");
        else
            System.out.println("hello, "+obj.name);
    }
}

class Company {
    protected String name;

    public Company() {
        this.name = "未知公司名";
    }

    public Company(String name) {
        this.name = name;
    }

    public String toString() {
        return this.name;   
    }

    public boolean equals(Company obj) {
        if (obj == null)
            return false;
        if (this.name.equals(obj.name))
            return true;
        else
            return false;
    }
}

class Employee extends Person {
    protected Company company = new Company(); //在类里面创建一个对象,这样子可以指定初值
    protected double salary;

    public Employee() {
        super();
        this.salary = 0;
    }

    public Employee(String name, int age, boolean gender, double salary, Company company) {
        super(name, age, gender);
        this.salary = salary;
        this.company = company;
    }

    public String toString() {
        String str = super.toString();
        String str2 = String.format("-%s-%s",this.company.name,this.salary);//格式化字符串
        return str+str2;
    }

    public boolean equals(Employee obj) {
        if (obj == null)
            return false;
        boolean bbb = super.equals(obj);
        DecimalFormat myFormat = new DecimalFormat("#.#");
        String str1 = myFormat.format(this.salary);
        String str2 = myFormat.format(obj.salary);
        if (bbb && this.company.equals(obj.company) && str1.equals(str2))
            return true;
        else
            return false;
    }

    public boolean isSameCampany(Employee obj) {
        if (obj == null)
            return false;
        if (this.company.equals(obj.company))
            return true;
        else
            return false;
    }
}

/** 
 * 类的继承,多态,封装总结
 * 继承, 子类可以继承父类的所有属性和方法
 * 多态, 同一类中的方法可以进行重载, 同一继承树中的方法可以进行重写
 * 封装, 通过访问限制修饰符还有非访问限制修饰符的使用,可以限定类中的属性和方法的访问权限,提高安全性
 **/
