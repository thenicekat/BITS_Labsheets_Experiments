import java.io.*;

class ReaderStream implements Runnable {
    Thread r;
    String name;
    File f;

    // static boolean isPrinting = false;

    ReaderStream(String fileName, File fInput) {
        r = new Thread(this, "Reader");
        name = fileName;
        f = fInput;

        r.start();
    }

    synchronized void print() {
    
        try {
            BufferedInputStream bis = new BufferedInputStream(new FileInputStream(f));
            int c;
            try {
                // while (isPrinting) {
                //     wait();
                // }

                // isPrinting = true;

                while ((c = bis.read()) != -1) {
                    try {
                        System.out.print((char) c);
                        if ((char) c == '\n') {
                            Thread.sleep(300);
                        }
                    } catch (InterruptedException e) {
                    }
                }

                // isPrinting = false;
                // notifyAll();
            } catch (Exception e) {
            }
            bis.close();
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found");
        } catch (IOException e) {
        }
    }

    public void run() {
        System.out.println("Thread Started");        
    }
}

public class PYQ12 {
    public static void main(String[] args) {
        File f = new File(args[0]);
        ReaderStream rs1 = new ReaderStream(args[0], f);
        ReaderStream rs2 = new ReaderStream(args[1], f);
        rs1.print();
        rs2.print();

        while (rs1.r.isAlive() || rs2.r.isAlive()) {
        }
        System.out.println("GoodBye");
    }
}
