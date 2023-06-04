package MyThread;

class ticket implements Runnable{
	private   int count=30;
	@Override
	public  void run() {
		// TODO Auto-generated method stub
		while (count>0){
			synchronized (this) {
				if(count>0){
					try{
						Thread.sleep(100);
					}catch(InterruptedException ie){}
					System.out.println(Thread.currentThread().getName()+"正在销售第 "+count+" 张票");
					count--;	
				}
				else {
					System.out.println("票卖完") ;
				}
			}
		}
		
	}
	
}

public class TicketTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ticket t =  new ticket();
		
		new Thread(t,"窗口1 ").start();
		new Thread(t,"窗口2 ").start();
		new Thread(t,"窗口3 ").start();
	}

}
