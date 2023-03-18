import java.util.*;
public class test {
    public static void main(String[] argv) {
        son one = new son(10,11);
        System.out.println(one.num);
    }
}

class father {
    int num;
    father(int num) {
        this.num = num;
    }
}

class son extends father {
    int age;
    son (int age,int num) {
        super(num); 
        this.num = num;
        this.age = age;
    }
}
