import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PYQ11 {
    public static void main(String[] args) {
        try {
            File f = new File("abc.txt");
            BufferedReader br = new BufferedReader(new FileReader(f));

            System.out.println(f.isDirectory());
            System.out.println(f.lastModified());

            int i = 0;
            String temp[] = new String[100];
            String tem;
            while ((tem = br.readLine()) != null) {
                if (i % 2 == 0) {
                    temp[i / 2] = tem;
                }
                i++;
            }
            br.close();

            BufferedWriter bw = new BufferedWriter(new FileWriter(f));
            for (String tempB : temp) {
                if (tempB != null){
                    System.out.println(tempB);
                    bw.write(tempB + "\n");
                }
            }
            // bw.flush();
            bw.close();

        } catch (FileNotFoundException e) {

        } catch (IOException e) {

        }
    }
}
