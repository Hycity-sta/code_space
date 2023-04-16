package test;

import our.common.Shape;
import our.todo.*;

public class Test {
	private static final int max = 10;

	public static void main(String[] argv) {
		//对象数组
		Circle[]  circle = new Circle[max];
		Triangle[] triangle = new Triangle[max];
		Columbia[] columbia = new Columbia[max];
		Rectangle[] rectangle = new Rectangle[max];
		Ring[] ring = new Ring[max];
		//创建对象
		circle[0] = new Circle("cir1",2,3,5);
		circle[1] = new Circle("cir2",4,3,2);
		
		triangle[0] = new Triangle("tri1", 3, 3, 3);
		triangle[1] = new Triangle("tri2", 1, 2, 3);
		
		columbia[0] = new Columbia("col1", 3, 5);
		columbia[1] = new Columbia("col2", 2, 7);
		
		rectangle[0] = new Rectangle("rec1",2,4);
		rectangle[1] = new Rectangle("rec2",6,4);
		
		ring[0] = new Ring("ring1",2,4,10,5);
		ring[1] = new Ring("ring2",6,4,8,7);
		
		//操作
		triangle[0].get_all_info();
		columbia[0].get_all_info();
		circle[0].get_all_info();
		rectangle[0].get_all_info();
		ring[0].get_all_info();
		
		circle[0].compare_position(circle[1]);
		
		Shape.get_allnum();
		Circle.get_allnum();
		Triangle.get_allnum();
		Columbia.get_allnum();
		Rectangle.get_allnum();
		Ring.get_allnum();

	}
}
