//学习通作业 继承与多态还有封装
//本目录下还有一个文件也是这个题目

import java.util.Scanner; 

public class test {
    public static void main(String[] args) {
        Scanner user_input = new Scanner(System.in);

        Manager lihua = new Manager("lihua",1234);
        Salesman wudong = new Salesman("wudong",3456);
        Worker xiaohua = new Worker("xiaohua",5555);

        lihua.getSalary();
        wudong.getSalary(10);
        xiaohua.getSalary(24);

        lihua.ToString();
        wudong.ToString();
        xiaohua.ToString();
    }
}

class Employee {
    int id;
    String name;
    int salary;
    Employee(){}
    void getSalary() {
        this.salary = 0;
    }
    void getSalary(int cost) {
        this.salary = cost;
    }
    void ToString() {
        System.out.println(this.salary);
    }
}

class Manager extends Employee{
    Manager(String name, int id) {
        this.name = name;
        this.id = id;
    }
    void getSalary() {
        super.getSalary(5000); //默认
    }
    void getSalary(int cost) {
        this.salary = cost; //可以输入参数来指定固定的工资
    }
    void ToString() {
        System.out.printf("Manager %s的工资是: %d\n",this.name,this.salary);
    }
}

class Salesman extends Employee{
    Salesman(String name, int id) {
        this.name = name;
        this.id = id;
    }
    void getSalary(int n) {
        this.salary = 3000+5*n; //根据销售量来进行提成
    }
    void ToString() {
        System.out.printf("Salesman %s的工资是: %d\n",this.name,this.salary);
    }
}

class Worker extends Employee{
    Worker(String name, int id) {
        this.name = name;
        this.id = id;
    }
    void getSalary(int n) {
        this.salary = 100*n; //根据工作天数来进行发工资
    }
    void ToString() {
        System.out.printf("Worker %s的工资是: %d\n",this.name,this.salary);
    }
}
