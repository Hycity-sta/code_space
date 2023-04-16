package our.todo;

import our.common.*;
import java.text.DecimalFormat;

public class Rectangle extends Shape implements Option {

	protected double length;
	protected double wide;
	protected static int num;
	protected DecimalFormat myformat = new DecimalFormat("#.00");

	public Rectangle(String name, double length, double wide) {
		this.name = name;
		this.length = length;
		this.wide = wide;
		num++;// 矩形所有的数量+1
		this.mynum = num;// 这是当前矩形的编号
		allnum++;// 这是让所有图形加一
	}

	// 求矩形的面积
	public double find_area() {
		this.area = length * wide;
		return this.area;
	}

	// 求矩形的周长
	public double find_circumference() {
		this.circumference = 2 * (length + wide);
		return this.circumference;
	}

	public void get_all_info() {
		System.out.printf("Rectangle " + this.name + "的面积是" + myformat.format(this.find_area()) + ",周长是"
				+ myformat.format(find_circumference()));
		System.out.println(",这是第" + this.mynum + "个rectangle\n");
	}

	public static void get_allnum() {
		System.out.println("现在一共有" + num + "个矩形");
	}

}
