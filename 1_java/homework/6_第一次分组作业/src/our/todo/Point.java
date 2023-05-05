package our.todo;

public class Point {
	protected double x;
	protected double y;

	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public void p_point() {
		System.out.print("x坐标是:" + this.x);
		System.out.println(", y坐标是:" + this.y + "\n");
	}
}
