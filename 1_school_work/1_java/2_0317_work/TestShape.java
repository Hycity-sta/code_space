import java.util.*;
import static java.lang.System.out;

//测试类
public class TestShape {
    public static void main(String[] argv) {
		Round s1 = new Round("s1","red",3);
        Rectangle s2 = new Rectangle("s2","yellow",3,4);
        Triangle s3 = new Triangle("s3","blue",3,4,5);
        s1.getArea();
        s2.getArea();
        s3.getArea();
	}
}

//Shape类
class Shape {
	String name;
	String color;
    Shape(String name, String color){
        this.name=name;
        this.color=color;
    }
	
	public void getArea() {}
}

//圆
class Round extends Shape {
	double Round_r;
	double Round_area;

    Round(String name, String color, double Round_r) {
        super(name, color);
        this.Round_r = Round_r;
    }

	public void getArea() {
        this.Round_area = Math.PI*(Round_r*Round_r);
        out.println(String.format("%.2f",this.Round_area));
	}
}

//矩形
class Rectangle extends Shape {
	double Rectangle_x;
	double Rectangle_y;
	double Rectangle_area;

    Rectangle(String name, String color,double Rectangle_x, double Rectangle_y){
        super(name, color);
        this.Rectangle_x = Rectangle_x;
        this.Rectangle_y = Rectangle_y;
    }
	public void getArea() {
        this.Rectangle_area = Rectangle_x*Rectangle_y;
        out.println(Rectangle_area);
	}
}

//三角形
class Triangle extends Shape {
    double Triangle_a;
    double Triangle_b;
    double Triangle_c;
    double Triangle_area;

	public Triangle(String name, String color,double Triangle_a, double Triangle_b, double Triangle_c) {
        super(name, color);
        this.Triangle_a = Triangle_a;
        this.Triangle_b = Triangle_b;
        this.Triangle_c = Triangle_c;
	}

	public void getArea() {
        double p = (Triangle_a+Triangle_c+Triangle_b)/2;
        this.Triangle_area = (Math.sqrt(p*(p- Triangle_a)*(p- Triangle_b)*(p- Triangle_c)));
        out.println(this.Triangle_area);
	}
}

