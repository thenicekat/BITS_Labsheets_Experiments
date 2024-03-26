import java.io.*;

public class CopyFile {
    public static void main(String[] args) {
        File f1 = new File(args[0]);
        File f2 = new File(args[1]);

        try {
            FileInputStream fis = new FileInputStream(f1);
            FileOutputStream fos = new FileOutputStream(f2);

            int temp = 0;
            try {
                while ((temp = fis.read()) != -1) {
                    System.out.println("::>" + (char) temp);
                    fos.write(temp);
                }

                System.out.println("Copy Successful");
            } catch (IOException e) {
            }

        } catch (FileNotFoundException e) {

        }
    }
}
