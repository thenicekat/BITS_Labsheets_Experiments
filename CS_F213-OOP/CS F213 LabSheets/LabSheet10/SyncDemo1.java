class Box {
	synchronized void show(){
		System.out.print("[+++");
		try {Thread.sleep(1000);}
		catch(InterruptedException ie){}
		System.out.print("]");
	}
}

class MyThread extends Thread {
	Box b;
	
	MyThread(Box binput){
		b = binput;
		start();
	}
	
	public void run(){
		// synchronized(b){
			b.show();
		// }
	}
}

class SyncDemo1 {
	public static void main(String args[]){
		Box b = new Box();
		MyThread mt1 = new MyThread(b);
		MyThread mt2 = new MyThread(b);
		MyThread mt3 = new MyThread(b);

	}
}
