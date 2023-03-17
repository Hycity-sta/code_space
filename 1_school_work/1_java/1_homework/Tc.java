import java.util.*;
import static java.lang.System.out;
public class Tc {
	public static void main(String[] args) {
		Scanner mystr = new Scanner(System.in);
		String str;
		out.print("如果路径中包含中文,可能会出现乱码问题\n");
		out.print("输入包含文件的路径:");
		str = mystr.nextLine();//用户输入
		
		//将字符串编程字符数组
		char[] array = new char[1000];
		for (int i = 0; i < str.length(); i++) {
			// 使用charAt方法，逐个读取字符串并存入到数组中
			array[i] = str.charAt(i);
		}

		int n1=str.length();//数组的长度
		
		//寻找最后一个斜杆出现的地方
		for(int b=str.length();array[b]!='\\';b--){
			n1--;
		}

		out.print("文件名是:");
		//n1+1是因为经过测试,不然会多输出一个斜杆
		for(int c=n1+1;c<str.length();c++) {
			out.print(array[c]);
		}

		out.println("");
		out.print("路径是:");
		for (int d=0;d<n1;d++) {
			out.print(array[d]);
		}
	}
}
