package our.common;

public abstract class Shape {
	protected static int allnum;// 所有的图形一共有几个
	protected int mynum;// 当前图像是第几个
	protected String name;// 名字
	protected double area;// 面积
	protected double circumference;// 周长

	public static void get_allnum() {
		System.out.println("现在一共有" + allnum + "个图形");
	}

}
