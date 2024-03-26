import java.io.FileOutputStream;
import java.io.IOException;

public class FileHandling {
    public static void main(String[] args) {
        String x = "Hello World!!";
        byte buf[] = x.getBytes();

        FileOutputStream f1 = null;
        FileOutputStream f2 = null;
        FileOutputStream f3 = null;
        
        try{
            f1 = new FileOutputStream("file1.txt");
            f2 = new FileOutputStream("file2.txt");
            f3 = new FileOutputStream("file3.txt");

            //Writing using one byte
            for(int i=0; i<buf.length; i++) f1.write(buf[i]);

            //Writing using full buffer
            f2.write(buf);

            //Writing using offset
            f3.write(buf, buf.length-5, 4);

          }catch(IOException e){
            System.out.println("Error Occured");
        } finally {
            try {
                if (f1 != null) f1.close();
            }catch (IOException e){
                System.out.println("Couldn't Close File 1");
            }

            try {
                if (f2 != null) f2.close();
            }catch (IOException e){
                System.out.println("Couldn't Close File 2");
            }

            try {
                if (f3 != null) f3.close();
            }catch (IOException e){
                System.out.println("Couldn't Close File 3");
            }
        }
    }
}
