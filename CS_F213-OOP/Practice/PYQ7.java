import java.io.*;

public class PYQ7 {
    public static void main(String[] args) {
        try {
            DataInputStream dis = new DataInputStream(new FileInputStream("data.txt"));
            try {
                int x = (int) dis.readInt();
                System.out.println(x);
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                try {
                    if (dis != null)
                        dis.close();
                } catch (IOException e) {
                    System.out.println("Error");
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found");
        }
    }
}
