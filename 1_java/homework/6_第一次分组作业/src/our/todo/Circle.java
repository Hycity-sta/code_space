package our.todo;

import our.common.Option;
import our.common.Shape;
import java.text.DecimalFormat;

public class Circle extends Shape implements Option {
	protected Point Circle_point;
	protected double r;
	protected final double PI = 3.14;
	protected static int num = 0; // 一共有多少个圆
	protected DecimalFormat myFormat = new DecimalFormat("#.00");

	public Circle() {
		this.name = "空";
		this.r = 0;
		num++;
		this.mynum = num;
		allnum++;
	}

	public Circle(String name, double x, double y, double r) {
		this.name = name;
		this.Circle_point = new Point(x, y);
		this.r = r;
		num++;
		this.mynum = num;
		allnum++;
	}

	public Circle(String name, int x, int y, double r) {
		this.name = name;
		this.Circle_point = new Point(x, y);
		this.r = r;
		num++;
		this.mynum = num;
		allnum++;
	}

	public double find_area() {
		this.area = PI * r * r;
		return this.area;
	}

	public double find_circumference() {
		this.circumference = 2 * r * PI;
		return this.circumference;
	}

	public void get_all_info() {
		String str1 = myFormat.format(this.find_area());
		String str2 = myFormat.format(this.find_circumference());
		System.out.println("Circle " + this.name + "的半径是:" + this.r + ", 周长是:" + str2 + ", 面积是:" + str1);
		System.out.print(", 这是第" + this.mynum + "个圆\n");
		this.Circle_point.p_point();
	}

	public void compare_position(Circle obj) {
		double a = this.Circle_point.x - obj.Circle_point.x;
		double b = this.Circle_point.y - obj.Circle_point.y;
		a = a * a;
		b = b * b;
		double c = Math.sqrt(a) + Math.sqrt(b); // 求两个圆的圆心之间的距离
		double temp1, temp2;// 1是长的,2是短的
		if (this.r < obj.r) {
			temp1 = obj.r;
			temp2 = this.r;
		} else {
			temp1 = this.r;
			temp2 = obj.r;
		}
		System.out.printf("圆:" + this.name + "与" + obj.name + ", ");
		if (c > (temp1 + temp2))
			System.out.println("这两个圆是外离的关系\n");
		else if (c == (temp1 + temp2))
			System.out.println("这两个圆是外切的关系\n");
		else if ((temp1 - temp2) < c && c < (temp2 + temp1))
			System.out.println("这两个圆是相交的关系\n");
		else if (c == (temp1 - temp2))
			System.out.println("这两个圆是内切的关系\n");
		else if (c < (temp1 - temp2))
			System.out.println("这两个圆是内含的关系\n");
		else
			System.out.println("error");
	}

	public static void get_allnum() {
		System.out.println("现在一共有" + num + "个圆");
	}
}
