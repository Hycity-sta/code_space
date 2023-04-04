//学习通作业 继承与多态还有封装
//本目录下还有一个文件也是这个题目

import java.util.Scanner; 

public class test {
    public static void main(String[] args) {
        Scanner user_input = new Scanner(System.in);

        Manager lihua = new Manager("lihua",1234);
        Salesman wudong = new Salesman("wudong",3456);
        Worker xiaohua = new Worker("xiaohua",5555);
        
        System.out.println(lihua.ToString());
        System.out.println(wudong.ToString());
        System.out.println(xiaohua.ToString());
    }
}

class Employee {
    protected int id;
    protected String name;
    final String post = "Employee";
    final int salary = 0;

    public Employee(){
        this.id = 0;
        this.name = "未知的名字";
    }

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public int getSalary() {
        return this.salary;
    }

    public String ToString() {
        String str = String.format("职位:%s , 名字:%s, 工资:%d\n",this.post,this.name,this.salary);
        return str;
    }
}

class Manager extends Employee{
    final int salary = 5000; //固定工资
    final String post = "Manager";

    public Manager() {
        super();
    }

    public Manager(String name, int id) {
        super(name,id);
    }

    public int getSalary() {
        return this.salary;
    }
    
    public String ToString() {
        String str = String.format("职位:%s , 名字:%s, 工资:%d\n",this.post,this.name,this.salary);
        return str;
    }
}

class Salesman extends Employee{
    Scanner input = new Scanner(System.in);
    final String post = "Salesman";
    final int salary = 3000;

    public Salesman() {
        super();
    }

    public Salesman(String name, int id) {
        super(name,id);
    }
    
    public int getSalary() {
        System.out.println("输入"+this.name+"的销售量: ");
        int n = input.nextInt();
        int salary = this.salary+5*n; //根据销售量来进行提成 这里假设在固定工资的基础上加5/件
        return salary;
    }
    
    public String ToString() {
        String str = String.format("职位:%s , 名字:%s, 工资:%d\n",this.post,this.name,this.getSalary());
        return str;
    }
}

class Worker extends Employee{
    Scanner input = new Scanner(System.in);
    final String post = "Worker";
    final int salary = 200;

    public Worker() {
        super();
    }

    public Worker(String name, int id) {
        super(name,id);
    }
    
    public int getSalary() {
        System.out.println("输入"+this.name+"的工作天数: ");
        int n = input.nextInt();
        int salary = this.salary * n; //根据工作天数来进行发工资
        return salary;
    }
    
    public String ToString() {
        String str = String.format("职位:%s , 名字:%s, 工资:%d\n",this.post,this.name,this.getSalary());
        return str;
    }
}
