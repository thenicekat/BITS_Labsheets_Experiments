class GrandChildThread implements Runnable {
    Thread t;
    int length;

    GrandChildThread(int len) {
        t = new Thread(this);
        t.setName("Grand Child Thread");

        length = len;
        t.start();
    }

    public void run() {
        try {
            System.out.println("Binary: " + Integer.toBinaryString(length));
            System.out.println("Octal: " + Integer.toOctalString(length));
            Thread.sleep(10000);
            System.out.println("Ending Grand Child");
        } catch (InterruptedException e) {

        }
    }
}

class ChildThread implements Runnable {
    Thread t;
    String s;

    ChildThread(String input) {
        t = new Thread(this);
        t.setName("Child Thread");
        s = input;
        t.start();
    }

    public void run() {
        try {
            boolean status = true;
            for (int i = 0; i < s.length() / 2; i++) {
                if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                    status = false;
                }
            }

            if (status) {
                System.out.println("It is a palindrome");
            } else {
                System.out.println("It is not a palindrome");
            }

            Thread.sleep(5000);

            GrandChildThread gct = new GrandChildThread(s.length());
            try{
                gct.t.join();
            }
            catch(Exception e){}

            System.out.println("Ending Child");
        } catch (InterruptedException e) {

        }
    }
}

public class PYQ9 {
    public static void main(String[] args) {
        ChildThread ct = new ChildThread("Hello");
        try{
            ct.t.join();
        }
        catch(Exception e){}

        System.out.println("Ending Main");
        System.out.println(Thread.currentThread().getPriority());
    }
}
