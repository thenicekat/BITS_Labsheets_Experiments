class AlphaThread implements Runnable{
	Thread t;
	
	AlphaThread(){
		t = new Thread(this, "Alphabet Thread");
		t.start();
	}
	
	synchronized public void run(){
		try {
			for(char i='a'; i<'z'; i++){
				System.out.println(" Alphabets -> " + i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException ie){
			System.out.println("Alphabets interrupted");
		}
		System.out.println("Exiting Alphabets");
	}
}

class NumberThread implements Runnable{
	Thread t;
	
	NumberThread(){
		t = new Thread(this, "Number Thread");
		t.start();
	}
	
	public void run(){
		try {
			for(int i=1; i<26; i++){
				System.out.println(" Number -> " + i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException ie){
			System.out.println("Number interrupted");
		}
		System.out.println("Exiting Number");
	}
}

public class AlphaNumber {
	public static void main(String args[]){
		System.out.println("Starting Threads");
		AlphaThread at = new AlphaThread();
		NumberThread nt = new NumberThread();
	}
}
