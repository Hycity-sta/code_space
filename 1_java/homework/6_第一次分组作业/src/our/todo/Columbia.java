package our.todo;

import our.common.*;
import java.text.DecimalFormat;

public class Columbia extends Shape implements Option {
	protected double h;
	protected double r;
	protected static int num; // 用于统计圆柱的总数
	protected static final double PI = 3.14;
	protected DecimalFormat myformat = new DecimalFormat("#.00");

	public Columbia(String name, double h, double r) {
		this.name = name;
		this.h = h;
		this.r = r;
		num++;
		this.mynum = num;
		allnum++;
	}

	// 求圆柱的表面积
	public double find_area() {
		this.area = 2 * PI * r * r + 2 * PI * r * h;
		return this.area;
	}

	// 求圆柱的周长
	public double find_circumference() {
		this.circumference = 2 * r * r * PI;
		return this.circumference;
	}

	public void get_all_info() {
		System.out.printf("\nColumbia " + this.name + "的面积是" + myformat.format(this.find_area()) + ", 周长是"
				+ myformat.format(find_circumference()));
		System.out.println(",这是第" + this.mynum + "个Columbia \n");
	}

	public static void get_allnum() {
		System.out.println("现在一共有" + num + "个圆柱");
	}
}
