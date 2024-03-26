class AlphaThread implements Runnable {
    Thread t;

    AlphaThread() {
        t = new Thread(this, "Alpha");
        t.start();
    }

    public void run() {
        char x = 65;
        try {
            for (int i = 0; i < 26; i++) {
                System.out.println(x);
                Thread.sleep(1000);
                x++;
            }
        } catch (InterruptedException e) {
            System.out.println("Alpha thread interrupted.");
        }
    }
}

class NumberThread implements Runnable {
    Thread t;

    NumberThread() {
        t = new Thread(this, "Number");
        t.start();
    }

    public void run() {
        try {
            for (int i = 1; i < 27; i++) {
                System.out.println(i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Number Thread Interrupted");
        }
    }
}

public class Exercise {
    public static void main(String[] args) {
        new AlphaThread();
        new NumberThread();
    }
}
