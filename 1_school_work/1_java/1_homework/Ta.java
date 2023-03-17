package my;
import static java.lang.System.out;
import java.util.Arrays;

public class Ta {
	public static void main(String[] argv) {
		Round one = new Round(2,2,2);
		one.get_info();
		one.set_info(4,1,1);
		one.get_info();
		one.return_S();
		one.return_C();
		
		out.println("");

		Ci two = new Ci(3,9,1,1);
		two.get_info();
		two.set_info(4,16,2,2);
		two.return_C();
		two.return_S();

		out.println("");

		Round tree = new Round(3,4,5);
		tree.get_info();
		tree.return_S();
		tree.return_C();
	}
}
// 圆的类
class Round {
	int radins;
	final double PI = 3.14;
	int[] center = new int[2];


	Round(int radins, int center_x, int center_y) {
		this.radins = radins;
		this.center[0] = center_x;
		this.center[1] = center_y;
	}


	public void get_info() {
		out.println("这个圆的半径是:"+this.radins);
		out.println("这个圆的圆心在:"+Arrays.toString(this.center));
	}


	public void set_info(int s1, int s2, int s3) {
		this.radins = s1;
		this.center[0] = s2;
		this.center[1]= s3;
		this.get_info();
	}


	public void return_S() {
		double sq;
		sq = this.radins*radins*PI;
		out.println("这个圆的面积是:"+String.format("%.2f",sq));
	}


	public void return_C() {
		double cc;
		cc = 2*radins*PI;
		out.println("这个圆环周长是:"+String.format("%.2f",cc));
	}
}


class Ci {
	int innerRadius;
	int outerRadius;
	int[] center = new int[2];
	final double PI = 3.14;


	Ci(int inner, int outer, int center_x, int center_y) {
		this.innerRadius = inner;
		this.outerRadius = outer;
		this.center[0] = center_x;
		this.center[1] = center_y;
	}


	void get_info() {
		out.println("这个圆环的内半径是:"+this.innerRadius);
		out.println("这个圆环的内半径是:"+this.outerRadius);
		out.println("这个圆环的圆心在:"+Arrays.toString(this.center));
	}


	void set_info(int c1, int c2, int c3, int c4) {
		this.innerRadius = c1;
		this.outerRadius = c2;
		this.center[0] = c3;
		this.center[1] = c4;
		this.get_info();
	}


	void return_S() {
		double ci_S;
		ci_S = PI * ((this.outerRadius*this.outerRadius)-(this.innerRadius*this.innerRadius));
		out.println("这个圆环的周长是:"+String.format("%.2f",ci_S));
	}


	void return_C() {
		double ci_C;
		ci_C = 2*PI*(this.innerRadius+this.outerRadius);
		out.println("这个圆环的周长是:"+String.format("%.2f",ci_C));
	}
}
