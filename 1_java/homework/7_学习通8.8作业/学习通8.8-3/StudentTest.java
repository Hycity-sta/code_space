import java.util.*;

public class StudentTest {
	public static void main(String[] args) {
		double in_regularGrade;
		double in_experimentGrade;
		double in_finalGrade;

		Scanner input = new Scanner(System.in);
        Student student_a = null;

        System.out.println("输入学生的名字");
        String in_name = input.next();

        //输入学生的成绩并监测是否是double类型的数据
        while (true) {
            try {
                System.out.println("输入学生的平时成绩");
                String str = input.next();
                in_regularGrade = Double.parseDouble(str);

                System.out.println("输入学生的实验成绩");
                str = input.next();
                in_experimentGrade = Double.parseDouble(str);

                System.out.println("输入学生的期末成绩");
                str = input.next();
                in_finalGrade = Double.parseDouble(str);
                //监控输入是否合理
                if (in_experimentGrade < 0 || in_experimentGrade > 100)
                    throw new NoCorrectNumException();
                if (in_finalGrade < 0 || in_finalGrade > 100)
                    throw new NoCorrectNumException();
                if (in_regularGrade < 0 || in_regularGrade > 100)
                    throw new NoCorrectNumException();

                student_a = new Student(in_name, in_regularGrade, in_experimentGrade, in_finalGrade);
                input.close();
                break;
            } catch (NumberFormatException e) {
                System.out.println("\n输入了不是Double类型的数据");
                System.out.println("请重新输入!");
                System.out.println("-----------------------------------------------\n");
            } catch (NoCorrectNumException e) {
                System.out.println(e.toString());
            }
        }

		//监控学生的成绩是否合格
		try {
			if (student_a.getScore() < 60)
				throw new FailException(student_a.getName());
			else
                System.out.println("这个学生本学期课程通过了!");
		} catch (FailException e) {
			System.out.println(e.toString());
		}
	}
}


//学生类
class Student {
    private String name;
	private double regularGrade; //平时成绩
	private double experimentGrade; //实验成绩
	private double finalGrade; //期末成绩

	public Student(String name, double regularGrade, double experimentGrade, double finalGrade) {
        this.name = name;
		this.regularGrade = regularGrade;
		this.experimentGrade = experimentGrade;
		this.finalGrade = finalGrade;
	}

	public double getScore() {
		double score = this.regularGrade * 0.2 + this.experimentGrade * 0.2 + this.finalGrade * 0.6;
		return score;
	}

    public String getName() {
        return this.name;
    }
}

//课程未通过的异常
class FailException extends Exception {
	String message;

	public FailException(String message) {
		this.message = message;
	}

	public String toString() {
		return message + "本门课程未通过！";
	}
}

//输入的数据不合法的异常
class NoCorrectNumException extends Exception {
	public String toString() {
		return "\n输入的数据是不合理的数据,请重新输入\n---------------------------------\n";
	}
}
