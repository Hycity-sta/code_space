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
					System.out.println(Thread.currentThread().getName()+"�������۵� "+count+" ��Ʊ");
					count--;	
				}
				else {
					System.out.println("Ʊ����") ;
				}
			}
		}
		
	}
	
}

public class TicketTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ticket t =  new ticket();
		
		new Thread(t,"����1 ").start();
		new Thread(t,"����2 ").start();
		new Thread(t,"����3 ").start();
	}

}
