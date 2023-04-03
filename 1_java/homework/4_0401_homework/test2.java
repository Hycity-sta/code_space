public class test2 {
    public static void main(String[] args) {
        Company meidi = new Company("meidi"); //美的公司
        Company geli = new Company("geli"); //格力公司

        Person my = new Person("my",11,true);
        Person you = new Person("my",11,true);
        System.out.println(my.equals(you)); //判断两个人是不是同一个人

        Employee lihua = new Employee("lihua",12,true,2000.0,meidi);
        Employee hua = new Employee("lihua",12,true,20.0,meidi);
        Employee yunlong = new Employee("yunlong",24,true,200.0,geli);
        System.out.println(lihua.equals(hua)); //判断两个职员是不是同一个人
        System.out.println(lihua.isSameCampany(hua)); //判断两人是不是一个公司的
        System.out.println(lihua.isSameCampany(yunlong)); //判断两个是不是一个公司的

        Student midi = new Student("midi",12,true,"No.123","class 2");
        Student mi = new Student("midi",12,true,"No.123","class 2");
        System.out.println(midi.equals(mi));//判断两个学生是不是同一个人

        System.out.println("");
        System.out.println(my.toString());
        System.out.println(lihua.toString());
        System.out.println(yunlong.toString());
        System.out.println(meidi.toString());
        System.out.println(midi.toString());
    }
}

class Person {
    String name;
    int age;
    boolean gender; //性别,ture为男

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
        if (obj == null) {
            return false;
        }
        if (this.age == obj.age) {
            if (this.name.equals(obj.name)) {
                if (this.gender == obj.gender) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
}

class Student extends Person {
    String stuNo;
    String clazz;

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
        if (obj == null) {
            return false;
        }
        boolean bbb = super.equals(obj);
        if (bbb == true) {
            if(this.stuNo.equals(obj.stuNo)) {
                if (this.clazz.equals(obj.clazz)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
}

class Company {
    String name;

    public Company(String name) {
        this.name = name;
    }

    public String toString() {
        return this.name;   
    }

    public boolean equals(Company obj) {
        if (obj == null) {
            return false;
        }
        if (this.name.equals(obj.name)) {
            return true;
        }
        else {
            return false;
        }
    }
}

class Employee extends Person {
    Company company;
    double salary;

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
        if (obj == null) {
            return false;
        }
        boolean bbb = super.equals(obj);
        if (bbb == true) {
            if (this.company.equals(obj.company)) {
                if (this.salary == obj.salary) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    public boolean isSameCampany(Employee obj) {
        if (obj == null) {
            return false;
        }
        if (this.company.equals(obj.company)) {
            return true;
        }
        else {
            return false;
        }
    }
}

