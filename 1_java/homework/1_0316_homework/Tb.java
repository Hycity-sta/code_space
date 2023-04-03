//生成随机的字符串
//然后输出里面每一个字符出现的次数
import java.util.*;
public class Tb {
	//用来判断有多少个字符的函数
	public static int count(String str,String s){
        int c = 0;
        char ch = s.charAt(0);
        for(int i=0;i<str.length();i++){
            if(ch == str.charAt(i) ) {
                c++;
            }
        }
        return c;
    }
	// 用来生成指定长度随机字符串的函数
	public static String getRandomString(int length){
		String str="abcdefghijklmnopqrstuvwxyz";
		Random random=new Random();
		StringBuffer sb=new StringBuffer();
		for(int i=0;i<length;i++){
			int number=random.nextInt(26);
			sb.append(str.charAt(number));
		}
		return sb.toString();
	}

    public static void main(String[] args){
		int n = 4;
		String str = getRandomString(n);
		System.out.println("现在字符串是:"+str);

		char in='a';
		String in_a = String.format("%c",in);
		for (int i=0;i<26;i++) {
			if (count(str,in_a) != 0) {
				System.out.println(in_a+" have "+count(str,in_a));
			}
			in++;
			in_a = String.format("%c",in);
		}
    }
}
