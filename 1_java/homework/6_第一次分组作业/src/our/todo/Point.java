package our.todo;

public class Point {
	protected double x;
	protected double y;

	// 处理输入整数的情况
	public Point(int x, int y) {
		this.x = (double) x;
		this.y = (double) y;
	}

	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public void p_point() {
		System.out.print("x坐标是:" + this.x);
		System.out.println(", y坐标是:" + this.y + "\n");
	}
}
