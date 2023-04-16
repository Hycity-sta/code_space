package our.todo;

import our.common.*;
import java.text.DecimalFormat;

public class Ring extends Shape implements Option {
	protected double outerR, interR;
	Point p;
	protected static int num;
	protected static double pi = 3.14;
	protected DecimalFormat myFormat = new DecimalFormat("#.00");

	public Ring(String name, int x, int y, double outR, double interR) {
		super.name = name;
		this.p = new Point(x, y);
		this.outerR = outR;
		this.interR = interR;
		num++;
		this.mynum = num;
		allnum++;
	}

	public Ring(String name, double x, double y, double outR, double interR) {
		super.name = name;
		this.p = new Point(x, y);
		this.outerR = outR;
		this.interR = interR;
		num++;
		this.mynum = num;
		allnum++;
	}

	public double find_area() {
		this.area = (this.outerR - this.interR) * pi * pi;
		return this.area;
	}

	public double find_circumference() {
		this.circumference = (this.outerR - this.interR) * 2 * pi;
		return this.circumference;
	}

	public void get_all_info() {
		String str1, str2;
		str1 = myFormat.format(this.find_area());
		str2 = myFormat.format(this.find_circumference());
		System.out.println("Ring " + this.name + "的圆心：(" + p.x + "," + p.y + "),外半径：" + this.outerR + "，内半径："
				+ this.interR + "，面积：" + str1 + "，周长：" + str2 + "\n");
	}

	public static void get_allnum() {
		System.out.println("现在一共有" + num + "个圆环");
	}
}