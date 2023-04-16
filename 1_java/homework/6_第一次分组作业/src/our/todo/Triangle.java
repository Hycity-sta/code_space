package our.todo;

import our.common.*;
import java.text.DecimalFormat;

public class Triangle extends Shape implements Option {// 三角形
	protected double Side_length[] = new double[3];// 边长
	protected boolean Whether;// 是否
	protected static int num = 0;// 这个图形有多少个
	protected DecimalFormat myformat = new DecimalFormat("#.00");

	public Triangle(String name, double a, double b, double c) {
		this.name = name;
		this.Side_length[0] = a;
		this.Side_length[1] = b;
		this.Side_length[2] = c;
		if ((a + b > c && a + c > b && b + c > a)
				&& (a - b < c && a - c < b && b - c < a && b - a < c && c - b < a && c - a < b)) {
			Whether = true;
			num++;
			allnum++;
			this.mynum = num;
		} else {
			System.out.println("不符合三角形的三边规则");
			Whether = false;
		}

	}

	public double find_area() {// 求面积
		if (Whether) {
			double p = (this.find_circumference()) / 2;
			this.area = Math
					.sqrt(p * (p - this.Side_length[0]) * (p - this.Side_length[1]) * (p - this.Side_length[2]));
			return (this.area);
		} else {
			System.out.println("不符合三角形的三边规则,没有面积");
			return 0;
		}
	}

	public double find_circumference() {
		if (Whether) {
			this.circumference = this.Side_length[0] + this.Side_length[1] + this.Side_length[2];
			return this.circumference;
		} else {
			System.out.println("不符合三角形的三边规则,没有周长");
			return 0;
		}
	}

	public void get_all_info() {
		String str;
		if (Whether)
			str = String.format("Triangle %s 的三边长分别是:%s,%s,%s, 面积是:%s 周长是:%s 这是第%d个三角形", this.name,
					myformat.format(this.Side_length[0]), myformat.format(this.Side_length[1]),
					myformat.format(this.Side_length[2]), myformat.format(this.find_area()),
					myformat.format(this.find_circumference()), this.mynum);
		else
			str = ("该三角形不存在");
		System.out.println(str);
	}

	public static void get_allnum() {
		System.out.println("现在一共有" + num + "个三角形");
	}
}
