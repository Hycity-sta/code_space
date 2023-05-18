import java.util.*;
import java.text.*;
//要模拟一个银行来着,但是失败了,因为不会设计
public class Test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BANK bank = null;
        try {
            System.out.println("请输入你的14位账户");
            String in_id = input.nextLine();
            DealMethod.isNumber(in_id);
            DealMethod.isLength(in_id,14);

            System.out.println("请输入你的10位密码");
            String in_key = input.nextLine();
            DealMethod.isNumber(in_key);
            DealMethod.isLength(in_key,10);

            bank = new BANK(in_id, in_key);
        } catch (Exception e) {
            System.out.println(e.toString());
        }

        System.out.println("你好,请问你需要做什么?");
        while (true) {
            try {
                System.out.println("如果要存款请输入1,如果要取款请输入2,如果要退出请输入0");
                String str = input.nextLine();
                DealMethod.isNumber(str);
                DealMethod.isLength(str,1);

                if (Integer.parseInt(str) == 1) {
                    bank.setMoney(); //存钱
                } else if (Integer.parseInt(str) == 2) {
                    bank.getMoney(); //取钱
                } else if (Integer.parseInt(str) == 0) {
                    System.out.println("正在退出...");
                    input.close();
                    break;
                } else {
                    throw new Exception("输入了错误的选项!");
                }
            } catch (BankInputException e) {
                System.out.println(e.getMessage());
                System.out.println("请重新输入!\n-----------------------------------------\n");
                continue;
            } catch (BankException e) {
                System.out.println(e.getMessage());
                System.out.println("请重新输入!\n-----------------------------------------\n");
                continue;
            } catch (Exception e) {
                System.out.println(e.toString());
                System.out.println("请重新输入!\n-----------------------------------------\n");
                continue;
            }
        } 
    }
}



//银行
class BANK {
    private String id; //账户
    private String key; //密码
    private double money; //钱
    DecimalFormat myFormat = new DecimalFormat("#.00");

    public BANK(String id, String key) {
        this.id= id;
        this.key = key;
    }

    //存钱操作
    public void setMoney() throws BankInputException{
        Scanner input_x = new Scanner(System.in);
        System.out.println("请问你需要存多少钱?注意:只能保留两位小数");
        try {
            String str = input_x.nextLine();
            double m = Double.parseDouble(str);
            str = myFormat.format(m); //保留两位小数
            
            this.money = Double.parseDouble(str);
            System.out.println("存钱成功!");
            input_x.close();
        } catch (NumberFormatException e) {
            throw new BankInputException("输入了错误的数据");
        }
    }

    //取款操作
    public void getMoney() throws BankInputException, BankException {
        Scanner input_x = new Scanner(System.in);
        System.out.println("你现在的账户的余额有:"+this.money);
        System.out.println("请问你需要取多少钱?注意:输入的数字最多只能保留两位小数");
        try {
            String str = input_x.nextLine();
            double m = Double.parseDouble(str);
            str = myFormat.format(m);

            Double geter = Double.parseDouble(str);
            DealMethod.isCorrect(geter,this.money);
            input_x.close();
        } catch (NumberFormatException e) {
            throw new BankInputException("输入了错误的数据");
        }
        
    }
}

class DealMethod {
    //判断操作
    public static void isCorrect(double get, double set) throws BankException {
        if (get > set) throw new BankException();
    }

    //判断字符串是不是纯数字
    public static void isNumber(String str) throws Exception {
        if (str.matches("\\d+")!=true) throw new Exception("输入的不是纯数字!");
    }

    //判断字符串长度
    public static void isLength(String str, int len) throws Exception{
        if (str.length() != len) throw new Exception("输入的不是"+len+"位数字!");
    }
}

class BankException extends Exception {
    public String toString() {
        return "操作错误,你的取款额大于存款额!";
    }
    public void printString() {
        System.out.println(this.toString());
    }
}


class BankInputException extends Exception {
    public BankInputException(String message) {
        super(message);
    }
}
