class ChildThread implements Runnable {
    Thread t;

    ChildThread(String name) {
        t = new Thread(this, name);
        t.start();
    }

    @Override
    public void run() {
        System.out.println("Current Priority: " + t.getPriority());
        if (t.getPriority() + 2 < Thread.MAX_PRIORITY) {
            t.setPriority(t.getPriority() + 2);
        }
        System.out.println("Current Priority: " + t.getPriority());
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
        }
        System.out.println("Child Ended");
    }    
}

public class Threads {
    public static void main(String[] args) {
        Thread curr = Thread.currentThread();
        curr.setName("SystemThread");

        ChildThread ct = new ChildThread("Pedo");

        while(ct.t.isAlive()){}
        
        System.out.println("Main Ended");
    }
}
