class NewThread implements Runnable {
	Thread t;
	
	NewThread(){
		t = new Thread(this, "Demo Thread");
		System.out.println(" Child Thread: " + t);
		t.start();	
	}
	
	public void run(){
		try {
			for(int i=10; i>0; i--){
				System.out.println(" Child -> " + i);
				Thread.sleep(500);
			}
		}catch(InterruptedException ie){
			System.out.println("Child interrupted");
		}
		System.out.println("Exiting Child");
	}
}

class NewThreadExtends extends Thread {
	NewThreadExtends(String x){
		super(x);
		System.out.println(" Child Thread: " + this);
		start();
	}
	
	public void run(){
		try {
			for(int i=10; i>0; i--){
				System.out.println(" Child -> " + i);
				Thread.sleep(500);
			}
		}catch(InterruptedException ie){
			System.out.println("Child interrupted");
		}
		System.out.println("Exiting Child");
	}	
}

class CurrentThreadDemo {
	public static void main(String args[]){
		NewThreadExtends nte = new NewThreadExtends("kik");
		NewThreadExtends nte2 = new NewThreadExtends("kik2");
		NewThreadExtends nte3 = new NewThreadExtends("kik3");
		Thread t = Thread.currentThread();
	
		
		t.setPriority(7);
		System.out.println("Main Thread: " + t);
		
		try {
		nte.join();
		nte2.join();
		nte3.join();
			for(int i=5; i>=0; i--){
				System.out.println(i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException ie){
			System.out.println("Main interrupted");
		}
	}
}
