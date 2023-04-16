package our.common;

public interface Option {
	double find_area(); // 求面积

	double find_circumference(); // 求周长

	void get_all_info(); // 获取所在当前图形的所有信息, 包括抽象类中的所有属性还有面积和周长, 以及特有的东西, 例如坐标, 个数等等
}
