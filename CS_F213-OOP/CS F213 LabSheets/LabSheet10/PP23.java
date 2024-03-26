class Printer {
    synchronized public void print(String text){
        try{
            System.out.print("[");
            System.out.print(text);
            Thread.sleep(1000);
        }catch(InterruptedException e){
            System.out.println("::> Error Occured");
        }
        System.out.println("]");
    }
}

class ThreadPrinter implements Runnable{
    Printer p;
    String msg;
    Thread t;

    ThreadPrinter(Printer printer, String s){
        msg = s;
        p = printer;
        t = new Thread(this);
    }

    public void run(){
        p.print(msg);
    }
}

public class PP23 {
    public static void main(String[] args) {
        Printer printer = new Printer();
        ThreadPrinter threadPrinter1 = new ThreadPrinter(printer, "Hello");
        ThreadPrinter threadPrinter2 = new ThreadPrinter(printer, "Synchronized");
        ThreadPrinter threadPrinter3 = new ThreadPrinter(printer, "World");

        threadPrinter1.t.start();
        threadPrinter2.t.start();
        threadPrinter3.t.start();

        try{
            threadPrinter1.t.join();
            threadPrinter2.t.join();
            threadPrinter3.t.join();
        }catch(InterruptedException e){
            System.out.println("::> Error Occured");
        }
    }
}